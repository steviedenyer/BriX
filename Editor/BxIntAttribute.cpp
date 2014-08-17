#include "BxIntAttribute.h"

BxIntAttribute::BxIntAttribute(int in, QObject *parent) :
    QObject(parent)
{
    QSpinBox* spinBox = new QSpinBox();
    spinBox->setMaximum(100);
    spinBox->setMinimum(0);
    spinBox->setValue(in);
    QObject::connect(spinBox, SIGNAL(valueChanged(int)), this, SLOT(setValue(int)));
    mControl = spinBox;
    mValue = 0;
}
