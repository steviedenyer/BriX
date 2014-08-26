#ifndef BXPATH_H
#define BXPATH_H

#include "BxPathPoint.h"

class BxPath
{
public:
    BxPath();

private:
    QVector<BxPathPoint*> mPoints;
};

#endif // BXPATH_H
