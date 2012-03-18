/********************************************************************************
** Form generated from reading UI file 'askdatabase.ui'
**
** Created: Sun 18. Mar 12:05:14 2012
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ASKDATABASE_H
#define UI_ASKDATABASE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AskDataBase
{
public:
    QWidget *centralwidget;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QComboBox *comboBox;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QMenuBar *menubar;

    void setupUi(QMainWindow *AskDataBase)
    {
        if (AskDataBase->objectName().isEmpty())
            AskDataBase->setObjectName(QString::fromUtf8("AskDataBase"));
        AskDataBase->resize(592, 93);
        centralwidget = new QWidget(AskDataBase);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayoutWidget = new QWidget(centralwidget);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(10, 0, 551, 80));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        comboBox = new QComboBox(gridLayoutWidget);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setEditable(true);

        gridLayout->addWidget(comboBox, 0, 0, 1, 3);

        pushButton = new QPushButton(gridLayoutWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        gridLayout->addWidget(pushButton, 1, 0, 1, 1);

        pushButton_2 = new QPushButton(gridLayoutWidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        gridLayout->addWidget(pushButton_2, 1, 1, 1, 1);

        pushButton_3 = new QPushButton(gridLayoutWidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));

        gridLayout->addWidget(pushButton_3, 1, 2, 1, 1);

        pushButton_4 = new QPushButton(centralwidget);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(570, 10, 21, 21));
        AskDataBase->setCentralWidget(centralwidget);
        menubar = new QMenuBar(AskDataBase);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 592, 20));
        AskDataBase->setMenuBar(menubar);

        retranslateUi(AskDataBase);

        QMetaObject::connectSlotsByName(AskDataBase);
    } // setupUi

    void retranslateUi(QMainWindow *AskDataBase)
    {
        AskDataBase->setWindowTitle(QApplication::translate("AskDataBase", "Choix de la base de donn\303\251e", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("AskDataBase", "Cr\303\251er", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("AskDataBase", "S\303\251l\303\251ctionner", 0, QApplication::UnicodeUTF8));
        pushButton_3->setText(QApplication::translate("AskDataBase", "Quitter", 0, QApplication::UnicodeUTF8));
        pushButton_4->setText(QApplication::translate("AskDataBase", "...", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class AskDataBase: public Ui_AskDataBase {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ASKDATABASE_H
