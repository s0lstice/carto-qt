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

    static database *dataCreate(QString name)
    {

        if (NULL == _singleton)
        {
            dataName = name;

            _singleton = new database(dataName);
        }
        return _singleton;
    }

    static database *dataCreate()
    {


        if (NULL == _singleton)
        {
            _singleton = new database(dataName);
        }
        return _singleton;
    }

    static void dataDisconnect(){
        if (NULL != _singleton)
          {
            delete _singleton;
            _singleton = NULL;
          }
    }

private :
    QSqlDatabase db;
    database(QString name);
    ~database();
};

#endif // DATABASE_H
