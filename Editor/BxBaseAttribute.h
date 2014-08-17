#ifndef BXBASEATTRIBUTE_H
#define BXBASEATTRIBUTE_H

#include <QWidget>
#include <QtWidgets>

class BxBaseAttribute
{
public:
    BxBaseAttribute();
    ~BxBaseAttribute();

    virtual QWidget* getControl() = 0;
//    int getValue() { return mValue;}
protected:
    QWidget* mControl;

private:

};

#endif // BXBASEATTRIBUTE_H
