#include "data_categories.h"

/*!
  @fn bool initCategoriesTable(){

  @brief fonction : creant la table categories dans la base de donnée
 @return vrai|fau : bool : indique la reussite ou l'echque de l'initialisation
 @note les champs de la table points sont :\n
    -categorie_id : INTEGER PRIMARY KEY AUTOINCREMENT : clef primaire de latable\n
    -categorie : VARCHAR(64) : nom de la categorie\n
    @note categorie est unique
*/
bool initCategoriesTable(){
    QSqlQuery query(database::dataCreate()->dataConnect());

    query.exec("create table categories ("
                  "categorie_id INTEGER PRIMARY KEY AUTOINCREMENT, "
                  "categorie VARCHAR(64),"
                  "unique (categorie))");


    return true;
}

/*!
  @fn bool addCategorie(QString categorie){
  @brief fonction : ajoute la categorie passe en parametre
 @param categorie : QString : nom de la categorie a ajouter
 @return vrai|fau : bool : indique la reussite ou l'echque de l'instertion
*/
bool addCategorie(QString categorie){
    QSqlQuery query(database::dataCreate()->dataConnect());
    if( query.exec("insert into categories(categorie) values('"
                   + categorie
                   + "')") == false)
    {
        qDebug()<< "addCategorie" << query.lastError().text();
        return false;
    }
    return true;
}

/*!
  @fn QString getCategorieById(int id){
  @brief fonction : retourne le nom de la categorie en fonction de l'identifiant
 @param id : int : identifiant cherche
 @return QString : nom de la categorie
*/
QString getCategorieById(int id){
    QSqlQuery query(database::dataCreate()->dataConnect());

     if(query.exec("SELECT categorie FROM categories WHERE categorie_id = '"+ QString::number(id) +"'") == false)
     {
         qDebug()<< "getCategorieById" << query.lastError().text();
         exit(1);
     }

     query.next();

     return query.value(0).toString();
}

/*!
  @fn int getCategorieIdByName(QString name){
  @brief fonction : retourne l'identifiant de la categorie en fonction de son nom
 @return id : int : identifiant cherche
 @param QString : nom de la categorie
*/
int getCategorieIdByName(QString name){
    QSqlQuery query(database::dataCreate()->dataConnect());

     if(query.exec("SELECT categorie_id FROM categories WHERE categorie = '"+ name +"'") == false)
     {
         qDebug()<< "getCategorieByPoint" << query.lastError().text();
         exit(1);
     }

     query.next();
     return query.value(0).toInt();
}

/*!
  @fn QVector<QString> getCategories()
  @brief fonction : retourne un vecteur avec toutes les categories de la base de donnee
 @return id : int : identifiant cherche
 @return QVector<QString>  : vecteur de categories
*/
QVector<QString> getCategories()
{
   QSqlQuery query(database::dataCreate()->dataConnect());
   QVector<QString> categories;

   if(query.exec("SELECT categorie FROM categories ORDER BY categorie ASC;") == false)
   {
       qDebug()<< "getCategories" << query.lastError().text();
       exit(1);
   }

   while(query.next()){
       categories.append(query.value(0).toString());
   }

   return categories;
}
