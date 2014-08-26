#include "BxActorItem.h"
#include <QTreeView>
#include <QObject>

BxActorItem::BxActorItem(QGraphicsItem* parent) :
    QGraphicsEllipseItem(QRect(-50, -50, 100, 100), parent)
{
    initialise();
}

BxActorItem::BxActorItem(const QJsonObject & actorObj, QGraphicsItem *parent) :
    QGraphicsEllipseItem(QRect(-50, -50, 100, 100), parent)
{
    initialise();
    this->readFromJson(actorObj);
}

void BxActorItem::initialise()
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

void BxActorItem::readFromJson(const QJsonObject &in)
{
        QJsonObject pos = in["pos"].toObject();
            double x = pos["x"].toDouble();
            double y = pos["y"].toDouble();

        QJsonObject attr = in["attr"].toObject();
            double radius = attr["radius"].toDouble();

        BxIntAttribute* radiusAttr = new BxIntAttribute("radius", radius);

        setX(x);
        setY(y);
        addAttribute(radiusAttr);

}

void BxActorItem::addAttribute(BxBaseAttribute *in)
{
    mAttributes.push_back(in);
}
