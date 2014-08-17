#ifndef BXLEVELVIEW_H
#define BXLEVELVIEW_H

#include <QGraphicsView>
#include "BxLevelScene.h"

class BxLevelView : public QGraphicsView
{
    Q_OBJECT
public:
    BxLevelView(BxLevelScene*);
    
signals:
    
public slots:

private:
    bool mTranslating;
    bool mScaling;
    int mLastMouseXPos;
    QPointF mScalePoint;
    QTransform mTransform;

    void keyPressEvent(QKeyEvent*);
    void keyReleaseEvent(QKeyEvent*);

    void mousePressEvent(QMouseEvent*);
    void mouseMoveEvent(QMouseEvent*);
    void mouseReleaseEvent(QMouseEvent*);
    
};

#endif // BXLEVELVIEW_H
