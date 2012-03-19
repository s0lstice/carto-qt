#include <QtGui/QApplication>
#include <QSettings>
#include "askdatabase.h"
#include <QObject>
#include "data_categories.h"
#include "application.h"

int main(int argc, char *argv[])
{
    application  *app = application::appInit(argc, argv);
    AskDataBase w;
    w.show();
    app->exec();
    app->appExit();
    return 0 ;

}
