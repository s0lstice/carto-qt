/********************************************************************************
** Form generated from reading UI file 'carte.ui'
**
** Created: Thu 22. Mar 10:14:11 2012
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CARTE_H
#define UI_CARTE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QListWidget>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QProgressBar>
#include <QtGui/QPushButton>
#include <QtGui/QSlider>
#include <QtGui/QSpinBox>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Carte
{
public:
    QAction *actionQuitter;
    QAction *actionChoix_BDD;
    QAction *actionGestion_BDD;
    QAction *actionExport_BDD;
    QAction *actionAnglais;
    QAction *actionFrancais;
    QWidget *centralWidget;
    QWidget *MapWidget;
    QSlider *verticalSlider;
    QLabel *label;
    QProgressBar *progressBar;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QListWidget *listWidget;
    QPushButton *BouttonCentrer;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QSpinBox *spinBox;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QLineEdit *lineEdit;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_4;
    QComboBox *comboBox;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *BouttonTelecharger;
    QCheckBox *AutoDownLoad;
    QMenuBar *menuBar;
    QMenu *menuMenu;
    QMenu *menuBDD;
    QMenu *menuLangue;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Carte)
    {
        if (Carte->objectName().isEmpty())
            Carte->setObjectName(QString::fromUtf8("Carte"));
        Carte->resize(850, 652);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Carte->sizePolicy().hasHeightForWidth());
        Carte->setSizePolicy(sizePolicy);
        actionQuitter = new QAction(Carte);
        actionQuitter->setObjectName(QString::fromUtf8("actionQuitter"));
        actionChoix_BDD = new QAction(Carte);
        actionChoix_BDD->setObjectName(QString::fromUtf8("actionChoix_BDD"));
        actionGestion_BDD = new QAction(Carte);
        actionGestion_BDD->setObjectName(QString::fromUtf8("actionGestion_BDD"));
        actionExport_BDD = new QAction(Carte);
        actionExport_BDD->setObjectName(QString::fromUtf8("actionExport_BDD"));
        actionAnglais = new QAction(Carte);
        actionAnglais->setObjectName(QString::fromUtf8("actionAnglais"));
        actionFrancais = new QAction(Carte);
        actionFrancais->setObjectName(QString::fromUtf8("actionFrancais"));
        centralWidget = new QWidget(Carte);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        MapWidget = new QWidget(centralWidget);
        MapWidget->setObjectName(QString::fromUtf8("MapWidget"));
        MapWidget->setGeometry(QRect(10, 10, 500, 520));
        verticalSlider = new QSlider(centralWidget);
        verticalSlider->setObjectName(QString::fromUtf8("verticalSlider"));
        verticalSlider->setGeometry(QRect(510, 10, 21, 161));
        verticalSlider->setMaximum(17);
        verticalSlider->setOrientation(Qt::Vertical);
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(540, 155, 51, 21));
        progressBar = new QProgressBar(centralWidget);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setGeometry(QRect(10, 570, 831, 20));
        progressBar->setValue(100);
        progressBar->setAlignment(Qt::AlignCenter);
        progressBar->setInvertedAppearance(false);
        progressBar->setTextDirection(QProgressBar::TopToBottom);
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(570, 10, 260, 521));
        verticalLayout_2 = new QVBoxLayout(layoutWidget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        listWidget = new QListWidget(layoutWidget);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));

        verticalLayout->addWidget(listWidget);

        BouttonCentrer = new QPushButton(layoutWidget);
        BouttonCentrer->setObjectName(QString::fromUtf8("BouttonCentrer"));

        verticalLayout->addWidget(BouttonCentrer);


        verticalLayout_2->addLayout(verticalLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);

        spinBox = new QSpinBox(layoutWidget);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setMaximum(99999);
        spinBox->setValue(10);

        horizontalLayout->addWidget(spinBox);


        verticalLayout_2->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_2->addWidget(label_3);

        lineEdit = new QLineEdit(layoutWidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        horizontalLayout_2->addWidget(lineEdit);


        verticalLayout_2->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_3->addWidget(label_4);

        comboBox = new QComboBox(layoutWidget);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        horizontalLayout_3->addWidget(comboBox);


        verticalLayout_2->addLayout(horizontalLayout_3);

        widget = new QWidget(centralWidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(10, 540, 301, 21));
        horizontalLayout_4 = new QHBoxLayout(widget);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        BouttonTelecharger = new QPushButton(widget);
        BouttonTelecharger->setObjectName(QString::fromUtf8("BouttonTelecharger"));

        horizontalLayout_4->addWidget(BouttonTelecharger);

        AutoDownLoad = new QCheckBox(widget);
        AutoDownLoad->setObjectName(QString::fromUtf8("AutoDownLoad"));

        horizontalLayout_4->addWidget(AutoDownLoad);

        Carte->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(Carte);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 850, 21));
        menuMenu = new QMenu(menuBar);
        menuMenu->setObjectName(QString::fromUtf8("menuMenu"));
        menuBDD = new QMenu(menuBar);
        menuBDD->setObjectName(QString::fromUtf8("menuBDD"));
        menuLangue = new QMenu(menuBar);
        menuLangue->setObjectName(QString::fromUtf8("menuLangue"));
        Carte->setMenuBar(menuBar);
        mainToolBar = new QToolBar(Carte);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        Carte->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(Carte);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        Carte->setStatusBar(statusBar);

        menuBar->addAction(menuMenu->menuAction());
        menuBar->addAction(menuBDD->menuAction());
        menuBar->addAction(menuLangue->menuAction());
        menuMenu->addAction(actionQuitter);
        menuBDD->addAction(actionChoix_BDD);
        menuBDD->addAction(actionGestion_BDD);
        menuBDD->addAction(actionExport_BDD);
        menuLangue->addAction(actionAnglais);
        menuLangue->addAction(actionFrancais);

        retranslateUi(Carte);

        QMetaObject::connectSlotsByName(Carte);
    } // setupUi

    void retranslateUi(QMainWindow *Carte)
    {
        Carte->setWindowTitle(QApplication::translate("Carte", "Carte", 0, QApplication::UnicodeUTF8));
        actionQuitter->setText(QApplication::translate("Carte", "Quitter", 0, QApplication::UnicodeUTF8));
        actionChoix_BDD->setText(QApplication::translate("Carte", "Choix BDD", 0, QApplication::UnicodeUTF8));
        actionGestion_BDD->setText(QApplication::translate("Carte", "Gestion BDD", 0, QApplication::UnicodeUTF8));
        actionExport_BDD->setText(QApplication::translate("Carte", "Export BDD", 0, QApplication::UnicodeUTF8));
        actionAnglais->setText(QApplication::translate("Carte", "Anglais", 0, QApplication::UnicodeUTF8));
        actionFrancais->setText(QApplication::translate("Carte", "Francais", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Carte", "0", 0, QApplication::UnicodeUTF8));
        BouttonCentrer->setText(QApplication::translate("Carte", "Centrer", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("Carte", "Nombre de points \303\240 afficher :", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("Carte", "Chaine De Recherche :", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("Carte", "Categories : ", 0, QApplication::UnicodeUTF8));
        BouttonTelecharger->setText(QApplication::translate("Carte", "Telecharger", 0, QApplication::UnicodeUTF8));
        AutoDownLoad->setText(QApplication::translate("Carte", "Auto Telechargement", 0, QApplication::UnicodeUTF8));
        menuMenu->setTitle(QApplication::translate("Carte", "Menu", 0, QApplication::UnicodeUTF8));
        menuBDD->setTitle(QApplication::translate("Carte", "BDD", 0, QApplication::UnicodeUTF8));
        menuLangue->setTitle(QApplication::translate("Carte", "Langue", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Carte: public Ui_Carte {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CARTE_H
