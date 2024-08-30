#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>

class Widget : public QWidget
{
    Q_OBJECT

    QVBoxLayout *my_layout;
    QHBoxLayout *my_layout_horisontal;
    QPushButton *my_button;
    QLineEdit   *my_edit;
    QLabel      *my_label;

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
};
#endif // WIDGET_H
