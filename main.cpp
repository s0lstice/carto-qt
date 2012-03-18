#include <QtGui/QApplication>
#include <QSettings>
#include "askdatabase.h"
#include <QObject>
#include "data_categories.h"


int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    AskDataBase w;
    w.show();
    QSettings settings("CartoTeam", "Cartographe");
    if(settings.value("Categories","NULL").toString()=="NULL"){

        QVariantList ListeDeCat;
        ListeDeCat.append("supermarche");
        ListeDeCat.append("musee");
        ListeDeCat.append("cinema");
        ListeDeCat.append("theatre");

        settings.setValue("Categories",ListeDeCat);
}
    a.exec();
    QVariantList EndList;
    QVector<QString> Categories= getCategories();
    int i = 0;
    for(i=0;i<Categories.count();i++)
    {
        EndList.append(Categories.value(i));
    }
settings.setValue("Categories",EndList);



    return 1;
}
