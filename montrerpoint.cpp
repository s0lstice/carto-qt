/**
 * \file montrerpoint.cpp
 * \brief Fenetre permetant la visualisation complette d'un point, position sur catre, donnees dans la base.
 * \author Guillaume Lastecoueres & Mickael Puret
 * \version 0.1
 *
 *
 */


#include "montrerpoint.h"
#include "ui_montrerpoint.h"
#include "heure.h"
#include "data_heures.h"
#include "data_jours.h"
#include <QVector>
#include "edit_point_gui.h"

/*!
  @fn MontrerPoint::MontrerPoint(POI PointDInteret,QWidget *parent) : QDialog(parent), ui(new Ui::MontrerPoint)
  @brief Construit la fenêtre et initialise les données importantes
    \param POI PointDInteret. La fenêtre va se construire en utilisant ses attributs
    \note Nous creeons un fenetre qui va afficher les attributs du point et sa position geographique, pour se faire on initialise les champs de la fenêtre avec chaque attributs
    Pour l'affichage de l'heure nous créeons une table et nous récuperons les heures du points à l'aide d'une requete sur la base de donnée.
*/

MontrerPoint::MontrerPoint(POI PointDInteret,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MontrerPoint)
{

    // On initialise les champs avec les attributs du POI passé en paramêtre
    ui->setupUi(this);
    ui->lineEdit->setText(PointDInteret.GetCat());
    ui->lineEdit_2->setText(PointDInteret.GetName());
    ui->lineEdit_3->setText(QString::number(PointDInteret.Getlat()));
    ui->lineEdit_4->setText(QString::number(PointDInteret.Getlon()));
    ui->plainTextEdit->appendPlainText(PointDInteret.GetDesc());

    // On dessine une carte sur laquel nous allons ajouter un point

    QVBoxLayout Temp;
     mc = new MapControl(QSize(211  , 280));
    mc->showScale(true);
   mapadapter = new OSMMapAdapter();
   mainlayer = new MapLayer("OpenStreetMap-Layer", mapadapter);
   mc->addLayer(mainlayer);
   mc->setView(QPointF(PointDInteret.Getlat(),PointDInteret.Getlon()));
   mc->setZoom(13);
   Temp.addWidget(mc);
   ui->widget->setLayout(&Temp);

   // On dessine le point sur la carte

   QPen* pointpen = new QPen(QColor(0,255,0));
   pointpen->setWidth(3);

   CirclePoint* PointA = new  CirclePoint(PointDInteret.Getlat(),PointDInteret.Getlon(),PointDInteret.GetName(),Point::Middle,pointpen);
   mainlayer->addGeometry(PointA);
   mainlayer->setVisible(false);
   mainlayer->setVisible(true);

   // On connecte le boutton quitter à l'evenemnt fermer
   connect(ui->BouttonFermer,SIGNAL(clicked()),this,SLOT(close()));
   connect(ui->BouttonModification,SIGNAL(clicked()),this,SLOT(modification()));
    PointDInteretA = PointDInteret;
   // Création de la table et recuperation des heurs ainsi que l'affichage de celles-ci
   ui->tableWidget->setHorizontalHeaderItem(0,new QTableWidgetItem("Jour"));
   ui->tableWidget->setHorizontalHeaderItem(1,new QTableWidgetItem("Debut"));
   ui->tableWidget->setHorizontalHeaderItem(2,new QTableWidgetItem("Fin"));

   QVector<heure>Horaires = getHeureByPoint(PointDInteret.GetId());
   int i = 0;
   qDebug()<<"Reussite 1";
   for(i=0;i<Horaires.count();i++)
   {
        ui->tableWidget->insertRow(i);
        ui->tableWidget->setRowCount(i+1);
        ui->tableWidget->setItem(i,0,new QTableWidgetItem(jourById(Horaires.value(i).getJour())));
        ui->tableWidget->setItem(i,1,new QTableWidgetItem(Horaires.value(i).getDebut()));
        ui->tableWidget->setItem(i,2,new QTableWidgetItem(Horaires.value(i).getFin()));
   }


}
void MontrerPoint::modification()
{
    edit_point_gui art(PointDInteretA.Getlat(),PointDInteretA.Getlon(),PointDInteretA.GetId());
    qDebug()<< "n°" << PointDInteretA.GetId();
    art.exec();

}

MontrerPoint::~MontrerPoint()
{
    delete ui;
}
