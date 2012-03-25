/*! \class data_heures data_heures.h
 * \brief Ceci est une bibilotheque fournissant des fonctions en lecture-ecriture sur la table heures. (\link data_heures.cpp data_heures.cpp \endlink)
*/
#include "data_heures.h"
#include "data_jours.h"

/*!
  @fn bool initHeuresTable(){
  @brief fonction : creant la table heures dans la base de donnée
 @return vrai|fau : bool : indique la reussite ou l'echque de l'initialisation
 @note les champs de la table points sont :\n
    -heure_id : INTEGER PRIMARY KEY AUTOINCREMENT : clef primaire de latable\n
    -point_id : INTEGER : clef etrengere sur points.point_id\n
    -debut : HEURE : heur d'ouverture\n
    -fin : HEURE : heur de fermeture
*/
bool initHeuresTable(){
    QSqlQuery query(database::dataCreate()->dataConnect());

    query.exec("create table heures (heure_id INTEGER PRIMARY KEY AUTOINCREMENT,"
                  "point_id INTEGER,"
                  "jour INTEGER,"
                  "debut HEURE,"
                  "fin HEURE,"
                  "FOREIGN KEY(point_id) REFERENCES points(point_id))");

    return true;
}

/*!
  @fn bool addHeur(int point_id,int jour_id, QString debut, QString fin ){
  @brief fonction : permet d'ajouter une plage horaire
  @param point_id : int : identifiant du point associe
  @param jour_id : int : identifiant du jour
  @param debut : QString : heur d'ouverture sous la forme HH:mm
  @param fin : QString : heur de fermeture sous la forme HH:mm
  @return vrai|fau : bool : indique la reussite ou l'echque de l'initialisation
*/
bool addHeur(int point_id,int jour_id, QString debut, QString fin ){
    QSqlQuery query(database::dataCreate()->dataConnect());
    if( query.exec("insert into heures (point_id, jour, debut, fin) values("
                   + QString::number(point_id)
                   + "," + QString::number(jour_id)
                   + ",'" + debut
                   + "','" + fin
                   + "')") == false)
    {
        qDebug()<< "addHeur" << query.lastError().text();
        return false;
    }
    return true;
}

/*!
  @fn QVector<heure> getHeureByPoint(int point_id){
  @brief fonction : permet d'obtenir les plages horaire d'un point
  @param point_id : int : identifiant du point associe
  @return QVector<heure> : un vecteur d'heurs de la classe heure
*/
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

/*!
  @fn QSqlRecord getHeureByPointRecord(int point_id){
  @brief fonction : permet d'obtenir les plages horaire d'un point
  @param point_id : int : identifiant du point associe
  @return QSqlRecord : le resultat de la requet sqlite
*/
QSqlRecord getHeureByPointRecord(int point_id){
    QSqlQuery query(database::dataCreate()->dataConnect());


     if(query.exec("SELECT jour, debut, fin FROM heures WHERE point_id = '"+
                   QString::number(point_id) +"'") == false)
     {
         qDebug()<< "getHeureByPoint" << query.lastError().text();
         exit(1);
     }

 return query.record();
}
