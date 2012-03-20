#include "edit_point_gui.h"
#include "database.h"
#include <QtGui>
#include "data_categories.h"
#include "edite_categories.h"
#include "data_gui.h"

/*! met en place le model de point
    @param modelpoints : QSqlRelationalTableModel [attirbut privé] contien le model de point
    @note charge la table points dans un QSqlRelationalTableModel,
        fait la relation entre la colonne points.categorie_id et categories.categorie en fonction de categories.categorie_id.
        nome les colonnes 1 :2 3 4 de la table pour l'affichage
*/
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

}

/*! desalocation du model de point
    @param modelpoints : QSqlRelationalTableModel [attirbut priv�e] contient le model de point
*/
void edit_point_gui::delete_table_point(){
    delete modelpoints;
}

/*! met en place l'affichage des points sous forme de table
    @param table_point : QTableView : élément de edition_point.ui.
    @param submit_point : QPushButton : élément de edition_point.ui.
    @param jout_point : QPushButton : élément de edition_point.ui.
    @param supr_point : QPushButton : élément de edition_point.ui.
    @param modelpoints : QSqlRelationalTableModel [attribut privé] : contient le model de point
    @note role : \n -charge le modelpoint dans une table_point, \n
        -Masque la colonnes des identifiants, \n
        -redimentionne la colonne description en fonction de la place restante dans la vue, \n
        -met en place la gestion des bouttons ajouter, supprimer et modifier un point, \n
        -met en place la selection d'une ligne de la vue.
*/
void edit_point_gui::init_view_point(){
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
    connect(BouttonPosition,SIGNAL(clicked()),this,SLOT(position()));
    connect(jout_point,  SIGNAL(clicked()), this, SLOT(insert_point()));
    connect(supr_point,  SIGNAL(clicked()), this, SLOT(drup_point()));
    connect(table_point->selectionModel(),SIGNAL(
                currentRowChanged(const QModelIndex &,
                const QModelIndex &)),this,SLOT(select_point(const QModelIndex &)));
}

/*! met en place le mapper de point
    @param modelpoints : QSqlRelationalTableModel [attirbut privé] : contien le model de point
    @param mapperpoints : QDataWidgetMapper [attirbut privé]
    @param nom_point : QLineEdit : élément de edittion_point.ui.
    @param categorie_point : QDialogButtonBox : élément de edittion_point.ui.
    @param lat_point : QLineEdit : élément de edittion_point.ui.
    @param lon_point : QLineEdit : élément de edittion_point.ui.
    @param description_point : QPlainTextedit : élément de edittion_point.ui.
    @note roel : \n met en place la jointure entre points.categorie_id et categories.categorie ; le resultt est affiché dans la liste deroulante categorie_point,\n
        fait la relation entre les éléments de la table points et nom_point, categorie_point, lat_point, lon_point, description_point.
*/
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

/*! desalocation du mapper de point
    @param mapperpoints : QDataWidgetMapper [attirbut privé]
*/
void edit_point_gui::delete_mapper_point(){
    delete mapperpoints;
}

/*! met en place le model heure
    @param modelheures : QSqlRelationalTableModel [attirbut privé] contien le model d'heure
    @note role : \n -charge la table heures dans un QSqlRelationalTableModel,\n
        -fait la relation entre la colonne heures.jour_id et jours.jour en fonction de jours.jour_id.\n
        -nome les colonnes 2 3 4 de la table pour l'affichage \n
        -trie l'affichage en fonction des jours (dimanche, lundi, mardi, mercredi, jeudi, vendredi, sammedi).\n
*/
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

}

/*! desalocation du model heure
    @param modelheures : QSqlRelationalTableModel [attirbut privé] : contien le model d'heure
*/
void edit_point_gui::delete_table_heure(){
    delete modelheures;
}

/*! met en place l'affichage des heures sous forme de table
    @param jout_heur : QDialogButtonBox : élément de edittion_point.ui.
    @param submit_heure : QPushButton : élément de edittion_point.ui.
    @param supr_heur : QPushButton : élément de edittion_point.ui.
    @param viewheures : QTableView : élément de edittion_point.ui.
    @param modelheures : QSqlRelationalTableModel [attirbut privé] : contien le model d'heure
    @note role : \n -charge le modelheures dans une QTableView,\n
        -masque les colonnes des identifiants,\n
        -redimentionne toutes les colonnes de nmaniere homogene en fonction de la place disponible,\n
        -met en place la gestion des bouttons ajouter, supprimer et modifier une heur,\n
        -met en place la selection d'une ligne de la vue.\n
*/
void edit_point_gui::init_view_heure(){
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

/*! met en place le mapper d'heures
    @param modelheures : QSqlRelationalTableModel [attirbut privé] : contien le model d'heure
    @param mapperheures : QDataWidgetMapper [attirbut privé]
    @param jour_heur : QDialogButtonBox : élément de edittion_point.ui.
    @param debut_heur : QLineEdit : élément de edittion_point.ui.
    @param fin_heur : QLineEdit : élément de edittion_point.ui.
    @note role : \n -met en place la jointure entre heures.jour_id et jours.jour d'on le resultt est affiché dans la liste deroulante jour_heur,\n
        -fait la relation entre les element de la table points et jour_heur, debut_heur, fin_heur.
*/
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

/*! desalocation du mapper d'heure
    @param mapperheures : QDataWidgetMapper [attirbut privé]
*/
void edit_point_gui::delete_mapper_heure(){
    delete mapperheures;
}

/*! contructeur de la classe edit_point_gui
  @param point_id : int parametre optionnel, designe le point courant dès l'affichage de la fenetre.
  @param courantpoint : int [attirbut privé] : point selectionné
*/
edit_point_gui::edit_point_gui(float PosxA  ,float PosyA ,int point_id , QWidget *parent ) : QDialog(parent)
{
    setupUi(this);
    database::dataCreate();
Posx = PosxA;
Posy = PosyA;
    /*** initialisation ***/
    courantpoint = point_id;
    if(point_id != 0)
        courantpoint = point_id;

    init_table_point();
    init_view_point();
    init_mapper_point();
    init_table_heure();
    init_view_heure();
    init_mapper_heure();

    setWindowTitle(tr("Edition des points"));
}

/*! destucteur de la classe edit_point_gui
*/
edit_point_gui::~edit_point_gui(){
    delete_table_point();
    delete_mapper_point();
    delete_table_heure();
    delete_mapper_heure();
}

/*! met a jour la table points en fonction des champs modifiés
    @param modelpoints : QSqlRelationalTableModel [attirbut privé] : contien le model de point
*/
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

/*! met a jour la table heures en fonction des champs modifiés
    @param modelheures : QSqlRelationalTableModel [attirbut privé] : contien le model d'heure
    @note evenement lié a submit_heure
*/
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

/*! action lors de la selection d'une heure
    @param courantheur : int [attirbut privé] : identifiant de l'heure selectionné
    @param mapperheures : QDataWidgetMapper [attirbut privé]
    @param viewheures : QTableView : élément de edittion_point.ui.
    @param modelheures : QSqlRelationalTableModel [attirbut privé] : contien le model d'heure
    @note evenement  : lié a la selection d'une ligne dans la vue heure\n
        role : -met a jour les champs heure de la fenetre \n -stock l'identifiant de l'heure selectionné dans courantheur
*/
void edit_point_gui::select_heure(const QModelIndex &index){
    QModelIndex indexp = viewheures->currentIndex();
    indexp.row();
    mapperheures->setCurrentIndex(indexp.row());

    QSqlRecord record = modelheures->record(index.row());
    courantheur = record.value("heure_id").toInt();
}

/*! action lors de la selection d'un point
    @param courantpoint : int [attirbut privé] : identifiant du point selectionné
    @param table_point : QTableView : élément de edittion_point.ui.
    @param mapperpoints : QDataWidgetMapper [attirbut privé]
    @param modelheures : QSqlRelationalTableModel [attirbut privé] : contien le model d'heure
    @note evenement  : lié a la selection d'une ligne dans la vue heure\n
        role : -met a jour les champs point de la fenetre \n
        -stock l'identifiant du point selectionné dans courantpoint\n
        -affiche les heures corespondant a ce point.
*/
void edit_point_gui::select_point(const QModelIndex &index){
    QModelIndex indexp = table_point->currentIndex();
    mapperpoints->setCurrentIndex(indexp.row());

    QSqlRecord record = modelpoints->record(index.row());
    courantpoint = record.value("point_id").toInt();
    modelheures->setFilter(QString("point_id = %1").arg(courantpoint));

}

/*! action lors de la suppression d'un point
    @param courantpoint : int [attirbut privé] : identifiant du point selectionné
    @param modelheures : QSqlRelationalTableModel [attirbut privé] : contien le model d'heure
    @param modelpoints : QSqlRelationalTableModel [attirbut privé] : contien le model de point
    @note : evenement : lie a la suppression d'un point (supr_point)\n
        role : -supprime toutes les heures qui ont point_id comme clef etrangeres\n
        -supprime le point selectionné\n
        -réactualise le model de points\n
        -réactualise le model d'heures.
*/
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

/*! action lors de la suppression d'une heure
    @param courantpoint : int [attirbut privé] : identifiant du point selectionné
    @param modelheures : QSqlRelationalTableModel [attirbut privé] : contien le model d'heure
    @note : evenement : lie a la suppression d'une heure (supr_heure)\n
        role : -supprime l'heure selectionné\n
        -réactualise le model d'heures.
*/
void edit_point_gui::drup_heur(){
    QSqlQuery query(database::dataCreate()->dataConnect());

    if(query.exec("DELETE FROM heures WHERE heure_id = " + QString::number(courantheur)) == false)
    {
        qDebug()<< "drup_point" << query.lastError().text();
    }
    modelheures->select();
}

/*! action lors de l'ajout d'une heure
    @param courantpoint : int [attirbut privé] : identifiant du point selectionné
    @param modelheures : QSqlRelationalTableModel [attirbut privé] : contien le model d'heure
    @param modelpoint : QSqlRelationalTableModel [attirbut privé] : contien le model point
    @note : evenement : lie a l'ajout d'une heure (jout_heure)\n
        role : -ajout un champ vide a la table heures qui a pour clef etrangere l'identifiant du point courant\n
        -met a jour l'affichage des heures.
        -selectionne l'heure créé.
*/
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

/*! action lors de l'ajout d'un point
    @param courantpoint : int [attirbut privé] : identifiant du point selectionné
    @param modelpoint : QSqlRelationalTableModel [attirbut privé] : contien le model point
    @note : evenement : lie a l'ajout d'une heure (jout_point)\n
        role : -ajout un champ vide a la table points\n
        -met a jour l'affichage des points.
        -selectionne le points créé.
*/
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

/*! action lors de la modification d'une heure
    @param debut_heur : QLineEdit : élément de edittion_point.ui.
    @note : role : verifier que le format ecrit soit le bon.
*/
void edit_point_gui::on_debut_heur_editingFinished()
{
    QRegExp exp ("^[0-9][0-9]:[0-9][0-9]$");
    if(exp.exactMatch(debut_heur->text()) == false){
        QMessageBox::warning(this, tr("Erreur"),
                             tr("l'heure doit etre sous la forme suivante HH:mm"));
        debut_heur->setText("00:00");
    }
}

/*! action lors de la modification d'une heure
    @param fin_heur : QLineEdit : élément de edittion_point.ui.
    @note : role : verifier que le format ecrit soit le bon.
*/
void edit_point_gui::on_fin_heur_editingFinished()
{
    QRegExp exp ("^[0-9][0-9]:[0-9][0-9]$");
    if(exp.exactMatch(fin_heur->text()) == false){
        QMessageBox::warning(this, tr("Erreur"),
                             tr("l'heur doit etre sous la forme suivante HH:mm"));
        fin_heur->setText("00:00");
    }
}


/*! ajout/modification de categorie(s)
    @note role :-fait appelle a la classe edite_categories pour afficher la fenetre d'edition\n
        -regenre la table, le mapper et la vue des points pour prendre en compte les modifications.
*/
void edit_point_gui::on_categorie_point_but_clicked()
{
    edite_categories window;
    window.exec();

    //reactualisation de la base de donné
    delete_table_point();
    delete_mapper_point();

    init_table_point();
    init_view_point();
    init_mapper_point();
    init_view_heure();
}


void edit_point_gui::position()
{

    lon_point->setValue(Posx);
    lat_point->setValue(Posy);

}
