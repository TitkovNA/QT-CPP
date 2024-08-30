#include "hellobutton.h"
#include <QString>

HelloButton::HelloButton(): QPushButton("Hello World!"), m_clickedTimes(0)
{
    connect(this, &HelloButton::clicked, this, &HelloButton::inc_counter);
}

void HelloButton::inc_counter()
{
    m_clickedTimes++;
    QString str = QString("Hellow world %1").arg(m_clickedTimes);
    setText(str);
    if (m_clickedTimes >= 5)
        emit closethisstuf();
}
