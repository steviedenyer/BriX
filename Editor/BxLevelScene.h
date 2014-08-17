#ifndef BXLEVELSCENE_H
#define BXLEVELSCENE_H

#include <QGraphicsScene>
#include "BxActorItem.h"

class BxLevelScene : public QGraphicsScene
{
    Q_OBJECT
public:

    enum Mode { insertItem, moveItem, moveView };
    BxLevelScene();
    void insertActor(BxActorItem*);
    
signals:

    void itemInserted(QGraphicsItem*);

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent*);
    void mouseMoveEvent(QGraphicsSceneMouseEvent*);


public slots:
    void setMode(int in){ mMode = in; }

private:

    int mMode;

    
};

#endif // BXLEVELSCENE_H
