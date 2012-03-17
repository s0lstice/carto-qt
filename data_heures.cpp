#include "data_heures.h"


bool initHeuresTable(){
    QSqlQuery query(database::dataCreate()->dataConnect());

    query.exec("create table heures (heure_id INTEGER PRIMARY KEY AUTOINCREMENT,"
                  "point_id INTEGER,"
                  "jour INTEGER,"
                  "debut HEURE,"
                  "fin DATE,"
                  "FOREIGN KEY(point_id) REFERENCES points(point_id))");

    return true;
}

bool addHeur(int point_id,int jour, QString debut, QString fin ){
    QSqlQuery query(database::dataCreate()->dataConnect());
    if( query.exec("insert into heures (point_id, jour, debut, fin) values("
                   + QString::number(point_id)
                   + "," + QString::number(jour)
                   + ",'" + debut
                   + "','" + fin
                   + "')") == false)
    {
        qDebug()<< "addHeur" << query.lastError().text();
        return false;
    }
    return true;
}

QVector<heure> getHeureByPoint(int point_id){
    QSqlQuery query(database::dataCreate()->dataConnect());
     heure tmpHeure;
     QVector<heure> tabHeure;

     if(query.exec("SELECT jour, debut, fin FROM heures WHERE point_id = '"+
                   QString::number(point_id) +"'") == false)
     {
         qDebug()<< "getHeureByPoint" << query.lastError().text();
         exit(1);
     }

     while(query.next()){
         tmpHeure.setJour(query.value(0).toInt());
         tmpHeure.setDebut(query.value(1).toString());
         tmpHeure.setFin(query.value(2).toString());

         tabHeure.append(tmpHeure);
     }

     return tabHeure;
}
