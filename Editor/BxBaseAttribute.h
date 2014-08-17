#ifndef BXBASEATTRIBUTE_H
#define BXBASEATTRIBUTE_H

#include <QWidget>
#include <QtWidgets>

class BxBaseAttribute
{
public:
    BxBaseAttribute();
    ~BxBaseAttribute();
    QWidget* getControl() { return mControl; }
//    int getValue() { return mValue;}
protected:
    QWidget* mControl;

private:

};

#endif // BXBASEATTRIBUTE_H
