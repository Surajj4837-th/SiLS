#include "SiLS.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SiLS w;
    w.show();
    return a.exec();
}
