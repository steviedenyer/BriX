#include "BxIntAttribute.h"

BxIntAttribute::BxIntAttribute(QString name, int in, QObject *parent) :
    QObject(parent), BxBaseAttribute(name)
{
    mValue = in;
}

QLayout* BxIntAttribute::getControl(QWidget* parent)
{
  QHBoxLayout* grp = new QHBoxLayout();

  QSpinBox* spinBox = new QSpinBox(parent);
  spinBox->setMaximum(100);
  spinBox->setMinimum(0);
  spinBox->setValue(mValue);
  QObject::connect(spinBox, SIGNAL(valueChanged(int)), this, SLOT(setValue(int)));

  QLabel* label = new QLabel(mName, parent);

  grp->addWidget(label);
  grp->addWidget(spinBox);
  return grp;
}

 void BxIntAttribute::writeToJson(QJsonObject &in)
 {
     in[mName] = mValue;
 }
