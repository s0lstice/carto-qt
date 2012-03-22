/**
 * \file data_points.h
 * \brief Bibliotheque de fonctions gerant la table points. utilise formement la classe database.
 * \author Guillaume Lastecoueres & Mickael Puret
 * \version 0.1
 *
 * Ensemble de fonctions de gestion de la table points
 *
 */

#ifndef DATA_POINTS_H
#define DATA_POINTS_H

#include <QtSql>
#include "POI.h"
#include "database.h"
#include <QMutex>

bool addPoint(QString categorie, QString name, float latitude, float longitude);
bool addPoint(QString categorie, QString name, float latitude, float longitude, QString description);
QVector<POI> getPointByName(QString name,int nbpts);
QVector<POI> getPointByCategorie(QString categorie);
QVector<POI> getPoint(float latitude, float longitude);
QVector<POI> getPointImp(float latitude, float longitude,int nbpts,QString name,QString cat);
QVector<POI> getPoint(float latitude, float longitude, QString name);
int getIdPoint(QString categorie, QString name, float latitude, float longitude);
bool initPointsTable();


#endif // DATA_POINTS_H
