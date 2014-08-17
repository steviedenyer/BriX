#include "BxIntAttribute.h"

BxIntAttribute::BxIntAttribute(int in, QObject *parent) :
    QObject(parent)
{
    mValue = 0;
}

QWidget *BxIntAttribute::getControl()
  {
  QSpinBox* spinBox = new QSpinBox();
  spinBox->setMaximum(100);
  spinBox->setMinimum(0);
  spinBox->setValue(mValue);
  QObject::connect(spinBox, SIGNAL(valueChanged(int)), this, SLOT(setValue(int)));
  return spinBox;
  }
