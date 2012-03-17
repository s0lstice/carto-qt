#include "carte.h"
#include "ui_carte.h"
#include <QtGui>
#include <QFormLayout>
#include <QDebug>
#include <QNetworkRequest>
#include "askdatabase.h"
#include "QtConcurrentRun"
#include "database.h"
#include "data_points.h"
#include <QtXml>
//#include <iostream>
#include <QFile>
#include <QString>
//#include "Exception"
#include "edit_point_gui.h"
#include "data_csv.h"

Carte::Carte(QWidget *parent) :QMainWindow(parent), ui(new Ui::Carte)
{
    y=0;
    cmpt=1;
    GestionnaireDeRequete = new QNetworkAccessManager();

    ui->setupUi(this);
    QVBoxLayout Temp;
    mc = new MapControl(QSize(450, 450));
    mc->showScale(true);
    mapadapter = new OSMMapAdapter();
    mainlayer = new MapLayer("OpenStreetMap-Layer", mapadapter);
    mc->addLayer(mainlayer);
    mc->setView(QPointF(2.33,48.86));
    mc->setZoom(13);
    Temp.addWidget(mc);
    ui->MapWidget->setLayout(&Temp);

    connect(ui->verticalSlider,SIGNAL(valueChanged(int)),this,SLOT(PosLabel(int)));
    connect(ui->verticalSlider,SIGNAL(valueChanged(int)),mc,SLOT(setZoom(int)));
    connect(mc,SIGNAL(viewChanged(QPointF,int)),this,SLOT(ZoomInv(QPointF,int)));
    connect(ui->actionQuitter,SIGNAL(triggered()),this,SLOT(close()));
    connect(ui->actionChoix_BDD,SIGNAL(triggered()),this,SLOT(choixBDD()));
    connect(ui->actionGestion_BDD,SIGNAL(triggered()),this,SLOT(gestionBDD()));
    connect(ui->actionExport_BDD,SIGNAL(triggered()),this,SLOT(exportCSV()));
    connect(ui->listWidget,SIGNAL(itemClicked(QListWidgetItem*)),this,SLOT(ReponseQListClick(QListWidgetItem*)));
    connect(mainlayer,SIGNAL(geometryClicked(Geometry*,QPoint)),this,SLOT(ReponseGeometryClick(Geometry*,QPoint)));

    ProtectBDD = new QMutex();
    ProtectDraw = new QMutex();
    LectureBaseDDTimer = new QTimer();
    DownloadTimer = new QTimer();
    LectureBaseDDTimer->setInterval(250);
    DownloadTimer->setInterval(250);
    connect(LectureBaseDDTimer,SIGNAL(timeout()),this,SLOT(LoadingDBBData()));
    connect(DownloadTimer,SIGNAL(timeout()),this,SLOT(DownloadAndParsage()));
    LectureBaseDDTimer->start();
    DownloadTimer->start();
}

void Carte::exportCSV(){
    export_csv();
}

void Carte::choixBDD()
{
    AskDataBase *choixFenetre = new AskDataBase();
    ProtectBDD->lock();
    database::dataDisconnect();
    ProtectBDD->unlock();
    choixFenetre->show();
    this->close();
}

void Carte::gestionBDD(){
    edit_point_gui window(1);
    window.exec();
}

void Carte::DownloadAndParsage()
{

    if(cmpt==5)
    {
    cmpt=0;
    qDebug("Start yeah");
    QString Urlp = QString("http://www.geovelo.fr/api_test.php?lon=" + QString::number(Posx) + "&lat=" + QString::number(Posy));
    QUrl url = QUrl(Urlp);
    QNetworkRequest requete(url);
    GestionnaireDeRequete->get(requete);
    connect( GestionnaireDeRequete, SIGNAL(finished(QNetworkReply*)), this, SLOT(ParserA(QNetworkReply*)));
    }

}


void Carte::AjouterPoints()
{
    int i;
    QPen* pointpen = new QPen(QColor(0,255,0));
    pointpen->setWidth(3);
    mainlayer->clearGeometries();

    for(i=0;i<VPOI.count();i++)
    {
        CirclePoint* PointA = new   CirclePoint(VPOI.value(i).Getlat(),VPOI.value(i).Getlon(),VPOI.value(i).GetName(),Point::Middle,pointpen);
        mainlayer->addGeometry(PointA);
    }
    mainlayer->setVisible(false);
    mainlayer->setVisible(true);
    free(pointpen);

}

void Carte::ZoomInv(QPointF Point,int Entier)
{
    if(zoomlevel!=Entier)
    {
    zoomlevel = Entier;
    ui->verticalSlider->setValue(Entier);
    }
    if((Posx!=Point.x())||(Posy!=Point.y()))
    {
        Posx= Point.x();
        Posy= Point.y();
    }
}

void Carte::PosLabel(int Py)
{
    ui->label->setGeometry(ui->label->x(),(((ui->verticalSlider->height()+ui->verticalSlider->y())/18)*(18-Py)),ui->label->width(),ui->label->height());
    ui->label->setText(QString::number(Py));
}

Carte::~Carte()
{
    delete ui;
}

void Carte::LoadingDBBData()
{
    int i;
    ui->progressBar->setValue(y);
    ui->listWidget->clear();
    for(i=0;i<VPOI.count();i++)
    {
        ui->listWidget->addItem(VPOI.value(i).GetName());
    }
    if((cmpt==1)&&(Posx!=PosxBak)&&(Posy!=PosyBak))
    {

        PosxBak = Posx;
        PosyBak = Posy;
        QtConcurrent::run(this,&Carte::LoadingDBBDataA);
    }
}

void Carte::LoadingDBBDataA()
{


   ProtectDraw->lock();
 ProtectBDD->lock();
   VPOI = getPointImp(Posx,Posy);
ProtectBDD->unlock();
   if(VPOI.count()!=0)
   {
       if(VPOI.value(1).GetDist()>0.01)
       {
           ProtectDraw->unlock();
           qDebug() << "download";
           cmpt = 5;
           return;
       }
        AjouterPoints();
        ProtectDraw->unlock();
   }
   else
   {
         ProtectDraw->unlock();
       qDebug() << "download";
       cmpt = 5;
       return;
   }

}

void Carte::ParserA(QNetworkReply* reponse)
{

    y=0;
    QDomDocument doc;
  //********************************
  // Read the DOM tree form file
  //********************************
    doc.setContent(reponse->readAll());
  //********************************
  // Parse the DOM tree
  //********************************
  QDomElement kml=doc.documentElement();
  QDomElement document = kml.firstChild().toElement();
  QDomElement Placemark = document.firstChild().toElement();
  QDomElement node;
  QDomElement childnode;
  //parcourt des lieux
  qDebug("Yeah");
  while(!Placemark.isNull())
  {
      POI* PointOfInterest = new POI();
      node = Placemark.firstChild().toElement();
      while(!node.isNull()){
          if(node.tagName() == "categorie"){
            PointOfInterest->SetCat(node.text());
          }
          else if(node.tagName() == "nom"){
              PointOfInterest->SetName(node.text().replace(QString("'"),QString(" "),Qt::CaseSensitive));
          }
          else if(node.tagName() == "Point"){
              childnode = node.firstChild().toElement();
              if(childnode.tagName() == "coordinates"){
                  PointOfInterest->Setlat(QString(childnode.text().split(",")[0]).toFloat());
                  PointOfInterest->Setlong(QString(childnode.text().split(",")[1]).toFloat());
                  }
          }
          node = node.nextSibling().toElement();
      }
      Placemark = Placemark.nextSibling().toElement();
      QtConcurrent::run(this,&Carte::addPointThread,PointOfInterest->GetCat(),PointOfInterest->GetName(),PointOfInterest->Getlat(),PointOfInterest->Getlon());
        free(PointOfInterest);
  }
    doc.clear();
    reponse->close();
    cmpt=1;
    qDebug("yeah Fin");
}

void Carte::addPointThread(QString categorie, QString name, float latitude, float longitude)
{
     ProtectBDD->lock();
       addPoint(categorie, name,latitude,longitude);
      ProtectBDD->unlock();
      y++;
}

void Carte::ReponseQListClick(QListWidgetItem* Item)
{
    int iterateur=0;
    MontrerPoint *MontrePointWindow;
    ProtectDraw->lock();
    for(iterateur=0;iterateur<VPOI.count();iterateur++)
    {
        if(VPOI.value(iterateur).GetName()==Item->text())
        {
          MontrePointWindow = new MontrerPoint(VPOI.value(iterateur));
           MontrePointWindow->show();
            break;
        }
    }
    ProtectDraw->unlock();

}
void Carte::ReponseGeometryClick(Geometry* geo,QPoint pt)
{
    int iterateur=0;
    MontrerPoint *MontrePointWindow;
    ProtectDraw->lock();
    for(iterateur=0;iterateur<VPOI.count();iterateur++)
    {
        if(VPOI.value(iterateur).GetName()==geo->name())
        {
          MontrePointWindow = new MontrerPoint(VPOI.value(iterateur));
         ui->listWidget->setCurrentItem( (ui->listWidget->findItems(geo->name(),Qt::MatchFlags())).value(1));
           MontrePointWindow->show();
            break;
        }
    }
    ProtectDraw->unlock();
}
