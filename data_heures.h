/**
 * \file data_heures.h
 * \brief Bibliotheque de fonctions gerant la table heures. utilise formement la classe database.
 * \author Guillaume Lastecoueres & Mickael Puret
 * \version 0.1
 *
 * Ensemble de fonctions de gestion de la table heures
 *
 */

#ifndef DATA_HEURES_H
#define DATA_HEURES_H

#include "database.h"
#include "heure.h"

bool addHeur(int point_id, int jour_id, QString debut, QString fin );
QVector<heure> getHeureByPoint(int point_id);
QSqlRecord getHeureByPointRecord(int point_id);
bool initHeuresTable();


#endif // DATA_HEURES_H
