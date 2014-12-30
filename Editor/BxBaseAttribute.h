#ifndef BXBASEATTRIBUTE_H
#define BXBASEATTRIBUTE_H

#include <QWidget>
#include <QtWidgets>
#include <QJsonObject>
#include <QPointer>

class BxBaseAttribute
{
public:    
    BxBaseAttribute(const QString &);
    ~BxBaseAttribute();

    virtual QLayout* getControl(QWidget* parent) = 0;
    void setName(const QString &);
    const QString & getName();

    virtual void writeToJson(QJsonObject &) = 0;
//    int getValue() { return mValue;}
protected:
    QPointer<QWidget> mControl;
    QString mName;

private:

};

#endif // BXBASEATTRIBUTE_H
