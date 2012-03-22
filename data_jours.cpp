#include "data_jours.h"
#include "database.h"

/*! fonction : creant la table heures dans la base de donnée
 @return vrai|fau : bool : indique la reussite ou l'echque de l'initialisation
 @note les champs de la table points sont :\n
    -jour_id : INTEGER PRIMARY KEY AUTOINCREMENT : clef primaire de latable\n
    -jour : VARCHAR(64) : nom du jour, 64 caratere maximum\n
    info : le champ jour est unique.\n
        Tout comme dans sql au niveau de la gestion des jours, ceci vont de dimanche a samedi avec des identifiant de 1 a 7.\n
        Les jours sont contenuent dans un QStringList et permetent leurs traduction. a ce niveau, il et donc paussible de donner une langue a la base de donnee.
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

    query.exec("create table jours ("
                  "jour_id INTEGER PRIMARY KEY AUTOINCREMENT, "
                  "jour VARCHAR(64),"
                  "unique (jour))");


    foreach(QString jour, jours){
        query.exec("insert into jours(jour) values('" + jour + "')");
    }
    return true;
}

/*! fonction : permet de connaitre le jour en fonction de l'identifiant
  @param jour_id : int : identifiant du jour
  @return QString : nom du jour.
*/
QString jourById(int jour_id){
    QSqlQuery query(database::dataCreate()->dataConnect());

    if( query.exec("SELECT jour FROM jours WHERE jour_id = " + QString::number(jour_id)) == false){
        qDebug()<< "jourById" << query.lastError().text();
        exit(1);
    }
    query.next();
    return query.value(0).toString();
}
