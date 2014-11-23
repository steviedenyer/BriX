#include "BxBaseAttribute.h"

BxBaseAttribute::BxBaseAttribute(const QString &in)
{
    setName(in);
}

void BxBaseAttribute::setName(const QString &in)
{
    mName = in;
}

const QString& BxBaseAttribute::getName()
{
    return mName;
}

BxBaseAttribute::~BxBaseAttribute()
{
    if(mControl != NULL)
    {
//        mControl->deleteLater();
        delete mControl;
    }
}


