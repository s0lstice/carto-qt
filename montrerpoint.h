/**
 * \file montrerpoint.h
 * \brief Fenetre permetant la visualisation complette d'un point, position sur catre, donnees dans la base.
 * \author Guillaume Lastecoueres & Mickael Puret
 * \version 0.1
 *
 *
 */

#ifndef MONTRERPOINT_H
#define MONTRERPOINT_H

#include <QDialog>
#include "POI.h"

#include <QtGui>
#include <QMapControl/qmapcontrol.h>
#include <QSlider>
#include <QNetworkReply>
#include <QPointF>
#include <QSqlRelationalTableModel>
#include <QSqlRelationalDelegate>
#include "POI.h"
#include "edit_point_gui.h"



using namespace qmapcontrol;
namespace Ui {
class MontrerPoint;
}

class MontrerPoint : public QDialog
{
    Q_OBJECT

public:
    explicit MontrerPoint(POI PointDInteret,QWidget *parent = 0);
    ~MontrerPoint();

private:
    Ui::MontrerPoint *ui;
    MapControl* mc;
    MapAdapter* mapadapter;
    Layer* mainlayer;
    QSqlRelationalTableModel *modelheures;
    POI PointDInteretA;
private slots:
    void modification();
};

#endif // MONTRERPOINT_H
