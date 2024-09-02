#include <QCoreApplication>
#include "printthread.h"
int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);

    PrintThread a("A",300),b("B", 500);
    a.start();
    b.start();
    return app.exec();
}
