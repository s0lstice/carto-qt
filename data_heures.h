#ifndef DATA_HEURES_H
#define DATA_HEURES_H

#include "database.h"
#include "heure.h"

bool addHeur(int point_id, int joure, QString debut, QString fin );
QVector<heure> getHeureByPoint(int point_id);
bool initHeuresTable();


#endif // DATA_HEURES_H
