/**
 * \file askdatabase.cpp
 * \brief Fenetre de gestion des bases de donnees, permet de choisir ou creer une nouvelle base
 * \author Guillaume Lastecoueres & Mickael Puret
 * \version 0.1
 *
 * La creation ou la selection d'une base de donné necessite la selection de son emplacement. La creation necessite de creer toutes les table de la base.
 *
 */

#include "askdatabase.h"
#include "ui_askdatabase.h"
#include "carte.h"
#include "QDebug"
#include "database.h"
#include "data_categories.h"
#include <QSettings>
#include <string>


/*!
  @brief Construit la fenêtre et initialise les données importantes
    @fn AskDataBase::AskDataBase(QWidget *parent) : QMainWindow(parent), ui(new Ui::AskDataBase)
    \note Cette fenêtre que nous allons créer est faite pour permettre à l'utilisateur de choisir une base de donnée.\n
    Il y a 4 bouttons :\n
    -pushbutton_3 permet de quitter\n
    -pushbutton_2 permet de creer ou selectionner une BDD\n
    -pushbutton permet de creer ou selectionner une BDD\n
    -pushbutton_4 permet d'ouvrir un explorateur pour choisir un fichier\n

    Deplus la fenêtre liste tout les fichiers en .db dans son repertoire.\n
*/

AskDataBase::AskDataBase(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AskDataBase)
{
    ui->setupUi(this);
    connect(ui->pushButton_3,SIGNAL(clicked()),this,SLOT(close()));
    connect(ui->pushButton_2,SIGNAL(clicked()),this,SLOT(ValidateFile()));
    connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(CreateFile()));
    connect(ui->pushButton_4,SIGNAL(clicked()),this,SLOT(SelectFile()));
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
}

AskDataBase::~AskDataBase()
{
    delete ui;
}


/*!
  @fn void AskDataBase::SelectFile(void)

  @brief Creer une fenêtre qui permet la selection d'un fichier .

    \note Une fois la selection faite on met automatiquement dans la combobox le fichier qui vient d'être selectionné.
*/
void AskDataBase::SelectFile(void)
{

    QString File = QFileDialog::getOpenFileName(this,tr("Choisir base de donnée"), QDir::currentPath(), tr("Database files (*.db)"));

    if (!File.isEmpty())
         {
             if (ui->comboBox->findText(File) == -1)
                 ui->comboBox->addItem(File);
                 ui->comboBox->setCurrentIndex(ui->comboBox->findText(File));
         }

}

/*!
    @fn void AskDataBase::CreateFile(void)

    @brief Cree ou recupere une BDD puis lance la feetre principale.
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

/*!
  @fn void AskDataBase::ValidateFile(void)

  @brief Cree ou recupere une BDD puis lance la feetre principale.
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

