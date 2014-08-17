#ifndef BXINTATTRIBUTE_H
#define BXINTATTRIBUTE_H

#include <QObject>
#include "BxBaseAttribute.h"

class BxIntAttribute : public QObject, public BxBaseAttribute
{
    Q_OBJECT
public:
    explicit BxIntAttribute( int in = 0, QObject *parent = 0);
    int getValue() { return mValue;}

public slots:
    void setValue(int in) { mValue = in;}

private:
    int mValue;

};

#endif // BXINTATTRIBUTE_H
