#ifndef DATA_CATEGORIES_H
#define DATA_CATEGORIES_H

#include "database.h"

bool addCategorie(QString categorie);
QString getCategorieById(int id);
int getCategorieIdByName(QString name);
bool initCategoriesTable();
QVector<QString> getCategories();


#endif // DATA_CATEGORIES_H
