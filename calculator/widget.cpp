#include "widget.h"



Widget::Widget(QWidget *parent)
    : QWidget(parent) , first_num(0)

{
    Layout_Main = new QVBoxLayout;
    Layout_Menu = new QGridLayout;

    Button_0 = new QPushButton("0",this);
    Button_1 = new QPushButton("1",this);
    Button_2 = new QPushButton("2",this);
    Button_3 = new QPushButton("3",this);
    Button_4 = new QPushButton("4",this);
    Button_5 = new QPushButton("5",this);
    Button_6 = new QPushButton("6",this);
    Button_7 = new QPushButton("7",this);
    Button_8 = new QPushButton("8",this);
    Button_9 = new QPushButton("9",this);
    Button_Eqals = new QPushButton("=",this);
    Button_AC = new QPushButton("AC",this);
    Button_Inv = new QPushButton("+/-",this);
    Button_Percent = new QPushButton("%",this);
    Button_Dot = new QPushButton(".",this);
    Button_Mul = new QPushButton("*",this);
    Button_Div = new QPushButton("/",this);
    Button_Plus = new QPushButton("+",this);
    Button_Minus = new QPushButton("-",this);

    Button_Mul->setCheckable(true);
    Button_Div->setCheckable(true);
    Button_Plus->setCheckable(true);
    Button_Minus->setCheckable(true);

    Label_result = new QLabel("0",this);

    setLayout(Layout_Main);

    Layout_Main->addWidget(Label_result);
    Layout_Main->addLayout(Layout_Menu);

    Layout_Menu->addWidget(Button_AC, 0, 0);
    Layout_Menu->addWidget(Button_Inv, 0, 1);
    Layout_Menu->addWidget(Button_Percent, 0, 2);
    Layout_Menu->addWidget(Button_Dot, 0, 3);

    Layout_Menu->addWidget(Button_7, 1, 0);
    Layout_Menu->addWidget(Button_8, 1, 1);
    Layout_Menu->addWidget(Button_9, 1, 2);
    Layout_Menu->addWidget(Button_Div, 1, 3);

    Layout_Menu->addWidget(Button_4, 2, 0);
    Layout_Menu->addWidget(Button_5, 2, 1);
    Layout_Menu->addWidget(Button_6, 2, 2);
    Layout_Menu->addWidget(Button_Mul, 2, 3);

    Layout_Menu->addWidget(Button_1, 3, 0);
    Layout_Menu->addWidget(Button_2, 3, 1);
    Layout_Menu->addWidget(Button_3, 3, 2);
    Layout_Menu->addWidget(Button_Minus, 3, 3);

    Layout_Menu->addWidget(Button_0, 4, 0, 1, 2);
    Layout_Menu->addWidget(Button_Eqals, 4, 2);
    Layout_Menu->addWidget(Button_Plus, 4, 3);

    connect(Button_0,&QPushButton::clicked,this,&Widget::print_digits);
    connect(Button_1,&QPushButton::clicked,this,&Widget::print_digits);
    connect(Button_2,&QPushButton::clicked,this,&Widget::print_digits);
    connect(Button_3,&QPushButton::clicked,this,&Widget::print_digits);
    connect(Button_4,&QPushButton::clicked,this,&Widget::print_digits);
    connect(Button_5,&QPushButton::clicked,this,&Widget::print_digits);
    connect(Button_6,&QPushButton::clicked,this,&Widget::print_digits);
    connect(Button_7,&QPushButton::clicked,this,&Widget::print_digits);
    connect(Button_8,&QPushButton::clicked,this,&Widget::print_digits);
    connect(Button_9,&QPushButton::clicked,this,&Widget::print_digits);
    connect(Button_Dot,&QPushButton::clicked,this,&Widget::print_dot);
    connect(Button_Mul,&QPushButton::clicked,this,&Widget::math_operations);
    connect(Button_Div,&QPushButton::clicked,this,&Widget::math_operations);
    connect(Button_Plus,&QPushButton::clicked,this,&Widget::math_operations);
    connect(Button_Minus,&QPushButton::clicked,this,&Widget::math_operations);
    connect(Button_Eqals,&QPushButton::clicked,this,&Widget::print_result);
    connect(Button_AC,&QPushButton::clicked,this,&Widget::AC_label_result);
    connect(Button_Percent,&QPushButton::clicked,this,&Widget::other_operations);
    connect(Button_Inv,&QPushButton::clicked,this,&Widget::other_operations);
}

Widget::~Widget() {}

void Widget::print_digits()
{
    QPushButton *clickedButton = qobject_cast<QPushButton*>(sender());
    double all_numbers {0};
    QString new_numbers;


    if (Label_result->text().contains('.') && clickedButton->text()=="0")
    {
        new_numbers = Label_result->text()+clickedButton->text();
    }
    else
    {
        all_numbers = (Label_result->text()+clickedButton->text()).toDouble();
        new_numbers = QString::number(all_numbers,'g',15);
    }
    Label_result->setText(new_numbers);

}

void Widget::print_dot()
{
    if (!(Label_result->text().contains('.')))
    {
        Label_result->setText(Label_result->text()+".");
    }
}

void Widget::math_operations()
{
    QPushButton *clickedButton = qobject_cast<QPushButton*>(sender());
    first_num = Label_result->text().toDouble();
    Label_result->setText("");
    clickedButton->setChecked(true);
}

void Widget::print_result()
{
    double res_num{0}, second_num{0};
    QString new_numbers;

    second_num = Label_result->text().toDouble();
    if (Button_Plus->isChecked())
    {
        res_num = first_num + second_num;
        new_numbers = QString::number(res_num, 'g', 15);
        Label_result->setText(new_numbers);
        Button_Plus->setChecked(false);

    }else if (Button_Minus->isChecked())
    {
        res_num = first_num - second_num;
        new_numbers = QString::number(res_num, 'g', 15);
        Label_result->setText(new_numbers);
        Button_Minus->setChecked(false);


    }else if (Button_Mul->isChecked())
    {
        res_num = first_num * second_num;
        new_numbers = QString::number(res_num, 'g', 15);
        Label_result->setText(new_numbers);
        Button_Mul->setChecked(false);

    }else if (Button_Div->isChecked())
    {
        if (second_num == 0)
        {
            Label_result->setText("Error: / 0");
            Button_Div->setChecked(false);
        }
        else
        {
            res_num = first_num / second_num;
            new_numbers = QString::number(res_num, 'g', 15);
            Label_result->setText(new_numbers);
            Button_Div->setChecked(false);
        }
    }
}

void Widget::AC_label_result()
{
    Button_Plus->setChecked(false);
    Button_Minus->setChecked(false);
    Button_Mul->setChecked(false);
    Button_Div->setChecked(false);

    Label_result->setText("0");
}

void Widget::other_operations()
{
    QPushButton *clickedButton = qobject_cast<QPushButton*>(sender());
    double all_numbers {0};
    QString new_numbers;

    if (clickedButton->text() == "+/-")
    {
        all_numbers = Label_result->text().toDouble();
        all_numbers *= -1;
        new_numbers = QString::number(all_numbers, 'g', 15);
        Label_result->setText(new_numbers);
    }
    else if (clickedButton->text() == "%")
    {
        all_numbers = Label_result->text().toDouble();
        all_numbers *= 0.01;
        new_numbers = QString::number(all_numbers, 'g', 15);
        Label_result->setText(new_numbers);
    }
}
