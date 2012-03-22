/**
 * \file application.cpp
 * \brief classe Application. Initialise l'application
 * \author Guillaume Lastecoueres & Mickael Puret
 * \version 0.1
 *
 * Initialisation et destruction du programme, gere les parametres de l'application.
 *
 */


#include "application.h"
#include <QSettings>
#include "data_categories.h"
application *application::_singleton = NULL;

/*!
  @fn application::application(int & argc, char ** argv) : QApplication(argc, argv)

  @brief constructeur de l'application, herite de QApplication
  @param argc et argv: parametres d'appelle de l'application
  @note info : ce constructeur est privé, la casse application est un singleton qui herite de QApplication.
    role : initialise une application qt, met en place le QSettings qui gere les categories de base.\n
    permet egalement de recupere le descripteur de l'application au cours de la vie du programme ; dans le but, par exemple, de changer la langue de maniere dynamique.
*/
application::application(int & argc, char ** argv) : QApplication(argc, argv)
{

    QSettings settings("CartoTeam", "Cartographe");
    if(settings.value("Categories","NULL").toString()=="NULL"){

        QVariantList ListeDeCat;
        ListeDeCat.append("supermarche");
        ListeDeCat.append("musee");
        ListeDeCat.append("cinema");
        ListeDeCat.append("theatre");

        settings.setValue("Categories",ListeDeCat);
    }
}

/*!
  @fnapplication::~application()
  @brief destructeur de l'application,

  @brief destructeur de l'application,
  @role : enregistre les categories dans les parametre de l'application, detruit l'application
*/
application::~application()
{
    QSettings settings("CartoTeam", "Cartographe");
    QVariantList EndList;
    QVector<QString> Categories= getCategories();
    int i = 0;
    for(i=0;i<Categories.count();i++)
    {
        EndList.append(Categories.value(i));
    }
    settings.setValue("Categories",EndList);

}

