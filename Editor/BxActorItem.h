#ifndef BXACTORITEM_H
#define BXACTORITEM_H

#include "BxAttributes.h"

#include <QGraphicsItem>
#include <QtWidgets>

class BxActorItem : public QGraphicsEllipseItem
{
public:
    BxActorItem();
    BxActorItem(const QRectF &rect, QGraphicsItem *parent = 0);

    QWidget* getControls();
signals:
    
public slots:
//    void setValue(int in) { testValue = in; }

private:
    BxIntAttribute* mTestValue;
    
};

#endif // BXACTORITEM_H
