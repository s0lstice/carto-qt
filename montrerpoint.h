#ifndef MONTRERPOINT_H
#define MONTRERPOINT_H

#include <QDialog>
#include "POI.h"

#include <QtGui>
#include <QMapControl/qmapcontrol.h>
#include <QSlider>
#include <QNetworkReply>
#include <QPointF>

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
};

#endif // MONTRERPOINT_H
