#include "data_jours.h"
#include "database.h"

/*
QString jourById(int id){
    QVector <QString> jours;

    jours.append(QObject::tr("dimanche"));
    jours.append(QObject::tr("lunid"));
    jours.append(QObject::tr("mardi"));
    jours.append(QObject::tr("mercredi"));
    jours.append(QObject::tr("jeudi"));
    jours.append(QObject::tr("vendredi"));
    jours.append(QObject::tr("samedi"));

    return jours.value(id);
}
*/

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

    if(query.exec("create table jours ("
                  "jour_id INTEGER PRIMARY KEY AUTOINCREMENT, "
                  "jour VARCHAR(64),"
                  "unique (jour))") == false)
    {
        qDebug()<< "initJoursTable" << query.lastError().text();
        return false;
    }

    foreach(QString jour, jours){
        if(query.exec("insert into jours(jour) values('" + jour + "')") == false){
            qDebug()<< "initJoursTable" << query.lastError().text();
            return false;
        }

    }
    return true;
}
