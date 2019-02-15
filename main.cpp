#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QScreen>
#include <QQmlContext>
#include <QQmlProperty>
#include <QQuickStyle>

#include "zqmlhelper.h"
#include "testclass.h"

int main(int argc, char *argv[])
{
    TestClass test1;

    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQuickStyle::setStyle("qrc:/styles/Industrial");
    QQuickStyle::setFallbackStyle("Universal");

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    engine.rootContext()->setContextProperty("_test1", &test1);

//    QScreen* screen = QGuiApplication::primaryScreen();
//    screen->setOrientationUpdateMask(Qt::PortraitOrientation);

    auto objects = engine.rootObjects();
    if (objects.isEmpty())
        return -1;

    auto t1 = zQMLHelper::FindItemByName(objects, "text1name");
    QQmlProperty(t1, "text").write("propwite1");
    return app.exec();
}
