/**
 * \file askdatabase.h
 * \brief Fenetre de gestion des bases de donnees, permet de choisir ou creer une nouvelle base
 * \author Guillaume Lastecoueres & Mickael Puret
 * \version 0.1
 *
 * La creation ou la selection d'une base de donné necessite la selection de son emplacement. La creation necessite de creer toutes les table de la base.
 *
 */

#ifndef ASKDATABASE_H
#define ASKDATABASE_H

#include <QMainWindow>
#include <QString>
#include <QtGui>

namespace Ui {
    class AskDataBase;
}

class AskDataBase : public QMainWindow
{
    Q_OBJECT

public:
    explicit AskDataBase(QWidget *parent = 0);
    ~AskDataBase();

private:
    Ui::AskDataBase *ui;
    void CreationCarte();
    QString filename;
private slots:
    void SelectFile(void);
    void CreateFile(void);
    void ValidateFile(void);


};

#endif // ASKDATABASE_H
