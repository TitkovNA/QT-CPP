#include "printthread.h"

PrintThread::PrintThread(QString prefix, int timeout) : m_prefix(prefix), m_timeot(timeout)
{

}

void PrintThread::run()
{
    int i {0};

    forever
    {
        QTest::qSleep(m_timeot);
        qDebug()<<m_prefix<<i++;
    }
}
