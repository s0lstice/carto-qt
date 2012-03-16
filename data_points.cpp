#include "data_points.h"
#include "data_categories.h"


bool initPointsTable(){

    QSqlQuery query(database::dataCreate()->dataConnect());


    if(query.exec("create table points ("
                  "point_id INTEGER PRIMARY KEY AUTOINCREMENT, "
                  "name VARCHAR(64), "
                  "categorie_id INTEGER, "
                  "latitude FLOAT, "
                  "longitude FLOAT, "
                  "description VARCHAR(1024), "
                  "FOREIGN KEY(categorie_id) REFERENCES categories(point_id), "
                  "unique (name, categorie_id, latitude, longitude))") == false)
    {
        qDebug()<< "initPointsTable" << query.lastError().text();
        return false;
    }
    return true;
}

bool addPoint(QString categorie, QString name, float latitude, float longitude, QString description){
    QSqlQuery query(database::dataCreate()->dataConnect());

    addCategorie(categorie);

    if( query.exec("insert into points(latitude, longitude, categorie_id, name, description) values("
        + QString::number(latitude)
        + "," + QString::number(longitude)
        + "," + QString::number(getCategorieIdByName(categorie))
        + ",'" + name
        + ",'" + description
        + "')") == false)
    {
        qDebug()<< "addPoint" << query.lastError().text();
        return false;
    }

    return true;
}

bool addPoint(QString categorie, QString name, float latitude, float longitude){
    QSqlQuery query(database::dataCreate()->dataConnect());

    addCategorie(categorie);

    if( query.exec("insert into points(latitude, longitude, categorie_id, name) values("
        + QString::number(latitude)
        + "," + QString::number(longitude)
        + "," + QString::number(getCategorieIdByName(categorie))
        + ",'" + name
        + "')") == false)
    {
        qDebug()<< "addPoint" << query.lastError().text();
        return false;
    }

    return true;
}

QVector<POI> getPointByCategorie(QString categorie){
    QSqlQuery query(database::dataCreate()->dataConnect());
    POI tmpPOI;
    QVector<POI> tabPOI;

    if(query.exec("SELECT latitude, longitude, name, categorie_id FROM points WHERE categorie_id = '"+ QString::number(getCategorieIdByName(categorie)) +"'") == false)
    {
        qDebug()<< "getPointByCategorie" << query.lastError().text();
        exit(1);
    }

    while(query.next()){
        tmpPOI.SetCat(query.value(3).toString());
        tmpPOI.SetName(getCategorieById(query.value(2).toInt()));
        tmpPOI.Setlat(query.value(0).toFloat());
        tmpPOI.Setlong(query.value(1).toFloat());

        tabPOI.append(tmpPOI);
    }

    return tabPOI;
}

QVector<POI> getPointByName(QString name){
   QSqlQuery query(database::dataCreate()->dataConnect());
   POI tmpPOI;
   QVector<POI> tabPOI;

   if(query.exec("SELECT latitude, longitude, name, categorie_id FROM points WHERE name = '"+ name +"'") == false)
   {
       qDebug()<< "getPointByName" << query.lastError().text();
       exit(1);
   }

   while(query.next()){
       tmpPOI.SetCat(getCategorieById(query.value(3).toInt()));
       qDebug() << tmpPOI.GetCat();
       tmpPOI.SetName(query.value(2).toString());
       qDebug() << tmpPOI.GetName();
       tmpPOI.Setlat(query.value(0).toFloat());
       qDebug() << tmpPOI.Getlat();
       tmpPOI.Setlong(query.value(1).toFloat());
       qDebug() << tmpPOI.Getlon();

       tabPOI.append(tmpPOI);
   }

   return tabPOI;
}

QVector<POI> getPoint(float latitude, float longitude, QString name){
    QSqlQuery query(database::dataCreate()->dataConnect());
   POI tmpPOI;
   QVector<POI> tabPOI;

   if(query.exec("SELECT latitude, longitude, name, categorie_id "
                 "FROM points "
                 "WHERE name = '"+ name +"' and "
                 + "latitude = '" + QString::number(latitude) + "' and "
                 + "longitude = '" + QString::number(longitude) +"'") == false)
   {
       qDebug()<< "getPoint" << query.lastError().text();
       exit(1);
   }

   while(query.next()){
       tmpPOI.SetCat(getCategorieById(query.value(3).toInt()));
       tmpPOI.SetName(query.value(2).toString());
       tmpPOI.Setlat(query.value(0).toFloat());
       tmpPOI.Setlong(query.value(1).toFloat());

       tabPOI.append(tmpPOI);
   }

   return tabPOI;
}

QVector<POI> getPoint(float latitude, float longitude){
    QSqlQuery query(database::dataCreate()->dataConnect());
   POI tmpPOI;
   QVector<POI> tabPOI;

   if(query.exec("SELECT latitude, longitude, name, categorie_id, description "
                 "FROM points "
                 "WHERE latitude = '" + QString::number(latitude) + "' and "
                 + "longitude = '" + QString::number(longitude) +"'") == false)
   {
       qDebug()<< "getPoint" << query.lastError().text();
       exit(1);
   }

   while(query.next()){
       tmpPOI.SetCat(getCategorieById(query.value(3).toInt()));
       tmpPOI.SetName(query.value(2).toString());
       tmpPOI.Setlat(query.value(0).toFloat());
       tmpPOI.Setlong(query.value(1).toFloat());
       tmpPOI.SetDesc(query.value(3).toString());
       tabPOI.append(tmpPOI);
   }

   return tabPOI;
}

int getIdPoint(QString categorie, QString name, float latitude, float longitude){
    QSqlQuery query(database::dataCreate()->dataConnect());

   if(query.exec("SELECT point_id "
                 "FROM points "
                 "WHERE latitude = '" + QString::number(latitude) + "' and "
                 + "longitude = '" + QString::number(longitude) +"' and "
                 + "name = '" + name + "' and "
                 + "categorie_id = '" + QString::number(getCategorieIdByName(categorie)) + "'") == false)
   {
       qDebug()<< "getIdPoint" << query.lastError().text();
       exit(1);
   }

   query.next();
   return query.value(0).toInt();

}
