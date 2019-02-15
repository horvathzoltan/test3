#ifndef ZHTMLHELPER_H
#define ZHTMLHELPER_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QString>



class zHTMLHelper: public QObject
{
    Q_OBJECT
public:
    explicit zHTMLHelper(QObject *parent = nullptr);
    ~zHTMLHelper();

    QByteArray download(const QString& urlstring);
private:
    QNetworkAccessManager* manager;
};

#endif // ZHTMLHELPER_H
