#include "edit_point_gui.h"
#include "database.h"
#include <QtGui>
#include "data_categories.h"
#include "edite_categories.h"

#include "data_gui.h"

void edit_point_gui::init_table_point(){

    /*** table points ***/
    modelpoints = new QSqlRelationalTableModel();
    modelpoints->setTable("points");
    modelpoints->setEditStrategy(QSqlTableModel::OnManualSubmit);
    modelpoints->setRelation(2, QSqlRelation("categories", "categorie_id", "categorie"));
    modelpoints->setHeaderData(1, Qt::Horizontal, tr("name"));
    modelpoints->setHeaderData(2, Qt::Horizontal, tr("categorie"));
    modelpoints->setHeaderData(3, Qt::Horizontal, tr("latitude"));
    modelpoints->setHeaderData(4, Qt::Horizontal, tr("longitude"));
    modelpoints->select();

    //viewpoints = new QTableView;
    table_point->setModel(modelpoints);
    table_point->setItemDelegate(new QSqlRelationalDelegate(this));
    table_point->setColumnHidden(0, true);
    table_point->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    /*calcule de la largeur de chaque collone plus de la barre d'entete avec + 2 pour les marges*/
    /*car adjustesize ne marche pas sur les QTableView*/
    int width =  table_point->width() - (table_point->verticalHeader()->width() +
            table_point->columnWidth(1) +
            table_point->columnWidth(2) +
            table_point->columnWidth(3) +
            table_point->columnWidth(4) +
            table_point->columnWidth(5)); //<- largeur a rajouter
    table_point->setColumnWidth(5, table_point->columnWidth(5) + width -2);

    connect(submit_point,  SIGNAL(clicked()), this, SLOT(submitPoints()));
    connect(jout_point,  SIGNAL(clicked()), this, SLOT(insert_point()));
    connect(supr_point,  SIGNAL(clicked()), this, SLOT(drup_point()));
    connect(table_point->selectionModel(),SIGNAL(
                currentRowChanged(const QModelIndex &,
                const QModelIndex &)),this,SLOT(select_point(const QModelIndex &)));

}
void edit_point_gui::delete_table_point(){
    delete modelpoints;
}

void edit_point_gui::init_mapper_point(){
    /*** affichage de la partie point ***/

    QSqlTableModel *relModelCategorie = modelpoints->relationModel(2);
    categorie_point->setModel(relModelCategorie);
    categorie_point->setModelColumn(relModelCategorie->fieldIndex("categorie"));

    mapperpoints = new QDataWidgetMapper(this);
    mapperpoints->setModel(modelpoints);
    mapperpoints->setItemDelegate(new QSqlRelationalDelegate(this));
    mapperpoints->addMapping(nom_point, modelpoints->fieldIndex("name"));
    mapperpoints->addMapping(categorie_point, 2);//modelpoints->fieldIndex("categorie_id")
    mapperpoints->addMapping(lat_point, modelpoints->fieldIndex("latitude"));
    mapperpoints->addMapping(lon_point, modelpoints->fieldIndex("longitude"));
    mapperpoints->addMapping(description_point, modelpoints->fieldIndex("description"));
    mapperpoints->toFirst();
}
void edit_point_gui::delete_mapper_point(){
    delete mapperpoints;
}

void edit_point_gui::init_table_heure(){
    /*** affichage des heures ***/
    modelheures = new QSqlRelationalTableModel(this);
    modelheures->setTable("heures");
    modelheures->setEditStrategy(QSqlTableModel::OnManualSubmit);
    modelheures->setRelation(modelheures->fieldIndex("jour"), QSqlRelation("jours", "jour_id", "jour"));
    modelheures->select();

    modelheures->setHeaderData(2, Qt::Horizontal, tr("Jour"));
    modelheures->setHeaderData(3, Qt::Horizontal, tr("Ouverture"));
    modelheures->setHeaderData(4, Qt::Horizontal, tr("Fermeture"));
    modelheures->setSort(2,Qt::AscendingOrder);

    /*** affichage du tableau ***/
    viewheures->setModel(modelheures);
    viewheures->setItemDelegate(new QSqlRelationalDelegate(this));
    viewheures->setColumnHidden(0, true);
    viewheures->setColumnHidden(1, true);
    viewheures->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    /*calcule de la largeur de chaque collone plus de la barre d'entete avec + 2 pour les marges*/
    /*car adjustesize ne marche pas sur les QTableView*/
    int width =  viewheures->width() - (viewheures->verticalHeader()->width() +
            viewheures->columnWidth(2) +
            viewheures->columnWidth(3) +
            viewheures->columnWidth(4));
    width/=3; //<- largeur a rajouter
    viewheures->setColumnWidth(2, viewheures->columnWidth(2) + width);
    viewheures->setColumnWidth(3, viewheures->columnWidth(3) + width);
    viewheures->setColumnWidth(4, viewheures->columnWidth(4) + width -1);

    connect(jout_heur,  SIGNAL(clicked()), this, SLOT(insert_heur()));
    connect(submit_heure, SIGNAL(clicked()), this, SLOT(submitHeure()));
    connect(supr_heur,  SIGNAL(clicked()), this, SLOT(drup_heur()));
    connect(viewheures->selectionModel(),SIGNAL(
                currentRowChanged(const QModelIndex &,
                const QModelIndex &)),this,SLOT(select_heure(const QModelIndex &)));
}
void edit_point_gui::delete_table_heure(){
    delete modelheures;
}

void edit_point_gui::init_mapper_heure(){
    /*** gestion des heures (ajout : suppression) ***/

    QSqlTableModel *relModelJour = modelheures->relationModel(modelheures->fieldIndex("jour"));
    jour_heur->setModel(relModelJour);
    jour_heur->setModelColumn(relModelJour->fieldIndex("jour"));

    mapperheures = new QDataWidgetMapper(this);
    mapperheures->setModel(modelheures);
    mapperheures->setItemDelegate(new QSqlRelationalDelegate(this));
    mapperheures->addMapping(jour_heur, modelheures->fieldIndex("jour"));
    mapperheures->addMapping(debut_heur, modelheures->fieldIndex("debut"));
    mapperheures->addMapping(fin_heur, modelheures->fieldIndex("fin"));
    mapperheures->toFirst();
}

void edit_point_gui::delete_mapper_heure(){
    delete mapperheures;
}

edit_point_gui::edit_point_gui(int point_id, QWidget *parent) : QDialog(parent)
{
    setupUi(this);
    database::dataCreate();

    /*** initialisation ***/
    courantpoint = point_id;
    if(point_id != 0)
        courantpoint = point_id;

    init_table_point();
    init_mapper_point();
    init_table_heure();
    init_mapper_heure();

    setWindowTitle(tr("Edition des points"));
}

edit_point_gui::~edit_point_gui(){
    delete_table_point();
    delete_mapper_point();
    delete_table_heure();
    delete_mapper_heure();
}

void edit_point_gui::submitPoints()
{
    modelpoints->database().transaction();
    if (modelpoints->submitAll()) {
        modelpoints->database().commit();
    } else {
        modelpoints->database().rollback();
        QMessageBox::warning(this, tr("Erreur"),
                             tr("L'opperation de mise a jour de la table des heures a rencontre une erreur : %1")
                             .arg(modelpoints->lastError().text()));
    }
}

void edit_point_gui::submitHeure(){

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

void edit_point_gui::select_heure(const QModelIndex &index){
    /*** table heures ***/
    QModelIndex indexp = viewheures->currentIndex();
    indexp.row();
    mapperheures->setCurrentIndex(indexp.row());

    QSqlRecord record = modelheures->record(index.row());
    courantheur = record.value("heure_id").toInt();
}

void edit_point_gui::select_point(const QModelIndex &index){
    /*** table point ***/
    QModelIndex indexp = table_point->currentIndex();
    mapperpoints->setCurrentIndex(indexp.row());

    /***table heur***/
    QSqlRecord record = modelpoints->record(index.row());
    courantpoint = record.value("point_id").toInt();
    modelheures->setFilter(QString("point_id = %1").arg(courantpoint));

}

void edit_point_gui::drup_point(){
    QSqlQuery query(database::dataCreate()->dataConnect());

    if(query.exec("DELETE FROM heures WHERE point_id = " + QString::number(courantpoint)) == false)
    {
        qDebug()<< "drup_point" << query.lastError().text();
    }

    if(query.exec("DELETE FROM points WHERE point_id = " + QString::number(courantpoint)) == false)
    {
        qDebug()<< "drup_point" << query.lastError().text();
    }
    modelpoints->select();
    modelheures->select();
}

void edit_point_gui::drup_heur(){
    QSqlQuery query(database::dataCreate()->dataConnect());

    if(query.exec("DELETE FROM heures WHERE heure_id = " + QString::number(courantheur)) == false)
    {
        qDebug()<< "drup_point" << query.lastError().text();
    }
    modelheures->select();
}

void edit_point_gui::insert_heur(){
    QSqlQuery query(database::dataCreate()->dataConnect());

    if(courantpoint != 0)
        if(query.exec("insert into heures(point_id, jour, debut, fin) values(" + QString::number(courantpoint) + ", 1, '00:00', '00:00')") == false)
        {
            qDebug()<< "insert_heur" << query.lastError().text();
        }
    courantheur = modelheures->data(modelheures->index(modelheures->rowCount() -1, 0)).toInt();
    modelheures->select();

}

void edit_point_gui::insert_point(){
    QSqlQuery query(database::dataCreate()->dataConnect());

    if(courantpoint != 0)
        if( query.exec("insert into points(latitude, longitude, categorie_id ) values(0, 0, 1)") == false)
        {
            qDebug()<< "insert_point" << query.lastError().text();
        }
    courantpoint = modelpoints->data(modelpoints->index(modelpoints->rowCount() -1, 0)).toInt();
    modelpoints->select();
}

void edit_point_gui::on_debut_heur_editingFinished()
{
    QRegExp exp ("^[0-9][0-9]:[0-9][0-9]$");
    if(exp.exactMatch(debut_heur->text()) == false){
        QMessageBox::warning(this, tr("Erreur"),
                             tr("l'heur doit etre sous la forme suivante HH:mm"));
    }
}

void edit_point_gui::on_fin_heur_editingFinished()
{
    QRegExp exp ("^[0-9][0-9]:[0-9][0-9]$");
    if(exp.exactMatch(fin_heur->text()) == false){
        QMessageBox::warning(this, tr("Erreur"),
                             tr("l'heur doit etre sous la forme suivante HH:mm"));
    }
}

void edit_point_gui::on_debut_heur_selectionChanged()
{
    QRegExp exp ("^[0-9][0-9]:[0-9][0-9]$");
    if(exp.exactMatch(debut_heur->text()) == false){
        QMessageBox::warning(this, tr("Erreur"),
                             tr("l'heur doit etre sous la forme suivante HH:mm"));
    }
}

void edit_point_gui::on_fin_heur_selectionChanged()
{
    QRegExp exp ("^[0-9][0-9]:[0-9][0-9]$");
    if(exp.exactMatch(fin_heur->text()) == false){
        QMessageBox::warning(this, tr("Erreur"),
                             tr("l'heur doit etre sous la forme suivante HH:mm"));
    }
}

void edit_point_gui::on_categorie_point_but_clicked()
{
    edite_categories window;
    window.exec();

    //reactualisation de la base de donné
    delete_table_point();
    delete_mapper_point();

    init_table_point();
    init_mapper_point();
}
