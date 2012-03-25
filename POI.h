/**
 * \file POI.h
 * \brief Classe permetant de contenir toutes les informations d'un point.
 * \author Guillaume Lastecoueres & Mickael Puret
 * \version 0.1
 *
 *
 */

#ifndef POI_H
#define POI_H

#include <QString>
#include <QDate>

class POI {

 private :
    int id;
    QString name;
    QString description;
    QString categorie;
    float lon;
    float lat;
    float distance; // Sert pour trier les points par distance par rapport au centre de vue;
   public :

    void SetId(int id){
        this->id = id;
    }

    int GetId(){
        return id;
    }

    float GetDist()
    {
        return distance;
    }

    void SetDist(float dist)
    {
        distance = dist;
    }

    QString GetName(){
        return name;
    }
    void SetName(QString name2){
        name = name2;
    }

    QString GetDesc(){
        return description;
    }
    void SetDesc(QString description2){
        description = description2;
    }
    QString GetCat(){
        return categorie;
    }
    void SetCat(QString categorie2){
        categorie=categorie2;
    }
    float Getlon()
    {
        return lon;
    }
    void Setlong(float f)
    {
        lon = f;
    }
    float Getlat()
    {
        return lat;
    }
    void Setlat(float f)
    {
        lat = f;
    }
};

#endif // POI_H
