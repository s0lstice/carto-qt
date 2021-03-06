/**
 * \file carte.h
 * \brief Fenetre principale de l'application
 * \author Guillaume Lastecoueres & Mickael Puret
 * \version 0.1
 *
 * permet la visualisation de la carte, la selection et le filtrage de points. Son menu permet le parametrage de la base de donnee et le changement de langue
 *
 */

#ifndef CARTE_H
#define CARTE_H

#include <QtGui>
#include <QMapControl/qmapcontrol.h>
#include <QSlider>
#include <QNetworkReply>
#include "database.h"
#include <QTimer>
#include "montrerpoint.h"

using namespace qmapcontrol;
namespace Ui {
    class Carte;
}

class Carte : public QMainWindow
{
    Q_OBJECT

public:
    explicit Carte(QWidget *parent = 0);
    ~Carte();
private:
    Ui::Carte *ui;
    MapControl* mc;
    MapAdapter* mapadapter;
    Layer* mainlayer;
    QNetworkAccessManager* GestionnaireDeRequete ;
    void DessinerPoint(QPointF Ptf);
    float Posx;
    int zoomlevel;
    int y;
    float Posy;
    float PosxBak;
    float PosyBak;
    CirclePoint* PointA;
    QTimer * LectureBaseDDTimer;
    bool DLenable;
    int cmpt;
    int nbpstoshow;
    void LoadingDBBDataA();
    QMutex * ProtectBDD;
    QMutex * ProtectDraw;
    QVector<POI> VPOI;
    void Parser(QNetworkReply *reponse);
    void addPointThread(QString categorie, QString name, float latitude, float longitude);
    bool downloading;

private slots:
    void Chercher(QString Chaine);
    void AjouterPoints();
    void ZoomInv(QPointF,int);
    void PosLabel(int);
    void choixBDD();
    void gestionBDD();
    void LoadingDBBData();
    void ParserA(QNetworkReply *reponse);
    void ReponseQListClick(QListWidgetItem* Item);
    void ReponseGeometryClick(Geometry*,QPoint);
    void ModifNbPoint(int nbpoints);
    void Centrer();
    void ByCat(int i );
    void langue_englais();
    void langue_francais();
    void Telecharger();
    void AutoTelcharger(int LvL);
    void exportCSV();
};



#endif // CARTE_H
