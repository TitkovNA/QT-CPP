#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDataStream>
#include <QTcpSocket>
#include <QString>
#include <QTime>
#include <QDebug>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE



class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_lineEdit_returnPressed();

private:
    Ui::MainWindow *ui;

    QTcpSocket *Socket;
    QByteArray Data;
    void SendToServer(QString str);
    quint16 nextblockSize;

public slots:
    void ReadyToRead();
};
#endif // MAINWINDOW_H
