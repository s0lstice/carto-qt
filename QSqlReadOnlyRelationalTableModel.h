#ifndef QSQLREADONLYRELATIONALTABLEMODEL_H
#define QSQLREADONLYRELATIONALTABLEMODEL_H

#include <QSqlRelationalTableModel>

class QSqlReadOnlyRelationalTableModel : public QSqlRelationalTableModel {
public:
    QSqlReadOnlyRelationalTableModel(QObject *parent = 0) : QSqlRelationalTableModel(parent){}

    Qt::ItemFlags flags ( const QModelIndex & index ) const{
        if(index.column() != 0)
            return QSqlRelationalTableModel::flags(index);
        return (QSqlRelationalTableModel::flags(index) & ~Qt::ItemIsEditable);
    }
};

#endif // QSQLREADONLYRELATIONALTABLEMODEL_H
