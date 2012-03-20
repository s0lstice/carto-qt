#include <QtGui/QApplication>
#include <QSettings>
#include "askdatabase.h"
#include <QObject>
#include "data_categories.h"
#include "application.h"



/*! Initialise le programme

    \note Nous appellons un objet de la classe application qui herite de la classe Qapplication. Cela est fait pour permettre les traductions ainsi que mettre aux propres les QSettings.
*/
int main(int argc, char *argv[])
{
    application  *app = application::appInit(argc, argv);
    AskDataBase w;
    w.show();
    app->exec();
    app->appExit();
    return 0 ;

}
