#include "widget.h"

#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    Widget w1;
    w1.show();
    w.show();
    return a.exec();
}
