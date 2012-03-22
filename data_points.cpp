#include "data_points.h"
#include "data_categories.h"

/*! fonction creant la table points dans la base de donnée
 @return vrai|fau : bool : indique la reussite ou l'echque de l'initialisation
 @note les champs de la table points sont :\n
    -point_id : INTEGER PRIMARY KEY AUTOINCREMENT : clef primaire de latable\n
    -name : VARCHAR(64) : nom d'un point, 64 caratere maximum\n
    -categorie_id : INTEGER : clef etrangere sur la table categorie\n
    -latitude : FLOAT : latitude du point\n
    -longitude : FLOAT : longitude du point\n
    -description : VARCHAR(1024) : description du point, 1024 caractere maximum\n
    info : les champs name, latitude, longitude, categorie_id forme un group unique.
*/
bool initPointsTable(){

    QSqlQuery query(database::dataCreate()->dataConnect());

    query.exec("create table points ("
                  "point_id INTEGER PRIMARY KEY AUTOINCREMENT, "
                  "name VARCHAR(64), "
                  "categorie_id INTEGER, "
                  "latitude FLOAT, "
                  "longitude FLOAT, "
                  "description VARCHAR(1024), "
                  "FOREIGN KEY(categorie_id) REFERENCES categories(point_id), "
                  "unique ( name,latitude, longitude,categorie_id))");

    return true;
}

/*! fonction : obtenir les points de la base de donnée
  @param latitude : float
  @param longitude : flaot
  @param nbpts : int : nombre maximum de points renvoyés
  @param name : QString
  @param Cat : QString : categorie des points recherché
  @return QVector<POI> : un vecteur de POI
*/

QVector<POI> getPointImp(float latitude, float longitude,int nbpts,QString Name,QString Cat)
{
   QSqlQuery query(database::dataCreate()->dataConnect());
   POI tmpPOI;
   QVector<POI> tabPOI;
   if(Cat!="")
   {
       if(query.exec("SELECT latitude, longitude, name, categorie_id ,description,point_id,((latitude - "+ QString::number(latitude)+  ") * (latitude - "+ QString::number(latitude) +  ")) + ((longitude - "+ QString::number(longitude) +  ") * (longitude -" + QString::number(longitude)+  ")) distance FROM points  WHERE categorie_id = "+ QString::number(getCategorieIdByName(Cat)) + " AND name like '%" + Name +"%' ORDER BY distance LIMIT " + QString::number(nbpts) + " ;") == false)
       {
           return tabPOI;
       }
    }
   else
   {
       if(query.exec("SELECT latitude, longitude, name, categorie_id ,description,point_id,((latitude - "+ QString::number(latitude)+  ") * (latitude - "+ QString::number(latitude) +  ")) + ((longitude - "+ QString::number(longitude) +  ") * (longitude -" + QString::number(longitude)+  ")) distance FROM points  WHERE name like '%" + Name +"%' ORDER BY distance LIMIT " + QString::number(nbpts) + " ;") == false)
       {
           return tabPOI;
       }
   }
   while(query.next()){
       tmpPOI.SetCat(getCategorieById(query.value(3).toInt()));
       tmpPOI.SetName(query.value(2).toString());
       tmpPOI.Setlat(query.value(0).toFloat());
       tmpPOI.Setlong(query.value(1).toFloat());
       tmpPOI.SetDesc(query.value(4).toString());
       tmpPOI.SetDist(query.value(6).toFloat());
       tmpPOI.SetId(query.value(5).toInt());
       tabPOI.append(tmpPOI);
   }

   return tabPOI;
}
/*! fonction : ajoute un point dans la base de donnée
  @param latitude : float
  @param longitude : flaot
  @param name : QString
  @param categorie : QString
  @param description : QString
  @return bool : vrai, l'ajouté a réussit | fau, echec de l'ajout
*/
bool addPoint(QString categorie, QString name, float latitude, float longitude, QString description){

    QSqlQuery query(database::dataCreate()->dataConnect());

    addCategorie(categorie);

    if( query.exec("insert into points(latitude, longitude, categorie_id, name, description) values("
        + QString::number(latitude)
        + "," + QString::number(longitude)
        + "," + QString::number(getCategorieIdByName(categorie))
        + ",'" + name
        + "','" + description
        + "');") == false)
    {
        return false;
    }

    return true;
}

/*! fonction : ajoute un point dans la base de donnée
  @param latitude : float
  @param longitude : flaot
  @param name : QString
  @param categorie : QString
  @return bool : vrai, l'ajouté a réussit | fau, echec de l'ajout
*/
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

        return false;
    }

    return true;
}

/*! fonction : permet d'obtenir les points en fonction de la categorie
  @param categorie : QString : categorie recherché
  @return QVector<POI>  : un vecteur de points
*/
QVector<POI> getPointByCategorie(QString categorie){
    QSqlQuery query(database::dataCreate()->dataConnect());
    POI tmpPOI;
    QVector<POI> tabPOI;

    if(query.exec("SELECT latitude, longitude, name, categorie_id, point_id FROM points WHERE categorie_id = "+ QString::number(getCategorieIdByName(categorie))  + " ;") == false)
    {
        qDebug()<< "getPointByCategorie" << query.lastError().text();
        exit(1);
    }

    while(query.next()){
        tmpPOI.SetId(query.value(4).toInt());
        tmpPOI.SetCat(getCategorieById(query.value(3).toInt()));
        tmpPOI.SetName(query.value(2).toString());
        tmpPOI.Setlat(query.value(0).toFloat());
        tmpPOI.Setlong(query.value(1).toFloat());
        tabPOI.append(tmpPOI);
    }
    return tabPOI;
}
/*! fonction : permet d'obtenir les points en fonction de leurs nom
  @param name : QString : nom recherché
  @param nbpts : int : nombre de points maximum renvoyé
  @return QVector<POI>  : un vecteur de points
*/
QVector<POI> getPointByName(QString name,int nbpts){
   QSqlQuery query(database::dataCreate()->dataConnect());
   POI tmpPOI;
   QVector<POI> tabPOI;

   if(query.exec("SELECT latitude, longitude, name, categorie_id FROM points WHERE name like '"+ name +"%' OR description like '" + name +"%' LIMIT " + QString::number(nbpts)) == false)
   {
       qDebug()<< "getPointByName" << query.lastError().text();
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

/*! fonction : permet d'obtenir les points en fonction de leurs nom et de leurs positions
  @param name : QString : nom recherché
  @param latitude : float
  @param longitide : float
  @return QVector<POI>  : un vecteur de points
*/
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



