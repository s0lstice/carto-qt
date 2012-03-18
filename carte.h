#ifndef CARTE_H
#define CARTE_H

#include <QtGui>
#include <QMapControl/qmapcontrol.h>
#include <QSlider>
#include <QNetworkReply>
#include "Parseur.h"
#include "database.h"
#include <QTimer>
#include <QMutex>
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
    QTimer * DownloadTimer;
    int cmpt;
    int nbpstoshow;
    void LoadingDBBDataA();
    QMutex * ProtectBDD;
    QMutex * ProtectDraw;
    QVector<POI> VPOI;
    void Parser(QNetworkReply *reponse);
    void addPointThread(QString categorie, QString name, float latitude, float longitude);

private slots:
    void Chercher(QString Chaine);
    void AjouterPoints();
    void ZoomInv(QPointF,int);
    void PosLabel(int);
    void choixBDD();
    void gestionBDD();
    void DownloadAndParsage();
    void LoadingDBBData();
    void ParserA(QNetworkReply *reponse);
    void ReponseQListClick(QListWidgetItem* Item);
    void ReponseGeometryClick(Geometry*,QPoint);
    void ModifNbPoint(int nbpoints);
    void Centrer();
    void ByCat(int i );


    void exportCSV();
};



#endif // CARTE_H
