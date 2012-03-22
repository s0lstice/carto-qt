/**
 * \file heure.h
 * \brief Classe permetant de contenir toutes les informations d'une plage horaire.
 * \author Guillaume Lastecoueres & Mickael Puret
 * \version 0.1
 *
 *
 */

#ifndef HEURES_H
#define HEURES_H

#include <QString>
#include <QDate>

class heure{
private :
    int jour;
    QString debut;
    QString fin;


public:
    heure();

    void setJour(int jour);
    void setDebut(QString debut);
    void setFin(QString fin);

    int getJour();
    QString getDebut();
    QString getFin();

};

#endif // HEURES_H
