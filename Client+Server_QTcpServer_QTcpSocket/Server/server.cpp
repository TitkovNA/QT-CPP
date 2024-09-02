#include "server.h"

server::server() :  nextblockSize(0)
{
    if (this->listen(QHostAddress::Any,2323))
    {
        qDebug()<<"start";
    }
    else{
        qDebug()<<"error";
    }
}


void server::incomingConnection(qintptr socketDescriptor)
{
    socket = new QTcpSocket;
    socket->setSocketDescriptor(socketDescriptor);
    connect(socket, &QTcpSocket::readyRead, this, &server::ReadyToRead);
    connect(socket, &QTcpSocket::disconnected, this, &server::onClientDisconnected);

    Sockets.push_back(socket);

    qDebug()<<"client connected"<<socketDescriptor;
}

void server::ReadyToRead()
{
    socket = (QTcpSocket*)sender();
    QDataStream in(socket);

    in.setVersion(QDataStream::Qt_5_15);
    if (in.status() == QDataStream::Ok )
    {
        qDebug() << "Reading...";
        // QString str;
        // in >> str;
        // qDebug() << str;
        // Send_To_Client(str);
        for (;;)
        {
            if (nextblockSize == 0)
            {
                if (socket->bytesAvailable()<2)
                {
                    qDebug() << "data < 2 , break";
                    break;
                }
                in >> nextblockSize;
                qDebug() << "nextblocksize = "<<nextblockSize;
            }
            if(socket->bytesAvailable() < nextblockSize)
            {
                qDebug() << "data not full, beak";
                break;
            }
            QString str;
            QTime time;
            in >> time >>str;
            nextblockSize = 0;
            qDebug() <<time<< str;
            Send_To_Client(str);
            break;
        }
    }
    else
    {
        qDebug() << "Error";
    }
}

void server::onClientDisconnected()
{
    socket = (QTcpSocket*)sender();
    Sockets.erase(std::remove(Sockets.begin(), Sockets.end(), socket), Sockets.end());
    socket->deleteLater();
}


void server::Send_To_Client(QString str)
{
    Data.clear();
    QDataStream out(&Data,QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_5_15);
    out<< quint16(0)<< QTime::currentTime() << str;
    out.device()->seek(0);
    out << quint16(Data.size()-sizeof(quint16));
    for (int i = 0 ; i<Sockets.size() ;++i)
    {
        Sockets[i] -> write(Data);
    }
}
