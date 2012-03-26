/**
 * \file database.h
 * \brief Classe singleton, gere l'ouverture et la fermeture de la base de donne, paussaide egalement les methode pour y acceder.
 * \author Guillaume Lastecoueres & Mickael Puret
 * \version 0.1
 *
 *
 */

#ifndef DATABASE_H
#define DATABASE_H

#include <QtSql>
#include "POI.h"

class database
{
public:
    static QString dataName;

    QSqlDatabase dataConnect();
    static database *_singleton;
    void initTable();

    /*!
      @fn static database *dataCreate(QString name)
      @brief gestionnaire de singleton, permet d'instancier ou de recuperer la classe
      @param name : QString : nom de la base de donné
      @note info : cette fonction est appelle obligatoirement la premiere fois, pour ouvrir la base de donné
    */
    static database *dataCreate(QString name)
    {
        if(dataName == ""){
            if (NULL == _singleton)
            {
                dataName = name;

                _singleton = new database(dataName);
            }
        }else
            if((name != "")&&(dataName != name)){ //evite les changement de base trop bourin
                dataDisconnect();
                dataName = name;
                _singleton = new database(dataName);
            }

        return _singleton;
    }

    /*!
      @fn static database *dataCreate()
      @brief gestionnaire de singleton, permet de recuperer la classe
      @note info : cette fonction est a utiliser uniquement apres une premiere instanciation de la classe.
    */
    static database *dataCreate()
    {

        if(dataName == "")
            qFatal("bdd non nome");

        if (NULL == _singleton)
        {
            qFatal("bdd non nome");
            //_singleton = new database(dataName);
        }
        return _singleton;
    }
    /*!
      @fn static void dataDisconnect()
      @brief permet de detruire la classe
    */

    static void dataDisconnect(){
        if (NULL != _singleton)
          {
            delete _singleton;
            dataName = "";
            _singleton = NULL;
          }
    }

private :
    QSqlDatabase db;
    database(QString name);
    ~database();
};

#endif // DATABASE_H
