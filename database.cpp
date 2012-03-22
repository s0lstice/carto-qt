#include "database.h"
#include "POI.h"
#include "heure.h"
#include "data_jours.h"
#include "data_heures.h"
#include "data_points.h"
#include "data_categories.h"
#include "data_jours.h"

database *database::_singleton = NULL;
QString database::dataName = "";

/*!
  @fn database::database(QString name)
  @brief constructeur du gestionnaire de base de donnée
  @param name : QString : nom de la base de donné
  @note info : ce constructeur est privé, la casse database est un singleton. pour instancier cette classe il faut utiliser la fonction "static database *dataCreate(QString name)"
*/
database::database(QString name)
{
    db = QSqlDatabase :: addDatabase("QSQLITE");
    qDebug()<<"Le nom est " << name;
    db.setDatabaseName(name + ".db");
    if(db.open() == false){
        throw(db.lastError());
    }
}
/*!
  @fn void database::initTable()
  @brief fonction d'initialisation des table de la base de donnée (privé)
*/
void database::initTable(){
    initCategoriesTable();
    initPointsTable();
    initHeuresTable();
    initJoursTable();
}

/*!
  @fn database::~database()
  @brief destructeur privé
  @note ferme la base de donné avant la destruction
*/
database::~database(){
    db.close();
}

/*!
  @fn QSqlDatabase database::dataConnect()
  @brief renvoi le descripteur de la base de donnée
  @return db : QSqlDatabase : descripteur de la pase de donnée
*/
QSqlDatabase database::dataConnect(){
    return db;
}
