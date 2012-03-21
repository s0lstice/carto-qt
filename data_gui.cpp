#include <QtGui>
#include <QtSql>

#include "data_gui.h"
#include "database.h"
#include "data_jours.h"

void data_gui::pointsView(){
    /*** table points ***/
    modelpoints = new QSqlRelationalTableModel();
    modelpoints->setTable("points");
    modelpoints->setEditStrategy(QSqlTableModel::OnManualSubmit);
    modelpoints->setRelation(2, QSqlRelation("categories", "ROWID", "categorie"));

    modelpoints->setHeaderData(1, Qt::Horizontal, tr("name"));
    modelpoints->setHeaderData(2, Qt::Horizontal, tr("categorie"));
    modelpoints->setHeaderData(3, Qt::Horizontal, tr("latitude"));
    modelpoints->setHeaderData(4, Qt::Horizontal, tr("longitude"));

    modelpoints->select();

    viewpoints = new QTableView;
    viewpoints->setModel(modelpoints);
    viewpoints->setItemDelegate(new QSqlRelationalDelegate(viewpoints));
    viewpoints->setColumnHidden(0, true);
    //viewpoints->resizeColumnsToContents();

    /*calcule de la largeur de chaque collone plus de la barre d'entete avec + 2 pour les marges*/
    /*car adjustesize ne marche pas sur les QTableView*/
    int width = 2 + viewpoints->verticalHeader()->width() +
            viewpoints->columnWidth(1) +
            viewpoints->columnWidth(2) +
            viewpoints->columnWidth(3) +
            viewpoints->columnWidth(4) +
            viewpoints->columnWidth(5);
    viewpoints->setFixedWidth(width);
}

void data_gui::changeHeuresView(const QModelIndex &index){
    /*** table heures ***/
    QSqlRecord record = modelpoints->record(index.row());
    int id = record.value("point_id").toInt();
    modelheures->setFilter(QString("point_id = %1").arg(id));
}

void data_gui::heuresView(){
    /*** table heures ***/

    modelheures = new QSqlRelationalTableModel();
    modelheures->setTable("heures");
    modelheures->setEditStrategy(QSqlTableModel::OnManualSubmit);
    modelpoints->setRelation(0, QSqlRelation("categories", "ROWID", "categorie"));
    modelheures->setHeaderData(2, Qt::Horizontal, tr("Joure"));
    modelheures->setHeaderData(3, Qt::Horizontal, tr("Ouverture"));
    modelheures->setHeaderData(4, Qt::Horizontal, tr("Fermeture"));
    modelheures->setSort(2,Qt::AscendingOrder);
    modelheures->select();

    viewheures = new QTableView;
    viewheures->setModel(modelheures);
    viewheures->setItemDelegate(new QSqlRelationalDelegate(viewheures));
    viewheures->setColumnHidden(0, true);
    viewheures->setColumnHidden(1, true);

    /*calcule de la largeur de chaque collone plus de la barre d'entete avec + 2 pour les marges*/
    /*car adjustesize ne marche pas sur les QTableView*/
    int width = 2 + viewheures->verticalHeader()->width() +
            viewheures->columnWidth(1) +
            viewheures->columnWidth(2) +
            viewheures->columnWidth(3) +
            viewheures->columnWidth(4);
    viewheures->setFixedWidth(width);

}

data_gui::data_gui(const QString &title, QWidget *parent) : QDialog(parent)
{
    database::dataCreate();

    pointsView();
    heuresView();

    /*** boutons et connection ***/
    QPushButton *submitButton = new QPushButton(tr("Submit"));
    submitButton->setDefault(true);
    QPushButton *revertButton = new QPushButton(tr("&Revert"));
    QPushButton *quitButton = new QPushButton(tr("Quit"));

    QDialogButtonBox *buttonBox = new QDialogButtonBox(Qt::Horizontal);
    buttonBox->addButton(submitButton, QDialogButtonBox::ActionRole);
    buttonBox->addButton(revertButton, QDialogButtonBox::ActionRole);
    buttonBox->addButton(quitButton, QDialogButtonBox::RejectRole);

    connect(submitButton, SIGNAL(clicked()), this, SLOT(submitHeures()));
    connect(submitButton, SIGNAL(clicked()), this, SLOT(submitPoints()));
    connect(revertButton, SIGNAL(clicked()), modelpoints, SLOT(revertAll()));
    connect(revertButton, SIGNAL(clicked()), modelheures, SLOT(revertAll()));
    connect(quitButton, SIGNAL(clicked()), this, SLOT(close()));
    connect(viewpoints->selectionModel(),SIGNAL(currentRowChanged(const QModelIndex &,
                                                const QModelIndex &)),this,SLOT(changeHeuresView(const QModelIndex &)));

    /***cadre de la fenetre ***/
    QVBoxLayout *rightLayout = new QVBoxLayout();
    rightLayout->addWidget(buttonBox);
    rightLayout->addWidget(viewheures);

    QHBoxLayout *mainLayout = new QHBoxLayout;
    mainLayout->addWidget(viewpoints);
    mainLayout->addLayout(rightLayout);
    setLayout(mainLayout);
    setWindowTitle(title);
}

void data_gui::submitPoints(){
 modelpoints->database().transaction();
     if (modelpoints->submitAll()) {
         modelpoints->database().commit();
     } else {
         modelpoints->database().rollback();
         QMessageBox::warning(this, tr("Erreur"),
                              tr("L'opperation de mise a jour de la table de points a rencontre une erreur : %1")
                              .arg(modelpoints->lastError().text()));
     }

}

void data_gui::submitHeures()
{
    modelheures->database().transaction();
    if (modelheures->submitAll()) {
        modelheures->database().commit();
    } else {
        modelheures->database().rollback();
        QMessageBox::warning(this, tr("Erreur"),
                             tr("L'opperation de mise a jour de la table des heures a rencontre une erreur : %1")
                             .arg(modelheures->lastError().text()));
    }
}
