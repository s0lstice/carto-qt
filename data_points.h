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
QVector<POI> getPointImp(float Posx,float Posy,int nbpts);
QVector<POI> getPoint(float latitude, float longitude, QString name);
int getIdPoint(QString categorie, QString name, float latitude, float longitude);
bool initPointsTable();


#endif // DATA_POINTS_H
