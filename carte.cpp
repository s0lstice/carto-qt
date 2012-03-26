/**
 * \file carte.cpp
 * \brief Fenetre principale de l'application
 * \author Guillaume Lastecoueres & Mickael Puret
 * \version 0.1
 *
 * permet la visualisation de la carte, la selection et le filtrage de points. Son menu permet le parametrage de la base de donnee et le changement de langue
 *
 */
/*! \class Carte carte.cpp
  \brief fentere principale de l'application
*/

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
#include "application.h"
#include <QSettings>
#include "data_categories.h"
#include "data_jours.h"
#include "data_heures.h"



/*!
  @fn Carte::Carte(QWidget *parent) :QMainWindow(parent), ui(new Ui::Carte)
  @brief constructeur de la fenêtre principale
  @note info : Dans ce constructeur de nombreuses choses se passe.
  Premierement il y a initialisation d'un gestionnaire d'acces reseau qui servira plus tard au telechargement du fichier kml chez geovelo.
  On met dans le widget de l'interface de la carte le QMapControl.
  On centre la carte sur paris en zoomant dessus
  Nous connectons tous les élements de l'interface aux fonctions correpondantes.
  Nous démarrons le timer qui sert à l'actualisation de la carte.
  Nous initialisons les différentes tables de la base de données.
*/
Carte::Carte(QWidget *parent) :QMainWindow(parent), ui(new Ui::Carte)
{

    cmpt=1;
    GestionnaireDeRequete = new QNetworkAccessManager();
    ui->setupUi(this);
    QVBoxLayout Temp;
    mc = new MapControl(QSize(480, 480));
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
    connect(ui->actionAnglais,SIGNAL(triggered()),this,SLOT(langue_englais()));
    connect(ui->actionFrancais,SIGNAL(triggered()),this,SLOT(langue_francais()));
    connect(ui->comboBox,SIGNAL(currentIndexChanged(int)),this,SLOT(ByCat(int)));
    //connect(ui->actionExport_BDD,SIGNAL(triggered()),this,SLOT(exportCSV()));
    connect(ui->lineEdit,SIGNAL(textChanged(QString)),this,SLOT(Chercher(QString)));
    connect(mainlayer,SIGNAL(geometryClicked(Geometry*,QPoint)),this,SLOT(ReponseGeometryClick(Geometry*,QPoint)));
    connect(ui->BouttonCentrer,SIGNAL(clicked()),this,SLOT(Centrer()));
    connect(ui->AutoDownLoad,SIGNAL(stateChanged(int)),this,SLOT(AutoTelcharger(int)));
    connect(ui->BouttonTelecharger,SIGNAL(clicked()),this,SLOT(Telecharger()));
    ui->comboBox->addItem("");
    LectureBaseDDTimer = new QTimer();
    LectureBaseDDTimer->setInterval(50);
    LectureBaseDDTimer->start();
    connect(LectureBaseDDTimer,SIGNAL(timeout()),this,SLOT(LoadingDBBData()));
    ui->spinBox->setValue(10);
    nbpstoshow = 10 ;
    int i ;
    initPointsTable();
    initCategoriesTable();
    initJoursTable();
    initHeuresTable();
    DLenable=false;

    QVector<QString> Categories = getCategories();

    for(i=0;i<Categories.count();i++)
    {
        if(ui->comboBox->findText(Categories.value(i))==-1)
        {
            ui->comboBox->addItem(Categories.value(i));
        }
    }
}

/*!
  @fn void Carte::Telecharger()
  @brief Fonction permettant le telechargement du fichier KML
  @note info :Dans cette fonction nous créons une url à partir des coordonnées de la carte.
  Puis nous executons une requête get pour rappatrier le fichier.
  Une fois fais nous appelons la fonction ParserA
*/
void Carte::Telecharger()
{
    downloading = true;
    QString Urlp = QString("http://www.geovelo.fr/api_test.php?lon=" + QString::number(Posx) + "&lat=" + QString::number(Posy));
    QUrl url = QUrl(Urlp);
    QNetworkRequest requete(url);
    GestionnaireDeRequete->get(requete);
    connect( GestionnaireDeRequete, SIGNAL(finished(QNetworkReply*)), this, SLOT(ParserA(QNetworkReply*)));

}

/*!
  @fn void Carte::AutoTelcharger(int LvL)
  @brief Fonction qui permet d'activer ou non l'autotelechargement
  @param int LvL valeur prise par la checkBox
  @note info : En fonction de la valeur renvoyé lors du clic sur la checkbox
  nous activons la variable DLenable ou non. Cette variable permet d'autotelecharger des points
*/
void Carte::AutoTelcharger(int LvL)
{
    if(LvL!=2)
    {
        DLenable=false;
    }
    else
    {
        DLenable=true;
    }
}

void Carte::langue_englais(){
    Carte * WCarte = new Carte();
    QTranslator translator;
    translator.load("langue_en");
    application *app = application::appInit();
    app->installTranslator(&translator);
    WCarte->show();
    this->close();
}


void Carte::langue_francais(){
    Carte * WCarte = new Carte();
    QTranslator translator;
    translator.load("langue_fr");
    application *app = application::appInit();
    app->installTranslator(&translator);
     WCarte->show();
    this->close();
}



/*!
  @fn void Carte::exportCSV()
  @brief Fonction qui permet l'export de la BDD sous la forme d'un fichier .csv
  @note info : Ouverture d'un explorateur de fichier. Suivit par l'appel de la fonction d'export au format csv
*/
void Carte::exportCSV(){
    QString File = QFileDialog::getSaveFileName(this, tr("export"), ".", tr("csv (*.csv"));

    if (!File.isEmpty())
         {
                 export_csv(File);
         }

}

/*!
  @fn void Carte::choixBDD()
  @brief Fonction qui permet d'appeler la fenêtre de selection de BDD
  @note info : Nous deconnectons la BDD actuellement utilisé puis nous ouvrons la fenêtre de selection de BDD
*/
void Carte::choixBDD()
{
    AskDataBase *choixFenetre = new AskDataBase();

    database::dataDisconnect();

    choixFenetre->show();
    this->close();
}

/*!
  @fn void Carte::Centrer()
  @brief Fonction qui centre la vue de la carte sur le point selectionné dans la liste des points
  @note info : Nous parcourons les points dans le Vecteur de point de façon à recuperer les coordonnées du point séléctionné puis nous appliquons ses coordonnées à la carte
*/
void Carte::Centrer()
{

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

}


/*!
  @fn void Carte::gestionBDD()
  @brief Fonction qui ouvre la fenêtre de gestion de la BDD
  @note info : Nous fournissons les coordonnées actuelles à la fenêtre de façon  à permettre de créer un point avec les coordonnées de la carte.
  Cmpt = 9 signifie que lors du prochain appel au compteur il faudra actualiser la liste des catégories.
*/
void Carte::gestionBDD(){
    edit_point_gui art(Posx,Posy,0,0);
    art.exec();
    cmpt=9;
}

/*!
  @fn void Carte::AjouterPoints()
  @brief Fonction qui dessine les points sur la carte et ajoute le nom des points dans la listes des points.
  @note info : Pour pouvoir économiser la ressource processeur. Nous desactivons l'actualisation de la liste lorsqu'on la peuple de cette façon elle n'essaye pas de s'actualiser à chaque fois que nous ajoutons un point.
  Nous supprimons ensuite les points de la carte pour déssiner les nouveaux.
  Pour finir nous desactivons activons la visibilité de la carte pour actualisé le layer Mainlayer.
*/
void Carte::AjouterPoints()
{
    int i;
    ui->listWidget->clear();
    ui->listWidget->setUpdatesEnabled(false);
    for(i=0;i<VPOI.count();i++)
    {
        ui->listWidget->addItem(VPOI.value(i).GetName());
    }
    ui->listWidget->setUpdatesEnabled(true);
    QPen* pointpen = new QPen(QColor(0,127,255));
    mainlayer->clearGeometries();
    pointpen->setWidth(3);
    for(i=0;i<VPOI.count();i++)
    {
        CirclePoint* PointA = new   CirclePoint(VPOI.value(i).Getlat(),VPOI.value(i).Getlon(),VPOI.value(i).GetName(),Point::Middle,pointpen);
        mainlayer->addGeometry(PointA);

    }
    free(pointpen);
    mainlayer->setVisible(false);
    mainlayer->setVisible(true);

}

/*!
  @fn void Carte::ZoomInv(QPointF Point,int Entier)
  @brief Cette fonction permet d'acualiser le slider vertical lorsqu'on zoom sur la carte
   @param QPointF Point , int Entier. Entier represente le niveau de zoom Point represente les coordonnées
  @note info : Nous verifions que le niveau de zoom est différents de la valeur du slider vertical cela evite une boucle infinie
*/
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
/*!
  @fn void Carte::PosLabel(int Py)
  @brief Cette fonction permet de deplacer le chiffre indiquant le niveau de zoom au niveau du curseur du slider
   @param int Py permet le calcul de la position du label
*/
void Carte::PosLabel(int Py)
{
    ui->label->setGeometry(ui->label->x(),(((ui->verticalSlider->height()+ui->verticalSlider->y())/18)*(18-Py)),ui->label->width(),ui->label->height());
    ui->label->setText(QString::number(Py));
}


/*!
  @fn Carte::~Carte()
  @brief libere les ressources de la fenetre contenant la carte
*/
Carte::~Carte()
{
    delete ui;
}



/*!
  @fn void Carte::LoadingDBBData()
  @brief Cette fonction est appelé lorsque le timer atteint son temps
  @note info: Cette fonction qui est appelé tout les ticks du timer permet de faire tourner le programme
  Premierement il met à jour la barre de chargement avec la variable y.
  Deuxiémement il regarde la valeur de cmpt et determine ce qu'il doit faire.
  Si cmpt = 1 alors il regarde si les coordonnées ont changé. Si oui il va simplement mettre à jour les coordonnées et afficher les points.
  Si cmpt = 10 cela signifie que même si la vue n'a pas changé il doit mettre à jour les points c'est ce qu'il fait
  si cmpt = 9 alors il y a potentiellement eu des changements dans les categories il faut donc mettre à jour les categories
  si cmpt = 5 alors cela signifie qu'il n'y a pas de points suffisament proche. Si il y a le telechargement auto alors il va telecharger de nouveaux points.
*/
void Carte::LoadingDBBData()
{

    int i;
    if(y<101)
    {
        ui->progressBar->setValue(y);
    }
    else
    {
        y=y-100;
    }
    if(((cmpt==1)&&(Posx!=PosxBak)&&(Posy!=PosyBak))||(cmpt>=5))
    {
        if(cmpt==10)
        {
                cmpt=1;
                AjouterPoints();
                return;
        }
        if(cmpt==9)
        {
            qDebug("9");
            QVector<QString> Categories = getCategories();
                for(i=0;i<Categories.count();i++)
                {
                    if(ui->comboBox->findText(Categories.value(i))==-1)
                    {
                        ui->comboBox->addItem(Categories.value(i));
                    }
                }
                cmpt =1;
        }
        if((cmpt==5)&&(downloading==false)&&(DLenable==true))
        {
            Telecharger();
        }
         PosxBak = Posx;
         PosyBak = Posy;

         AjouterPoints();
          QtConcurrent::run(this,&Carte::LoadingDBBDataA);
    }
}



/*!
  @fn void Carte::LoadingDBBDataA()
  @brief Cette fonction est lancé dans un thread à partir de LoadingDBBData
  @note info: Cette fonction récupére des points dans la base de données à partir des coordonnées de la croix sur la carte puis il regarde.
  Si il n'y a pas de point il met cmpt = 5 pour le telechargement de nouveaux points
  Si la distance est trop elevé par rapport à la position de la croix sur la carte alors il met aussi cmpt = 5 pour amorcer un telechargement
  Sinon il demande l'actualisation des points.
*/
void Carte::LoadingDBBDataA()
{
   VPOI.clear();
   VPOI = getPointImp(Posx,Posy,nbpstoshow,ui->lineEdit->text(),ui->comboBox->currentText());
   if(VPOI.count()!=0)
   {
       if(VPOI.value(1).GetDist()>0.00005)
       {
            cmpt = 5 ;
           return;
       }
       cmpt=10;
      return;
   }
   else
   {
       cmpt=5;
       return;
   }
}


/*!
  @fn void Carte::ParserA(QNetworkReply* reponse)
  @brief Cette fonction est lancé lorsque l'on a récuperé le fichier kml. Il le parse puis ajoute les points dans la BDD.
  @note info: Ce fonction parse donc le fichier kml puis lorsqu'il a recupere les informations d'un point il lance un thread qui a pour but de l'ajouter dans la base de donnees.
  A la fin de l'ajout il met cmpt=10 pour pouvoir actualiser la liste des points.
*/
void Carte::ParserA(QNetworkReply* reponse)
{
    QDomDocument doc;
    y=0;

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
    downloading=false;
}


/*!
  @fn void Carte::addPointThread(QString categorie, QString name, float latitude, float longitude)
  @brief Cette fonction permet tout simplement d'ajouter un point dans la base de données.
  @param QString categorie, QString name, float latitude, float longitude representent les données du point que l'on veut ajouter.
  @note note : On ajoute dans la base de données à l'aide d'un thread car c'est l'operation qui prend le plus de temps et qui peut donc empecher l'utilisateur de se deplacer. On met cmpt = 10 pour informer que l'on souhaite mettre à jour les points et y++ pour incrémenter la barre de progrés.
*/
void Carte::addPointThread(QString categorie, QString name, float latitude, float longitude)
{
       addPoint(categorie, name,latitude,longitude);
       cmpt = 10;
       y++;
}


/*!
  @fn void Carte::ReponseQListClick(QListWidgetItem* Item)
  @brief Cette fonction permet d'afficher une fenêtre lorsqu'on double cliquesur un element dans la liste des points.
  @param QListWidgetItem* Item represente l'item sur lequel on à cliqué.
  @note note : on recherche le point avec le même nom que l'objet sur lequel on a clique cela permet d'afficher une fenetre qui donne les informations sur le point
*/
void Carte::ReponseQListClick(QListWidgetItem* Item)
{
    int iterateur=0;
    MontrerPoint *MontrePointWindow;
    for(iterateur=0;iterateur<VPOI.count();iterateur++)
    {
        if(VPOI.value(iterateur).GetName()==Item->text())
        {
          MontrePointWindow = new MontrerPoint(VPOI.value(iterateur));
          MontrePointWindow->exec();
          return;
        }
    }
}

/*!
  @fn void Carte::ModifNbPoint(int nbpoints)
  @brief Cette fonction change la variable qui indique le nombre de points à afficher.
  @param int nbpoints indique la valeur du nombre de points à afficher

*/
void Carte::ModifNbPoint(int nbpoints)
{
     nbpstoshow = nbpoints;
     VPOI.clear();
     VPOI=getPointImp(Posx,Posy,nbpstoshow,ui->lineEdit->text(),ui->comboBox->currentText());
     cmpt=10;
}


/*!
  @fn void Carte::ReponseGeometryClick(Geometry* geo,QPoint pt)
  @brief Cette fonction permet d'afficher une fenêtre lorsqu'on clique sur un element de la carte.
  @param Geometry* geo,QPoint pt representent l'objet ainsi que ses coordonnées
  @note note : on recherche le point avec le même nom que l'objet sur lequel on a clique cela permet d'afficher une fenetre qui donne les informations sur le point
*/
void Carte::ReponseGeometryClick(Geometry* geo,QPoint pt)
{
    int iterateur=0;
    MontrerPoint *MontrePointWindow;
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
}


/*!
  @fn void Carte::Chercher(QString Chaine)
  @brief Cette fonction permet de filtrer les points par la chaine de recherche
  @param QString Chaine est la chaine tapé par l'utilisateur

*/
void Carte::Chercher(QString Chaine)
{
    VPOI.clear();
    VPOI=getPointImp(Posx,Posy,nbpstoshow,Chaine,ui->comboBox->currentText());
    cmpt=10;
}

/*!
  @fn void Carte::Chercher(int i)
  @brief Cette fonction permet de filtrer les points par categorie
  @param int i est la categorie choisie

*/
void Carte::ByCat(int i)
{
    VPOI.clear();
    VPOI=getPointImp(Posx,Posy,nbpstoshow,ui->lineEdit->text(),ui->comboBox->currentText());
    cmpt=10;
}
