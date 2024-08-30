#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{

    my_model = new DataModel(this);
    my_List = new QListView(this);
    my_Edit = new QLineEdit("New value", this);
    my_List->setModel(my_model);
    btn_add = new QPushButton("Add value", this);
    btn_delete = new QPushButton("Delete value", this);



    setLayout(new QVBoxLayout);
    QHBoxLayout *my_HLayout = new QHBoxLayout;
    my_HLayout->addWidget(my_Edit);
    my_HLayout->addWidget(btn_add);
    my_HLayout->addWidget(btn_delete);

    layout()->addWidget(my_List);
    layout()->addItem(my_HLayout);

    connect(btn_add, &QPushButton::clicked,this,&Widget::insert_value_from_line);
    connect(btn_delete, &QPushButton::clicked,this,&Widget::delete_value_from_line);
}

Widget::~Widget() {}

void Widget::insert_value_from_line()
{
    my_model->add_value(my_Edit->text());
}

void Widget::delete_value_from_line()
{

    QModelIndex index = my_List->currentIndex();
    my_List->setCurrentIndex(QModelIndex());

    if (index.isValid())
    {
        int row = index.row();
        my_model->delete_value(row);
    }
    else
    {
        qDebug() << "No element.";
    }
}

