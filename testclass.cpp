#include <QDebug>
#include <QJsonDocument>
#include <QJsonObject>
#include "testclass.h"


//int TestClass::counter = 123;

TestClass::TestClass(QObject *parent) : QObject(parent)
{
    counter = 555;
}


int TestClass::doWork(const QString &a)
{
    int eredmeny=-1;
    auto b = htmlhelper.download("http://172.16.1.63:8080/getNext");

    if(!b.isEmpty())
    {
        QJsonDocument itemDoc = QJsonDocument::fromJson(b);
        QJsonObject rootObject = itemDoc.object();

        eredmeny = rootObject.value("number").toInt();
    }

    qDebug() << QStringLiteral("Nyom: %1: %2").arg(a).arg(eredmeny);
    return eredmeny;
}
