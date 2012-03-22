/**
 * \file data_categories.h
 * \brief Bibliotheque de fonctions gerant la table categorie. utilise formement la classe database.
 * \author Guillaume Lastecoueres & Mickael Puret
 * \version 0.1
 *
 * Ensemble de fonctions de gestion de la table categories
 *
 */

#ifndef DATA_CATEGORIES_H
#define DATA_CATEGORIES_H

#include "database.h"

bool addCategorie(QString categorie);
QString getCategorieById(int id);
int getCategorieIdByName(QString name);
bool initCategoriesTable();
QVector<QString> getCategories();


#endif // DATA_CATEGORIES_H
