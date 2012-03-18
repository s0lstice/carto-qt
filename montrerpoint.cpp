#include "montrerpoint.h"
#include "ui_montrerpoint.h"

MontrerPoint::MontrerPoint(POI PointDInteret,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MontrerPoint)
{
    ui->setupUi(this);
    ui->lineEdit->setText(PointDInteret.GetCat());
    ui->lineEdit_2->setText(PointDInteret.GetName());
    ui->lineEdit_3->setText(QString::number(PointDInteret.Getlat()));
    ui->lineEdit_4->setText(QString::number(PointDInteret.Getlon()));
    ui->plainTextEdit->appendPlainText(PointDInteret.GetDesc());
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
   QPen* pointpen = new QPen(QColor(0,255,0));
   pointpen->setWidth(3);

   CirclePoint* PointA = new  CirclePoint(PointDInteret.Getlat(),PointDInteret.Getlon(),PointDInteret.GetName(),Point::Middle,pointpen);
   mainlayer->addGeometry(PointA);
   mainlayer->setVisible(false);
   mainlayer->setVisible(true);
   connect(ui->BouttonFermer,SIGNAL(clicked()),this,SLOT(close()));


}

MontrerPoint::~MontrerPoint()
{
    delete ui;
}
