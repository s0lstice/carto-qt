#ifndef EDITION_POINT_GUI_H
#define EDITION_POINT_GUI_H

#include <QDialog>
#include "ui_edition_point.h"

QT_BEGIN_NAMESPACE
class QComboBox;
class QDataWidgetMapper;
class QItemSelectionModel;
class QLabel;
class QLineEdit;
class QPushButton;
class QSqlRelationalTableModel;
class QStandardItemModel;
class QStringListModel;
class QTextEdit;
QT_END_NAMESPACE

class edit_point_gui: public QDialog, public Ui::edit_point
{
    Q_OBJECT

public:
    //edit_point_gui(QWidget *parent = 0);
    edit_point_gui(int point_id = 0, QWidget *parent = 0);
    ~edit_point_gui();

private slots:
    void select_point(const QModelIndex &index);
    void select_heure(const QModelIndex &index);
    void drup_point();
    void drup_heur();
    void insert_point();
    void insert_heur();
    void submitHeure();
    void submitPoints();
    void on_fin_heur_editingFinished();
    void on_debut_heur_editingFinished();

    void on_debut_heur_selectionChanged();

    void on_fin_heur_selectionChanged();

    void on_categorie_point_but_clicked();

private:
    void init_table_point();
    void init_view_point();
    void init_mapper_point();
    void init_table_heure();
    void init_view_heure();
    void init_mapper_heure();

    void delete_table_point();
    void delete_mapper_point();
    void delete_table_heure();
    void delete_mapper_heure();

    QSqlRelationalTableModel *modelpoints;
    QItemSelectionModel *selectionModel;
    QDataWidgetMapper *mapperpoints;
    QDataWidgetMapper *mapperheures;
    QSqlRelationalTableModel *modelheures;
    int courantpoint;
    int courantheur;
};

#endif // EDITION_POINT_GUI_H
