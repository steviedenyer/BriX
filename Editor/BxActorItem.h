#ifndef BXACTORITEM_H
#define BXACTORITEM_H

#include "BxAttributes.h"

#include <QGraphicsItem>
#include <QtWidgets>
#include <QVector>

class BxActorItem : public QGraphicsEllipseItem
{
public:
    BxActorItem();
    BxActorItem(const QRectF &rect, QGraphicsItem *parent = 0);

    QWidget* getControls();
    void writeToJson(QJsonObject &);
    void addAttribute(BxBaseAttribute*);

signals:
    
public slots:
//    void setValue(int in) { testValue = in; }

private:
//    BxIntAttribute* mTestValue;
    QVector<BxBaseAttribute*> mAttributes;
    QString mID;
    
};

#endif // BXACTORITEM_H
