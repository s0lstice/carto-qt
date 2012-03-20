/********************************************************************************
** Form generated from reading UI file 'montrerpoint.ui'
**
** Created: Mon 19. Mar 22:13:33 2012
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MONTRERPOINT_H
#define UI_MONTRERPOINT_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPlainTextEdit>
#include <QtGui/QPushButton>
#include <QtGui/QTableWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MontrerPoint
{
public:
    QWidget *widget;
    QPushButton *BouttonFermer;
    QWidget *widget1;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEdit_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *lineEdit;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLineEdit *lineEdit_3;
    QLabel *label_4;
    QLineEdit *lineEdit_4;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_5;
    QPlainTextEdit *plainTextEdit;
    QTableWidget *tableWidget;

    void setupUi(QDialog *MontrerPoint)
    {
        if (MontrerPoint->objectName().isEmpty())
            MontrerPoint->setObjectName(QString::fromUtf8("MontrerPoint"));
        MontrerPoint->resize(670, 404);
        widget = new QWidget(MontrerPoint);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(9, 9, 231, 351));
        BouttonFermer = new QPushButton(MontrerPoint);
        BouttonFermer->setObjectName(QString::fromUtf8("BouttonFermer"));
        BouttonFermer->setGeometry(QRect(580, 370, 75, 23));
        widget1 = new QWidget(MontrerPoint);
        widget1->setObjectName(QString::fromUtf8("widget1"));
        widget1->setGeometry(QRect(250, 10, 411, 351));
        verticalLayout_2 = new QVBoxLayout(widget1);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(widget1);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        lineEdit_2 = new QLineEdit(widget1);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));

        horizontalLayout->addWidget(lineEdit_2);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(widget1);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        lineEdit = new QLineEdit(widget1);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        horizontalLayout_2->addWidget(lineEdit);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_3 = new QLabel(widget1);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_3->addWidget(label_3);

        lineEdit_3 = new QLineEdit(widget1);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));

        horizontalLayout_3->addWidget(lineEdit_3);

        label_4 = new QLabel(widget1);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_3->addWidget(label_4);

        lineEdit_4 = new QLineEdit(widget1);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));

        horizontalLayout_3->addWidget(lineEdit_4);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_5 = new QLabel(widget1);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_4->addWidget(label_5);

        plainTextEdit = new QPlainTextEdit(widget1);
        plainTextEdit->setObjectName(QString::fromUtf8("plainTextEdit"));

        horizontalLayout_4->addWidget(plainTextEdit);


        verticalLayout->addLayout(horizontalLayout_4);

        tableWidget = new QTableWidget(widget1);
        if (tableWidget->columnCount() < 3)
            tableWidget->setColumnCount(3);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setRowCount(0);
        tableWidget->setColumnCount(3);
        tableWidget->horizontalHeader()->setVisible(true);
        tableWidget->horizontalHeader()->setCascadingSectionResizes(true);
        tableWidget->horizontalHeader()->setProperty("showSortIndicator", QVariant(false));

        verticalLayout->addWidget(tableWidget);


        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(MontrerPoint);

        QMetaObject::connectSlotsByName(MontrerPoint);
    } // setupUi

    void retranslateUi(QDialog *MontrerPoint)
    {
        MontrerPoint->setWindowTitle(QApplication::translate("MontrerPoint", "Dialog", 0, QApplication::UnicodeUTF8));
        BouttonFermer->setText(QApplication::translate("MontrerPoint", "Fermer", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MontrerPoint", "Nom :", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MontrerPoint", "Categorie :", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MontrerPoint", "Latitude :", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("MontrerPoint", "Longitude :", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("MontrerPoint", "Description :", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MontrerPoint: public Ui_MontrerPoint {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MONTRERPOINT_H
