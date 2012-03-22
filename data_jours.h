/**
 * \file data_jours.h
 * \brief Bibliotheque de fonctions gerant la table jours. utilise formement la classe database.
 * \author Guillaume Lastecoueres & Mickael Puret
 * \version 0.1
 *
 * Ensemble de fonctions de gestion de la table jours
 *
 */

#ifndef DATA_jour_H
#define DATA_jour_H

#include "database.h"

//QString jourById(int id);
bool initJoursTable();
QString jourById(int jour_id);

#endif // DATA_jour_H
