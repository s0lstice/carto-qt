#include "data_csv.h"
#include "data_categories.h"
#include "POI.h"
#include "data_points.h"
#include "heure.h"
#include "data_heures.h"
#include "data_jours.h"

void export_csv(){
    QVector<QString> categories;
    QVector<POI> points;
    QVector<heure> heures;

    QFile file("export.csv");
    if(!file.open(QIODevice::WriteOnly)){
        qWarning() << "[erreur] impossible d'ouvrir le ficher en ecriture seul"
                  << qPrintable(file.errorString());
        return;
    }

    QTextStream out(&file);

    categories = getCategories();
    foreach(QString categorie, categories){
        points = getPointByCategorie(categorie);

        foreach(POI point, points){
            heures = getHeureByPoint(point.GetId());

            out << point.GetName() << ";"
                << point.GetCat() << ";"
                << point.Getlat() << ";"
                << point.Getlon() << ";"
                << point.GetDesc() << ";" << endl;

            foreach(heure p_heure, heures){
                out << ";" << jourById(p_heure.getJour()) << ";"
                    << p_heure.getDebut() << ";"
                    << p_heure.getFin() << endl;
            }
        }
    }
}
