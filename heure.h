#ifndef HEURES_H
#define HEURES_H

#include <QString>
#include <QDate>

class heure{
private :
    int jour;
    QTime debut;
    QTime fin;


public:
    heure();

    void setJour(int jour);
    void setDebut(QString debut);
    void setDebut(QTime debut);
    void setFin(QString fin);
    void setFin(QTime fin);

};

#endif // HEURES_H
