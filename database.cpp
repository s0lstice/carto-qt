#include "database.h"
#include "POI.h"
#include "heure.h"
#include "data_jours.h"
#include "data_heures.h"
#include "data_points.h"
#include "data_categories.h"
#include "data_jours.h"

database *database::_singleton = NULL;
bool database::initTable = false;
QString database::dataName = "";

database::database(QString name)
{
    db = QSqlDatabase :: addDatabase("QSQLITE");

    db.setDatabaseName(name + ".db");
    if(db.open() == false){
        throw(db.lastError());
    }
    if(initTable == false){
        initTable = true;
        initCategoriesTable();
        initPointsTable();
        initHeuresTable();
        initJoursTable();
    }
}

database::~database(){
    db.close();
}


QSqlDatabase database::dataConnect(){
    return db;
}
