#ifndef SERVER_H
#define SERVER_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <Qvector>
#include <Qdebug>
#include <QDataStream>
#include <QString>
#include <QTime>

class server : public QTcpServer
{
    Q_OBJECT
public:
    server();
    QTcpSocket *socket;

private:

    QVector <QTcpSocket *> Sockets;
    QByteArray Data;
    void Send_To_Client(QString str);
    quint16 nextblockSize;

public slots:
    void incomingConnection(qintptr socketDescriptor);
    void ReadyToRead();
    void onClientDisconnected();
};

#endif // SERVER_H
