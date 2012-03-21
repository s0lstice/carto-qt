#ifndef DATA_GUI_H
#define DATA_GUI_H

#include <QDialog>
#include <QtGui>
#include <QtSql>

QT_BEGIN_NAMESPACE
class QDialogButtonBox;
class QPushButton;
class QSqlTableModel;
QT_END_NAMESPACE

class data_gui : public QDialog
{
    Q_OBJECT

public:
    data_gui(const QString &title,QWidget *parent = 0);

private slots:
    void submitHeures();
    void submitPoints();
    void changeHeuresView(const QModelIndex &index);

private:
    void heuresView();
    void pointsView();

    QPushButton *submitButton;
    QPushButton *revertButton;
    QPushButton *quitButton;
    QDialogButtonBox *buttonBox;
    QSqlRelationalTableModel *modelpoints;
    QSqlRelationalTableModel *modelheures;
    QTableView *viewpoints;
    QTableView *viewheures;
};

#endif
