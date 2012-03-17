#include "heure.h"

heure::heure(){}
void heure::setJour(int jour){
    this->jour = jour;
}

void heure::setDebut(QString debut){
    this->debut = QTime::fromString(debut, "hh:mm:ss");
}

void heure::setDebut(QTime debut){
    this->debut = debut;
}

void heure::setFin(QString fin){
    this->fin = QTime::fromString(fin, "hh:mm:ss");
}

void heure::setFin(QTime fin){
    this->fin = fin;
}

