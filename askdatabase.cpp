#include "askdatabase.h"
#include "ui_askdatabase.h"
#include "carte.h"
#include "QDebug"
#include "database.h"

AskDataBase::AskDataBase(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AskDataBase)
{
    ui->setupUi(this);

    connect(ui->pushButton_3,SIGNAL(clicked()),this,SLOT(close()));
    connect(ui->pushButton_2,SIGNAL(clicked()),this,SLOT(ValidateFile()));
    connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(CreateFile()));
    connect(ui->pushButton_4,SIGNAL(clicked()),this,SLOT(SelectFile()));
    // On remplit une QStringList avec chacun des filtres désirés
    // On sélectionne le répertoire à partir duquel on va rechercher les fichiers .db
    QString MyAppDirPath =  QCoreApplication::applicationDirPath();
    QStringList listFilter;
    listFilter << "*.db";
    QDir *DirA = new QDir(MyAppDirPath);
    QStringList FIL = DirA->entryList(listFilter);
    int i = 0;
    for(i=0;i<FIL.count();i++)
    {
        qDebug("File found");
        ui->comboBox->addItem(FIL[i]);
    }
    free(DirA);
}

AskDataBase::~AskDataBase()
{
    delete ui;
}

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

void AskDataBase::CreateFile(void)
{

    CreationCarte();
    this->close();
}

void AskDataBase::ValidateFile(void)
{
    CreationCarte();
    this->close();
}

void AskDataBase::CreationCarte(){
    Carte * WCarte = new Carte();
    filename= ui->comboBox->currentText().remove(".db");
    database::dataCreate(filename);
    WCarte->show();
}

