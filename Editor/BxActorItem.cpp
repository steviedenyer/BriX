#include "BxActorItem.h"
#include <QTreeView>
#include <QObject>

BxActorItem::BxActorItem()
{
    mTestValue = new BxIntAttribute();
}

BxActorItem::BxActorItem(const QRectF &rect, QGraphicsItem* parent) :
    QGraphicsEllipseItem(rect, parent)
{

    mTestValue = new BxIntAttribute();
    setFlag(ItemIsMovable, true);
    setFlag(ItemIsSelectable, true);
}

QWidget* BxActorItem::getControls()
{
    /*
    QSpinBox* test = new QSpinBox();
    test->setMaximum(100);
    test->setMinimum(0);
    test->setValue(mTestValue->getValue());
    QObject::connect(test, SIGNAL(valueChanged(int)), mTestValue, SLOT(setValue(int)));
    return test;
    */
    return mTestValue->getControl();
}
