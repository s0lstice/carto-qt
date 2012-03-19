#include "application.h"
#include <QSettings>
#include "data_categories.h"
application *application::_singleton = NULL;

application::application(int & argc, char ** argv) : QApplication(argc, argv)
{

    QSettings settings("CartoTeam", "Cartographe");
    if(settings.value("Categories","NULL").toString()=="NULL"){

        QVariantList ListeDeCat;
        ListeDeCat.append("supermarche");
        ListeDeCat.append("musee");
        ListeDeCat.append("cinema");
        ListeDeCat.append("theatre");

        settings.setValue("Categories",ListeDeCat);
    }
}


application::~application()
{
    QSettings settings("CartoTeam", "Cartographe");
    QVariantList EndList;
    QVector<QString> Categories= getCategories();
    int i = 0;
    for(i=0;i<Categories.count();i++)
    {
        EndList.append(Categories.value(i));
    }
settings.setValue("Categories",EndList);

}

