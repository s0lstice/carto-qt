#include "data_jours.h"
#include "database.h"



bool initJoursTable(){
    QSqlQuery query(database::dataCreate()->dataConnect());

    QStringList jours;
    jours << QObject::tr("dimanche")
            << QObject::tr("lundi")
            << QObject::tr("mardi")
            << QObject::tr("mercredi")
            << QObject::tr("jeudi")
            << QObject::tr("vendredi")
            << QObject::tr("samedi");

    query.exec("create table jours ("
                  "jour_id INTEGER PRIMARY KEY AUTOINCREMENT, "
                  "jour VARCHAR(64),"
                  "unique (jour))");


    foreach(QString jour, jours){
        query.exec("insert into jours(jour) values('" + jour + "')");

    }
    qDebug("ok");
    return true;
}
