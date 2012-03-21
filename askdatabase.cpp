#include "askdatabase.h"
#include "ui_askdatabase.h"
#include "carte.h"
#include "QDebug"
#include "database.h"
#include "data_categories.h"
#include <QSettings>
#include <string>


/*! Construit la fenêtre et initialise les données importantes

    \note Cette fenêtre que nous allons créer est faite pour permettre à l'utilisateur de choisir une base de donnée.
    Il y a 4 bouttons :
    -pushbutton_3 permet de quitter
    -pushbutton_2 permet de creer ou selectionner une BDD
    -pushbutton permet de creer ou selectionner une BDD
    -pushbutton_4 permet d'ouvrir un explorateur pour choisir un fichier

    Deplus la fenêtre liste tout les fichiers en .db dans son repertoire.
*/

AskDataBase::AskDataBase(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AskDataBase)
{
    ui->setupUi(this);
    qDebug()<<"CartoTag";
    connect(ui->pushButton_3,SIGNAL(clicked()),this,SLOT(close()));
    connect(ui->pushButton_2,SIGNAL(clicked()),this,SLOT(ValidateFile()));
    connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(CreateFile()));
    connect(ui->pushButton_4,SIGNAL(clicked()),this,SLOT(SelectFile()));
 qDebug()<<"CartoTag2";
    QString MyAppDirPath =  QCoreApplication::applicationDirPath();
    QStringList listFilter;
    listFilter << "*.db";
    QDir *DirA = new QDir(MyAppDirPath);
    QStringList FIL = DirA->entryList(listFilter);
    int i = 0;
    for(i=0;i<FIL.count();i++)
    {
        ui->comboBox->addItem(FIL[i]);
    }
    free(DirA);
 qDebug()<<"CartoTag3";
}

AskDataBase::~AskDataBase()
{
    delete ui;
}


/*! Creer une fenêtre qui permet la selection d'un fichier .

    \note Une fois la selection faite on met automatiquement dans la combobox le fichier qui vient d'être selectionné.
*/
void AskDataBase::SelectFile(void)
{
     qDebug()<<"CartoTag4";
    QString File = QFileDialog::getOpenFileName(this,tr("Choisir base de donnée"), QDir::currentPath(), tr("Database files (*.db)"));

    if (!File.isEmpty())
         {
             if (ui->comboBox->findText(File) == -1)
                 ui->comboBox->addItem(File);
                 ui->comboBox->setCurrentIndex(ui->comboBox->findText(File));
         }
     qDebug()<<"CartoTag5";
}

/*! Cree ou recupere une BDD puis lance la feetre principale.
    \note Dans les faits la recuperation ou la creation de la base de donnée se fait à l'appel de datacreate on récupére aussi les catagories qui ont été sauvergardé dans les QSettings.

*/
void AskDataBase::CreateFile(void)
{
    filename= ui->comboBox->currentText().remove(".db");
    database::dataCreate(filename)->initTable();
    int i = 0 ;
    QStringList Categories;
    QSettings settings("CartoTeam", "Cartographe");
    Categories.append(settings.value("Categories").toStringList());
    for(i=0;i<Categories.count();i++)
    {
        addCategorie(Categories.value(i));
    }
    Carte * WCarte = new Carte();
    WCarte->show();
    this->close();
}

/*! Cree ou recupere une BDD puis lance la feetre principale.
    \note Dans les faits la recuperation ou la creation de la base de donnée se fait à l'appel de datacreate on récupére aussi les catagories qui ont été sauvergardé dans les QSettings.
*/
void AskDataBase::ValidateFile(void)
{



        filename= ui->comboBox->currentText().remove(".db");
        database::dataCreate(filename);

        int i = 0 ;
        QStringList Categories;
        QSettings settings("CartoTeam", "Cartographe");
        Categories.append(settings.value("Categories").toStringList());
        for(i=0;i<Categories.count();i++)
        {
            addCategorie(Categories.value(i));
        }

        Carte * WCarte = new Carte();
        WCarte->show();
        this->close();
}

