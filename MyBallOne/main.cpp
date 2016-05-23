#include "myballone.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MyBallOne w;
    w.show();


    return a.exec();
}
