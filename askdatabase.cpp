#include "askdatabase.h"
#include "ui_askdatabase.h"
#include "carte.h"
#include "QDebug"
#include "database.h"
#include "data_categories.h"
#include <QSettings>
#include <string>

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

void AskDataBase::CreateFile(void)
{


    qDebug()<<"CartoTag6";
    filename= ui->comboBox->currentText().remove(".db");
    qDebug()<<"CartoTag7";
    database::dataCreate(filename);
    qDebug()<<"CartoTag8";
    database::dataCreate()->dataCreate();
    qDebug()<<"CartoTag9";
    int i = 0 ;
    qDebug()<<"CartoTag10";
    QStringList Categories;
    qDebug()<<"CartoTag11";
    QSettings settings("CartoTeam", "Cartographe");
    qDebug()<<"CartoTag12";
    Categories.append(settings.value("Categories").toStringList());
    qDebug()<<"CartoTag13";
    for(i=0;i<Categories.count();i++)
    {
        addCategorie(Categories.value(i));
    }
    Carte * WCarte = new Carte();
    WCarte->show();

    this->close();
}

void AskDataBase::ValidateFile(void)
{

    Carte * WCarte = new Carte();

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


        WCarte->show();
        this->close();
}

