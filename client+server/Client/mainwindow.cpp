#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow),nextblockSize(0)
{
    ui->setupUi(this);
    Socket = new QTcpSocket(this);
    connect(Socket, &QTcpSocket::readyRead, this, &MainWindow::ReadyToRead);
    connect(Socket, &QTcpSocket::disconnected, Socket, &QTcpSocket::deleteLater);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    Socket->connectToHost("127.0.0.1", 2323);
}

void MainWindow::SendToServer(QString str)
{
    Data.clear();
    QDataStream out(&Data,QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_5_15);
    out<< quint16(0) << QTime::currentTime()<<str;
    out.device()->seek(0);
    out << quint16(Data.size()-sizeof(quint16));
    Socket->write(Data);
    ui->lineEdit->clear();
}

void MainWindow::ReadyToRead()
{

    QDataStream in(Socket);

    in.setVersion(QDataStream::Qt_5_15);
    if (in.status() == QDataStream::Ok )
    {
        // QString str;
        // in >> str;
        // ui->textBrowser->append(str);
        for (;;)
        {
            if (nextblockSize == 0)
            {
                if (Socket->bytesAvailable()<2)
                {
                    break;
                }
                in >> nextblockSize;
            }
            if(Socket->bytesAvailable() < nextblockSize)
            {
                break;
            }
            QString str;
            QTime time;
            in >> time >> str;
            nextblockSize = 0;
            qDebug() << time <<str;
            ui->textBrowser->append(time.toString()+ " " +str);
            break;
        }
    }
    else
    {
        ui->textBrowser->append("read error");
    }
}


void MainWindow::on_pushButton_2_clicked()
{
    SendToServer(ui->lineEdit->text());
}


void MainWindow::on_lineEdit_returnPressed()
{
    SendToServer(ui->lineEdit->text());
}

