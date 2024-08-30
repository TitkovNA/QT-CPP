#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QString>

class Widget : public QWidget
{
    Q_OBJECT

private:
    QVBoxLayout* Layout_Main;
    QGridLayout* Layout_Menu;

    QPushButton* Button_0;
    QPushButton* Button_1;
    QPushButton* Button_2;
    QPushButton* Button_3;
    QPushButton* Button_4;
    QPushButton* Button_5;
    QPushButton* Button_6;
    QPushButton* Button_7;
    QPushButton* Button_8;
    QPushButton* Button_9;
    QPushButton* Button_Eqals;
    QPushButton* Button_AC;
    QPushButton* Button_Inv;
    QPushButton* Button_Percent;
    QPushButton* Button_Dot;
    QPushButton* Button_Mul;
    QPushButton* Button_Div;
    QPushButton* Button_Plus;
    QPushButton* Button_Minus;

    QLabel*      Label_result;
    double       first_num;
public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void print_digits();
    void print_dot();
    void math_operations();
    void print_result();
    void AC_label_result();
    void other_operations();

};
#endif // WIDGET_H
