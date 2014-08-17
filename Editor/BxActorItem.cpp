#include "BxActorItem.h"
#include <QTreeView>
#include <QObject>

BxActorItem::BxActorItem()
{
    //mTestValue = new BxIntAttribute();
    mID = "test";
}

BxActorItem::BxActorItem(const QRectF &rect, QGraphicsItem* parent) :
    QGraphicsEllipseItem(rect, parent)
{
    mID = "test";
    //mTestValue = new BxIntAttribute();
    setFlag(ItemIsMovable, true);
    setFlag(ItemIsSelectable, true);
}

QWidget* BxActorItem::getControls()
{
    QWidget* grp = new QWidget;
    QVBoxLayout* grpLayout = new QVBoxLayout(grp);

    foreach(auto attr, mAttributes)
    {
        auto at = attr->getControl(grp);
        grpLayout->addItem(at);
    }

    return grp;
}

void BxActorItem::writeToJson(QJsonObject &in)
{
    QJsonObject JsonActor;
    QJsonObject JsonPos;
    QJsonObject JsonAttr;

    JsonPos["x"] = x();
    JsonPos["y"] = y();
    JsonActor["pos"] = JsonPos;

    foreach(auto attr, mAttributes)
    {
        attr->writeToJson(JsonAttr);
    }
    JsonActor["attr"] = JsonAttr;
    in[mID] = JsonActor;
}

void BxActorItem::addAttribute(BxBaseAttribute *in)
{
    mAttributes.push_back(in);
}
