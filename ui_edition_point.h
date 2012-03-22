/********************************************************************************
** Form generated from reading UI file 'edition_point.ui'
**
** Created: Thu 22. Mar 06:45:07 2012
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDITION_POINT_H
#define UI_EDITION_POINT_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPlainTextEdit>
#include <QtGui/QPushButton>
#include <QtGui/QTableView>

QT_BEGIN_NAMESPACE

class Ui_edit_point
{
public:
    QGroupBox *Point;
    QLineEdit *nom_point;
    QLabel *point_name_lab;
    QLabel *categorie_point_lab;
    QComboBox *categorie_point;
    QLabel *lat_point_lab;
    QDoubleSpinBox *lat_point;
    QLabel *Lon_point_lab;
    QDoubleSpinBox *lon_point;
    QLabel *decription_point_lab;
    QPlainTextEdit *description_point;
    QPushButton *categorie_point_but;
    QPushButton *BouttonPosition;
    QGroupBox *heures_point_box;
    QTableView *viewheures;
    QLabel *jour_heur_lab;
    QComboBox *jour_heur;
    QLabel *plage_heur;
    QLabel *label;
    QPushButton *jout_heur;
    QPushButton *supr_heur;
    QPushButton *submit_heure;
    QLineEdit *debut_heur;
    QLineEdit *fin_heur;
    QGroupBox *groupBox;
    QPushButton *supr_point;
    QPushButton *jout_point;
    QTableView *table_point;
    QPushButton *submit_point;

    void setupUi(QDialog *edit_point)
    {
        if (edit_point->objectName().isEmpty())
            edit_point->setObjectName(QString::fromUtf8("edit_point"));
        edit_point->resize(831, 519);
        Point = new QGroupBox(edit_point);
        Point->setObjectName(QString::fromUtf8("Point"));
        Point->setGeometry(QRect(10, 190, 411, 321));
        Point->setFlat(false);
        nom_point = new QLineEdit(Point);
        nom_point->setObjectName(QString::fromUtf8("nom_point"));
        nom_point->setGeometry(QRect(92, 30, 311, 27));
        point_name_lab = new QLabel(Point);
        point_name_lab->setObjectName(QString::fromUtf8("point_name_lab"));
        point_name_lab->setGeometry(QRect(10, 36, 91, 16));
        categorie_point_lab = new QLabel(Point);
        categorie_point_lab->setObjectName(QString::fromUtf8("categorie_point_lab"));
        categorie_point_lab->setGeometry(QRect(10, 66, 81, 17));
        categorie_point = new QComboBox(Point);
        categorie_point->setObjectName(QString::fromUtf8("categorie_point"));
        categorie_point->setGeometry(QRect(92, 60, 141, 27));
        lat_point_lab = new QLabel(Point);
        lat_point_lab->setObjectName(QString::fromUtf8("lat_point_lab"));
        lat_point_lab->setGeometry(QRect(10, 97, 91, 17));
        lat_point = new QDoubleSpinBox(Point);
        lat_point->setObjectName(QString::fromUtf8("lat_point"));
        lat_point->setGeometry(QRect(92, 91, 141, 27));
        lat_point->setDecimals(5);
        lat_point->setMinimum(-100);
        lat_point->setMaximum(100);
        Lon_point_lab = new QLabel(Point);
        Lon_point_lab->setObjectName(QString::fromUtf8("Lon_point_lab"));
        Lon_point_lab->setGeometry(QRect(10, 127, 91, 17));
        lon_point = new QDoubleSpinBox(Point);
        lon_point->setObjectName(QString::fromUtf8("lon_point"));
        lon_point->setGeometry(QRect(92, 122, 141, 27));
        lon_point->setDecimals(5);
        lon_point->setMinimum(-100);
        lon_point->setMaximum(100);
        decription_point_lab = new QLabel(Point);
        decription_point_lab->setObjectName(QString::fromUtf8("decription_point_lab"));
        decription_point_lab->setGeometry(QRect(10, 160, 81, 17));
        description_point = new QPlainTextEdit(Point);
        description_point->setObjectName(QString::fromUtf8("description_point"));
        description_point->setGeometry(QRect(93, 154, 311, 161));
        categorie_point_but = new QPushButton(Point);
        categorie_point_but->setObjectName(QString::fromUtf8("categorie_point_but"));
        categorie_point_but->setGeometry(QRect(240, 60, 161, 30));
        BouttonPosition = new QPushButton(Point);
        BouttonPosition->setObjectName(QString::fromUtf8("BouttonPosition"));
        BouttonPosition->setGeometry(QRect(240, 106, 161, 30));
        heures_point_box = new QGroupBox(edit_point);
        heures_point_box->setObjectName(QString::fromUtf8("heures_point_box"));
        heures_point_box->setGeometry(QRect(420, 190, 401, 331));
        viewheures = new QTableView(heures_point_box);
        viewheures->setObjectName(QString::fromUtf8("viewheures"));
        viewheures->setGeometry(QRect(10, 30, 381, 191));
        jour_heur_lab = new QLabel(heures_point_box);
        jour_heur_lab->setObjectName(QString::fromUtf8("jour_heur_lab"));
        jour_heur_lab->setGeometry(QRect(10, 230, 131, 17));
        jour_heur = new QComboBox(heures_point_box);
        jour_heur->setObjectName(QString::fromUtf8("jour_heur"));
        jour_heur->setGeometry(QRect(120, 225, 261, 27));
        plage_heur = new QLabel(heures_point_box);
        plage_heur->setObjectName(QString::fromUtf8("plage_heur"));
        plage_heur->setGeometry(QRect(10, 260, 101, 17));
        plage_heur->setFrameShape(QFrame::NoFrame);
        label = new QLabel(heures_point_box);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(250, 260, 16, 17));
        jout_heur = new QPushButton(heures_point_box);
        jout_heur->setObjectName(QString::fromUtf8("jout_heur"));
        jout_heur->setGeometry(QRect(10, 290, 121, 27));
        supr_heur = new QPushButton(heures_point_box);
        supr_heur->setObjectName(QString::fromUtf8("supr_heur"));
        supr_heur->setGeometry(QRect(150, 290, 121, 27));
        submit_heure = new QPushButton(heures_point_box);
        submit_heure->setObjectName(QString::fromUtf8("submit_heure"));
        submit_heure->setGeometry(QRect(290, 290, 111, 27));
        debut_heur = new QLineEdit(heures_point_box);
        debut_heur->setObjectName(QString::fromUtf8("debut_heur"));
        debut_heur->setGeometry(QRect(120, 257, 113, 27));
        fin_heur = new QLineEdit(heures_point_box);
        fin_heur->setObjectName(QString::fromUtf8("fin_heur"));
        fin_heur->setGeometry(QRect(269, 257, 113, 27));
        groupBox = new QGroupBox(edit_point);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(10, 10, 811, 181));
        supr_point = new QPushButton(groupBox);
        supr_point->setObjectName(QString::fromUtf8("supr_point"));
        supr_point->setGeometry(QRect(670, 80, 121, 27));
        jout_point = new QPushButton(groupBox);
        jout_point->setObjectName(QString::fromUtf8("jout_point"));
        jout_point->setGeometry(QRect(670, 40, 121, 27));
        table_point = new QTableView(groupBox);
        table_point->setObjectName(QString::fromUtf8("table_point"));
        table_point->setGeometry(QRect(10, 20, 641, 151));
        submit_point = new QPushButton(groupBox);
        submit_point->setObjectName(QString::fromUtf8("submit_point"));
        submit_point->setGeometry(QRect(670, 120, 121, 27));

        retranslateUi(edit_point);

        QMetaObject::connectSlotsByName(edit_point);
    } // setupUi

    void retranslateUi(QDialog *edit_point)
    {
        edit_point->setWindowTitle(QApplication::translate("edit_point", "Dialog", 0, QApplication::UnicodeUTF8));
        Point->setTitle(QApplication::translate("edit_point", "Donn\303\251es du point :", 0, QApplication::UnicodeUTF8));
        nom_point->setText(QString());
        point_name_lab->setText(QApplication::translate("edit_point", "Nom :", 0, QApplication::UnicodeUTF8));
        categorie_point_lab->setText(QApplication::translate("edit_point", "Categorie :", 0, QApplication::UnicodeUTF8));
        lat_point_lab->setText(QApplication::translate("edit_point", "Latitude :", 0, QApplication::UnicodeUTF8));
        Lon_point_lab->setText(QApplication::translate("edit_point", "Longitude : ", 0, QApplication::UnicodeUTF8));
        decription_point_lab->setText(QApplication::translate("edit_point", "desciption :", 0, QApplication::UnicodeUTF8));
        categorie_point_but->setText(QApplication::translate("edit_point", "Ajouter une categorie", 0, QApplication::UnicodeUTF8));
        BouttonPosition->setText(QApplication::translate("edit_point", "Position actuel", 0, QApplication::UnicodeUTF8));
        heures_point_box->setTitle(QApplication::translate("edit_point", "Horaires du point :", 0, QApplication::UnicodeUTF8));
        jour_heur_lab->setText(QApplication::translate("edit_point", "Jour :", 0, QApplication::UnicodeUTF8));
        plage_heur->setText(QApplication::translate("edit_point", "Plage horaire  :", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("edit_point", "-", 0, QApplication::UnicodeUTF8));
        jout_heur->setText(QApplication::translate("edit_point", "Ajouter ", 0, QApplication::UnicodeUTF8));
        supr_heur->setText(QApplication::translate("edit_point", "Supprimer", 0, QApplication::UnicodeUTF8));
        submit_heure->setText(QApplication::translate("edit_point", "mettre \303\240 jour", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("edit_point", "Points existant :", 0, QApplication::UnicodeUTF8));
        supr_point->setText(QApplication::translate("edit_point", "Supprimer", 0, QApplication::UnicodeUTF8));
        jout_point->setText(QApplication::translate("edit_point", "Ajouter ", 0, QApplication::UnicodeUTF8));
        submit_point->setText(QApplication::translate("edit_point", "metre \303\240 jour", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class edit_point: public Ui_edit_point {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITION_POINT_H
