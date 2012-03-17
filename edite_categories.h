#ifndef EDITE_CATEGORIES_H
#define EDITE_CATEGORIES_H

#include <QDialog>
#include <QtGui>
#include <QtSql>

QT_BEGIN_NAMESPACE
class QDialogButtonBox;
class QPushButton;
class QSqlTableModel;
QT_END_NAMESPACE

class edite_categories: public QDialog
{
    Q_OBJECT
public:
    edite_categories(QWidget *parent = 0);

private slots :
    void submitCategorie();
    void select_categorie(const QModelIndex &index);
    void drup_categorie();
    void insert_categorie();

private :
    QSqlTableModel *edite_categorie;
    QTableView *viewCategories;
    QPushButton *editButton;
    QPushButton *addButton;
    QPushButton *deletButton;
    QDialogButtonBox *buttonBox;
    QVBoxLayout *mainLayout;
    int courantCategorie;
};

#endif // EDITE_CATEGORIES_H
