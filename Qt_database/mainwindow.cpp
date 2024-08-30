#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , row(0)
{
    ui->setupUi(this);
    db = QSqlDatabase::addDatabase("QSQLITE");

    db.setDatabaseName("./Test_QT.db");

    if (!db.open()) {
        qDebug() << "Ошибка подключения к базе данных:";
    } else {
        qDebug() << "Соединение с QSQLITE установлено!";
    }

    query = new QSqlQuery(db);
    query->exec("CREATE TABLE Users(FirstName TEXT, Lastname TEXT, Telephone INT);");

    model = new QSqlTableModel(this, db);
    model->setTable("Users");
    model->select();
    ui->tableView->setModel(model);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_Add_clicked()
{
    model->insertRow(model->rowCount());
}


void MainWindow::on_pushButton_Delete_clicked()
{
    model->removeRow(row);
}


void MainWindow::on_tableView_clicked(const QModelIndex &index)
{
    row =index.row();
}

