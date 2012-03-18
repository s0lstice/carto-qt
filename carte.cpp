#include "carte.h"
#include "ui_carte.h"
#include <QtGui>
#include <QFormLayout>
#include <QNetworkRequest>
#include "askdatabase.h"
#include "QtConcurrentRun"
#include "database.h"
#include "data_points.h"
#include <QtXml>
#include <QFile>
#include <QString>
#include "edit_point_gui.h"
#include "data_csv.h"
#include <QSettings>


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
    connect(ui->spinBox,SIGNAL(valueChanged(int)),this,SLOT(ModifNbPoint(int)));
    connect(ui->verticalSlider,SIGNAL(valueChanged(int)),this,SLOT(PosLabel(int)));
    connect(ui->verticalSlider,SIGNAL(valueChanged(int)),mc,SLOT(setZoom(int)));
    connect(mc,SIGNAL(viewChanged(QPointF,int)),this,SLOT(ZoomInv(QPointF,int)));
    connect(ui->actionQuitter,SIGNAL(triggered()),this,SLOT(close()));
    connect(ui->actionChoix_BDD,SIGNAL(triggered()),this,SLOT(choixBDD()));
    connect(ui->actionGestion_BDD,SIGNAL(triggered()),this,SLOT(gestionBDD()));
    connect(ui->listWidget,SIGNAL(itemDoubleClicked(QListWidgetItem*)),this,SLOT(ReponseQListClick(QListWidgetItem*)));
    connect(ui->actionExport_BDD,SIGNAL(triggered()),this,SLOT(exportCSV()));
    connect(ui->lineEdit,SIGNAL(textChanged(QString)),this,SLOT(Chercher(QString)));
    connect(ui->listWidget,SIGNAL(itemDoubleClicked(QListWidgetItem*)),this,SLOT(ReponseQListClick(QListWidgetItem*)));
    connect(mainlayer,SIGNAL(geometryClicked(Geometry*,QPoint)),this,SLOT(ReponseGeometryClick(Geometry*,QPoint)));
    connect(ui->BouttonCentrer,SIGNAL(clicked()),this,SLOT(Centrer()));


    ProtectBDD = new QMutex();
    ProtectDraw = new QMutex();
    LectureBaseDDTimer = new QTimer();
    DownloadTimer = new QTimer();
    LectureBaseDDTimer->setInterval(50);
    DownloadTimer->setInterval(250);
    connect(LectureBaseDDTimer,SIGNAL(timeout()),this,SLOT(LoadingDBBData()));
    connect(DownloadTimer,SIGNAL(timeout()),this,SLOT(DownloadAndParsage()));
    LectureBaseDDTimer->start();
    DownloadTimer->start();
    ui->spinBox->setValue(10);
    nbpstoshow = 10 ;



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

void Carte::Centrer()
{
    ProtectDraw->lock();
    int i = 0 ;
    if(ui->listWidget->selectedItems().count()==1)
    {
        if(VPOI.count()>0)
        {
            for(i=0;i<VPOI.count();i++)
            {
                 if(VPOI.value(i).GetName()==ui->listWidget->selectedItems().value(0)->text())
                 {
                      mc->setView(QPointF(VPOI.value(i).Getlat(),VPOI.value(i).Getlon()));
                 }
            }
        }
    }
    ProtectDraw->unlock();
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
    mainlayer->setVisible(false);
    mainlayer->clearGeometries();

    for(i=0;i<VPOI.count();i++)
    {
        CirclePoint* PointA = new   CirclePoint(VPOI.value(i).Getlat(),VPOI.value(i).Getlon(),VPOI.value(i).GetName(),Point::Middle,pointpen);
        mainlayer->addGeometry(PointA);

    }

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

    if(((cmpt==1)&&(Posx!=PosxBak)&&(Posy!=PosyBak))||(cmpt==10))
    {

        if(cmpt==10)
        {
            cmpt=1;
            ui->listWidget->clear();
            ui->listWidget->setUpdatesEnabled(false);
            for(i=0;i<VPOI.count();i++)
            {
                ui->listWidget->addItem(VPOI.value(i).GetName());
            }
            ui->listWidget->setUpdatesEnabled(true);
            AjouterPoints();
            return;
        }
        PosxBak = Posx;
        PosyBak = Posy;

        QtConcurrent::run(this,&Carte::LoadingDBBDataA);

    }
}

void Carte::LoadingDBBDataA()
{

   ProtectDraw->lock();

   if(ui->lineEdit->text()=="")
   {
   ProtectBDD->lock();
   VPOI.clear();
   VPOI = getPointImp(Posx,Posy,nbpstoshow);
   ProtectBDD->unlock();
   }

   if(VPOI.count()!=0)
   {
       if(VPOI.value(1).GetDist()>0.00005)
       {
           ProtectDraw->unlock();
           qDebug() << "download";
           cmpt = 5;
           return;
       }
        cmpt=10;
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
    cmpt=10;
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

   void Carte::ModifNbPoint(int nbpoints)
   {
        nbpstoshow = nbpoints;
        cmpt=10;

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

void Carte::Chercher(QString Chaine)
{
    VPOI.clear();
    VPOI=getPointByName(Chaine.replace(QString("'"),QString(" ")),nbpstoshow);
    cmpt=10;

}
