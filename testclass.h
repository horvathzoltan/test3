#ifndef TESTCLASS_H
#define TESTCLASS_H

#include "zhtmlhelper.h"

#include <QObject>

class TestClass : public QObject
{
    Q_OBJECT
public:
    explicit TestClass(QObject *parent = nullptr);

signals:

public slots:
    int doWork(const QString & a);

private:
   int counter;
   zHTMLHelper htmlhelper;
};

#endif // TESTCLASS_H
