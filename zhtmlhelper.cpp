#include "zhtmlhelper.h"

#include <QObject>
#include <QEventLoop>
#include <QNetworkReply>

zHTMLHelper::zHTMLHelper(QObject *parent) : QObject(parent)
{
    manager = nullptr;
}

zHTMLHelper::~zHTMLHelper(){
    delete manager;
}

QByteArray zHTMLHelper::download(const QString& urlstring)
{
    manager = new QNetworkAccessManager(this);
    //auto ikey = zLog::openInfo(QStringLiteral("Beolvasás: %1").arg(urlstring));

    //auto url = QUrl(QStringLiteral("https://docs.google.com/document/export?format=html&id=1qqYuhCY5iTAfzBiwQGfzRdU7C1jm1pNnNajVrSrWAfU"));
    auto url = QUrl(urlstring);
    QNetworkRequest request;
    request.setUrl(url);
    request.setRawHeader("User-Agent", "zDownloader 1.0");

      QNetworkReply* reply = manager->get(request);

      QEventLoop loop;
      connect(reply, SIGNAL(finished()), &loop, SLOT(quit()));
      loop.exec();
      auto e = reply->readAll();

      //zLog::appendInfo(ikey, zLog::OK);
      //zLog::closeInfo(ikey);
      return e;
}
