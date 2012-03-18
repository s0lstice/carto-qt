/********************************************************************************
** Form generated from reading UI file 'carte.ui'
**
** Created: Sat 17. Mar 18:47:43 2012
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
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QListWidget>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QProgressBar>
#include <QtGui/QPushButton>
#include <QtGui/QSlider>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Carte
{
public:
    QAction *actionQuitter;
    QAction *actionChoix_BDD;
    QAction *actionGestion_BDD;
    QWidget *centralWidget;
    QWidget *MapWidget;
    QSlider *verticalSlider;
    QLabel *label;
    QProgressBar *progressBar;
    QPushButton *BouttonModifier;
    QPushButton *BouttonAccesBDD;
    QListWidget *listWidget;
    QPushButton *BouttonCentrer;
    QMenuBar *menuBar;
    QMenu *menuMenu;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Carte)
    {
        if (Carte->objectName().isEmpty())
            Carte->setObjectName(QString::fromUtf8("Carte"));
        Carte->resize(849, 631);
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
        progressBar->setGeometry(QRect(10, 550, 831, 20));
        progressBar->setValue(100);
        progressBar->setAlignment(Qt::AlignCenter);
        progressBar->setInvertedAppearance(false);
        progressBar->setTextDirection(QProgressBar::TopToBottom);
        BouttonModifier = new QPushButton(centralWidget);
        BouttonModifier->setObjectName(QString::fromUtf8("BouttonModifier"));
        BouttonModifier->setGeometry(QRect(570, 340, 81, 23));
        BouttonAccesBDD = new QPushButton(centralWidget);
        BouttonAccesBDD->setObjectName(QString::fromUtf8("BouttonAccesBDD"));
        BouttonAccesBDD->setGeometry(QRect(740, 340, 91, 23));
        listWidget = new QListWidget(centralWidget);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setGeometry(QRect(570, 10, 261, 321));
        BouttonCentrer = new QPushButton(centralWidget);
        BouttonCentrer->setObjectName(QString::fromUtf8("BouttonCentrer"));
        BouttonCentrer->setGeometry(QRect(660, 340, 71, 23));
        Carte->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(Carte);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 849, 21));
        menuMenu = new QMenu(menuBar);
        menuMenu->setObjectName(QString::fromUtf8("menuMenu"));
        Carte->setMenuBar(menuBar);
        mainToolBar = new QToolBar(Carte);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        Carte->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(Carte);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        Carte->setStatusBar(statusBar);

        menuBar->addAction(menuMenu->menuAction());
        menuMenu->addAction(actionChoix_BDD);
        menuMenu->addAction(actionGestion_BDD);
        menuMenu->addAction(actionQuitter);

        retranslateUi(Carte);

        QMetaObject::connectSlotsByName(Carte);
    } // setupUi

    void retranslateUi(QMainWindow *Carte)
    {
        Carte->setWindowTitle(QApplication::translate("Carte", "Carte", 0, QApplication::UnicodeUTF8));
        actionQuitter->setText(QApplication::translate("Carte", "Quitter", 0, QApplication::UnicodeUTF8));
        actionChoix_BDD->setText(QApplication::translate("Carte", "Choix BDD", 0, QApplication::UnicodeUTF8));
        actionGestion_BDD->setText(QApplication::translate("Carte", "Gestion BDD", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Carte", "0", 0, QApplication::UnicodeUTF8));
        BouttonModifier->setText(QApplication::translate("Carte", "Modifier", 0, QApplication::UnicodeUTF8));
        BouttonAccesBDD->setText(QApplication::translate("Carte", "Acces BDD", 0, QApplication::UnicodeUTF8));
        BouttonCentrer->setText(QApplication::translate("Carte", "Centrer", 0, QApplication::UnicodeUTF8));
        menuMenu->setTitle(QApplication::translate("Carte", "Menu", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Carte: public Ui_Carte {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CARTE_H
