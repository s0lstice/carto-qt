/**
 * \file heure.h
 * \brief Classe permetant de contenir toutes les informations d'une plage horaire.
 * \author Guillaume Lastecoueres & Mickael Puret
 * \version 0.1
 *
 *
 */
/*! \class heure heure.cpp
  \brief contient toutes les informations sur une plage horaire
*/

#include "heure.h"
#include <QDebug>

heure::heure(){}
void heure::setJour(int jour){
    this->jour = jour;
}

int heure::getJour(){
    return jour;
}

void heure::setDebut(QString debut){
    this->debut = debut;
}

QString heure::getDebut(){
    return debut;
}

void heure::setFin(QString fin){
    this->fin = fin;
}


QString heure::getFin(){
    return fin;
}


