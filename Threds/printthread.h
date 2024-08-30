#ifndef PRINTTHREAD_H
#define PRINTTHREAD_H

#include <QObject>
#include <QThread>
#include <QtTest/QTest>
#include <QDebug>

class PrintThread : public QThread
{
    QString m_prefix {""};
    int     m_timeot {0};
public:
    PrintThread(QString prefix, int timeout);
protected:
    void run()        override;
};

#endif // PRINTTHREAD_H
