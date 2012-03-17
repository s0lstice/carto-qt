#ifndef POI_H
#define POI_H

#include <QString>
#include <QDate>

class POI {

 private :
    QString name;
    QString description;
    QString categorie;
    float lon;
    float lat;
    QDate horaires;
    float distance;
   public :


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
    QDate GetHoraires()
    {
        return horaires;
    }
    void SetHoraires(QDate H)
    {
        horaires=H;
    }
};

#endif // POI_H
