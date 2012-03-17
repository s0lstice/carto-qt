#include "edite_categories.h"
#include "database.h"

#include <QtGui>
edite_categories::edite_categories(QWidget *parent) : QDialog(parent)
{
    database::dataCreate();

    courantCategorie = 1;
    QLabel * attention = new QLabel;
    attention->setText(tr("Attention :\n La suppression d'une categorie en cours d'utilisation\n rendra les donnees inutilisables !"));

    edite_categorie = new QSqlTableModel;
    edite_categorie->setTable("categories");
    edite_categorie->setHeaderData(1, Qt::Horizontal, tr("categorie"));
    edite_categorie->select();

    viewCategories = new QTableView;
    viewCategories->setModel(edite_categorie);
    viewCategories->setItemDelegate(new QSqlRelationalDelegate(this));
    viewCategories->setColumnHidden(0, true);

    viewCategories->resize(350, 100);
    viewCategories->setColumnWidth(1, viewCategories->width());

    editButton = new QPushButton(tr("&Modifier"));
    addButton = new QPushButton(tr("&Ajouter"));
    deletButton = new QPushButton(tr("&Supprimer"));

    buttonBox = new QDialogButtonBox(Qt::Horizontal);
    buttonBox->addButton(editButton, QDialogButtonBox::ActionRole);
    buttonBox->addButton(addButton, QDialogButtonBox::ActionRole);
    buttonBox->addButton(deletButton, QDialogButtonBox::ActionRole);

    mainLayout = new QVBoxLayout;
    mainLayout->addWidget(attention);
    mainLayout->addWidget(viewCategories);
    mainLayout->addWidget(buttonBox);

    connect(editButton, SIGNAL(clicked()), this, SLOT(submitCategorie()));
    connect(deletButton, SIGNAL(clicked()), this, SLOT(drup_categorie()));
    connect(addButton, SIGNAL(clicked()), this, SLOT(insert_categorie()));
    connect(viewCategories->selectionModel(),SIGNAL(
                currentRowChanged(const QModelIndex &,
                const QModelIndex &)),this,SLOT(select_categorie(const QModelIndex &)));

    setLayout(mainLayout);
}

void edite_categories::select_categorie(const QModelIndex &index){
    QSqlRecord record = edite_categorie->record(index.row());
    courantCategorie = record.value("categorie_id").toInt();
}

void edite_categories::drup_categorie(){
    QSqlQuery query(database::dataCreate()->dataConnect());

    if(query.exec("DELETE FROM categories WHERE categorie_id = " + QString::number(courantCategorie)) == false)
    {
        qDebug()<< "drup_categorie" << query.lastError().text();
    }

    edite_categorie->select();
}

void edite_categories::insert_categorie(){
    QSqlQuery query(database::dataCreate()->dataConnect());

    if(query.exec("insert into categories(categorie) values('')") == false)
    {
        qDebug()<< "insert_categorie" << query.lastError().text();
    }

    edite_categorie->select();

    courantCategorie = edite_categorie->data(edite_categorie->index(edite_categorie->rowCount() -1, 0)).toInt();
    viewCategories->selectRow(courantCategorie);
}

void edite_categories::submitCategorie(){

    edite_categorie->database().transaction();
    if (edite_categorie->submitAll()) {
        edite_categorie->database().commit();
    } else {
        edite_categorie->database().rollback();
        QMessageBox::warning(this, tr("Erreur"),
                             tr("L'opperation de mise a jour de la table de points a rencontre une erreur : %1")
                             .arg(edite_categorie->lastError().text()));
    }
}
