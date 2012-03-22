/**
 * \file application.h
 * \brief classe Application. Initialise l'application
 * \author Guillaume Lastecoueres & Mickael Puret
 * \version 0.1
 *
 * Initialisation et destruction du programme, gere les parametres de l'application.
 *
 */

#ifndef APPLICATION_H
#define APPLICATION_H

#include <QtGui/QApplication>

class application : public QApplication
{
public:
    static application *_singleton;

    static application *appInit(int & argc, char ** argv)
    {
        if (NULL == _singleton)
        {
            _singleton = new application(argc, argv);
        }
        return _singleton;
    }

    static application *appInit()
    {
        if (NULL == _singleton)
        {
            qFatal("application : singleton non initialisé");
            exit(1);
        }
        return _singleton;
    }

    static void appExit(){
        if (NULL != _singleton)
        {
            delete _singleton;
            _singleton = NULL;
        }
    }


private:
    application(int & argc, char ** argv);
    ~application();
};

#endif // APPLICATION_H
