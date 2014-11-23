#include "BxNodePath.h"

BxNodePath::BxNodePath(QGraphicsScene* scene)
{
    mScene = scene;
}

void BxNodePath::addPoint(const QPointF &in)
{
    BxNodePathPoint* newPoint = new BxNodePathPoint(0, mScene);
    newPoint->setPos(in);

    if(!mPoints.empty())
    {
        BxNodeLine* newLine = new BxNodeLine(newPoint, mPoints.last()); // add line to both nodes connected
        newPoint->mConnections.push_back(newLine);
        mPoints.last()->mConnections.push_back(newLine);

        newLine->adjust();
        newLine->update();

        mScene->addItem(newLine);
    }

    mPoints.push_back(newPoint);
    mScene->addItem(newPoint);
}
