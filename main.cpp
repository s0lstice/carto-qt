#include <QtGui/QApplication>
#include "qmlapplicationviewer.h"
#include "database.h"
#include "data_points.h"
#include "data_heures.h"
#include "POI.h"
#include "data_gui.h"
#include "edit_point_gui.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    database::dataCreate("cartoPoints");

/*
    QVector<POI> tabdatas;
    QVector<heure> tabheure;

    qDebug() <<"> ajout de point 1 : " <<addPoint("test1", "test4",  (float)3.1234, (float)2.67890);
    qDebug() <<"> ajout de point 2 : " <<addPoint("test2", "test2",  (float)3.1234, (float)2.67890);
    qDebug() <<"> ajout de point 3 : " <<addPoint("test3", "test1",  (float)3.1234, (float)2.67890);

    qDebug() <<"> ajout d'heure 1 : " <<addHeur(2,1, "11:13:14", "13:13:14");
    qDebug() <<"> ajout d'heure 2 : " <<addHeur(1,2, "12:13:14", "14:13:14");
    qDebug() <<"> ajout d'heure 3 : " <<addHeur(3,3, "13:13:14", "15:13:14");

    qDebug() <<"> ajout d'heure 1 : " <<addHeur(3,1, "11:13:14", "13:13:14");
    qDebug() <<"> ajout d'heure 2 : " <<addHeur(2,2, "12:13:14", "14:13:14");
    qDebug() <<"> ajout d'heure 3 : " <<addHeur(1,3, "13:13:14", "15:13:14");

    qDebug() <<"> ajout d'heure 1 : " <<addHeur(1,1, "11:13:14", "13:13:14");
    qDebug() <<"> ajout d'heure 2 : " <<addHeur(3,2, "12:13:14", "14:13:14");
    qDebug() <<"> ajout d'heure 3 : " <<addHeur(2,3, "13:13:14", "15:13:14");

    qDebug("> getpointByName : test2");
    tabdatas = getPointByName("test2");
    qDebug() << "nb table avec test2 comme nom" << tabdatas.size();

    qDebug("> getpointByName : test1");
    tabdatas = getPointByName("test1");
    qDebug() << ">> nb table : " << tabdatas.size();

    qDebug() << "> getPoint((float)3.1234, (float)2.67890, test2)";
    tabdatas = getPoint((float)3.1234, (float)2.67890, "test2");
    qDebug() << ">> nb table : " << tabdatas.size();

    qDebug() << "> getPoint((float)3.1234, (float)2.67890)";
    tabdatas = getPoint((float)3.1234, (float)2.67890);
    qDebug() << ">> nb table : " << tabdatas.size();

    qDebug() << "> heure du point 0 ";
    tabheure = getHeureByPoint(0);
    qDebug() << ">> nb table : " << tabheure.size();

    qDebug() << "> heure du point 1 ";
    tabheure = getHeureByPoint(1);
    qDebug() << ">> nb table : " << tabheure.size();

    qDebug() << "> heure du point 3 ";
    tabheure = getHeureByPoint(3);
    qDebug() << ">> nb table : " << tabheure.size();

    qDebug() << "> id point 1 : " << getIdPoint("test3", "test1",  (float)3.1234, (float)2.67890);
*/
    edit_point_gui window(1);
    //window.exec();

    return window.exec();
}
