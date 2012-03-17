#include <QtGui/QApplication>

#include "askdatabase.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    AskDataBase w;
    w.show();
    return a.exec();
}
