#ifndef WIDGET_H
#define WIDGET_H

#include <QDebug>
#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QLineEdit>
#include <QListView>

#include "datamodel.h"

class Widget : public QWidget
{
    Q_OBJECT

    QListView *my_List;
    QLineEdit *my_Edit;

    QPushButton *btn_add;
    QPushButton *btn_delete;

    DataModel *my_model;

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
public slots:
    void insert_value_from_line();
    void delete_value_from_line();
};
#endif // WIDGET_H
