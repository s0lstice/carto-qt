#ifndef HORRAIRES_H
#define HORRAIRES_H

#endif // HORRAIRES_H

#include <QString>
#include <QDateTime>
#include <QVector>
#include <QtCore>
class Horaires {

private :
    QVector<QDateTime> Plage;

    int count;

public :
    void AddDate(QDateTime dateD,QDateTime DateF)
    {


        if(dateD.date().day()!=DateF.date().day())
        {
            throw("Erreur 1 : Erreur date différente");
        }
        if(dateD<DateF)
        {
            throw("Erreur 2 : date de debut inferieur à date de fin");
        }


        Plage.insert(Plage.size(),dateD);
        Plage.insert(Plage.size(),DateF);
        count=count +1 ;
    }

};
