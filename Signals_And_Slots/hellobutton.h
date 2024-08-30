#ifndef HELLOBUTTON_H
#define HELLOBUTTON_H

#include <QPushButton>

class HelloButton : public QPushButton
{
    Q_OBJECT
    int m_clickedTimes;
public:
    HelloButton();

signals:
    void closethisstuf();
public slots:
    void inc_counter();
};

#endif // HELLOBUTTON_H
