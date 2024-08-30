#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    my_layout = new QVBoxLayout;
    my_button = new QPushButton("Push me!", this);
    my_layout_horisontal = new QHBoxLayout;
    my_edit = new QLineEdit(this);
    my_label = new QLabel("Name", this);

    setLayout(my_layout);
    my_layout->addItem(my_layout_horisontal);

    my_layout_horisontal->addWidget(my_label);
    my_layout_horisontal->addWidget(my_edit);

    my_layout->addWidget(my_button);

    connect(my_button, &QPushButton::clicked, this, & Widget::close);
}

Widget::~Widget() {}
