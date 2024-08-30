#include <QApplication>
#include "hellobutton.h"
int main(int argc, char* argv[])
{
    QApplication app(argc, argv);

    HelloButton btn;

    QObject::connect(&btn, &HelloButton::closethisstuf, &app, &QApplication::quit);

    btn.show();

    return app.exec();
}
