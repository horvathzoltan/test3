#ifndef ZQMLHELPER_H
#define ZQMLHELPER_H

#include <QQuickItem>

class zQMLHelper
{
public:
    zQMLHelper();

    static QQuickItem* FindItemByName(QList<QObject*> nodes, const QString& name);
};

#endif // ZQMLHELPER_H
