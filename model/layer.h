#ifndef LAYER_H
#define LAYER_H

#include <QString>

#include "pointtype.h"
#include "componenttype.h"

enum ColorType{
    Tricolor,
    GreyColor
};

class Layer
{
    QString script;
    QString rcomponent;
    QString gcomponent;
    QString bcomponent;
    QString greycomponent;
    PointType xtype;
    PointType ytype;
    ColorType colortype;
public:
    Layer();
    QString getScript();
    QString getRComponent();
    QString getGComponent();
    QString getBComponent();
    QString getGreyComponent();
    QString getComponent(ComponentType component);
    PointType getXPointType();
    PointType getYPointType();
    ColorType getColorType();
    void setScript(QString script);
    void setRComponent(QString expr);
    void setGComponent(QString expr);
    void setBComponent(QString expr);
    void setGreyComponent(QString expr);
    void setComponent(ComponentType component,QString exp);
    void setXPointType(PointType type);
    void setYPointType(PointType type);
    void setColorType(ColorType type);
};

#endif // LAYER_H