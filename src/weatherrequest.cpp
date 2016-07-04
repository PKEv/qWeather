#include "weatherrequest.h"

// example
// http://api.openweathermap.org/data/2.5/forecast/daily?q=Moscow&cnt=7&APPID=4a61d170b251cc18c4c9417e7663d602

WeatherRequest::WeatherRequest(QObject *parent) : QObject(parent)
{
    manager = new QNetworkAccessManager(0);

    QObject::connect(manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(onReply(QNetworkReply*)));
    QString cityName = "Moscow";
    int dayCount = 7;

    QString location = "q=" + cityName + "&cnt=" + QString::number(dayCount);
    QString address = "http://api.openweathermap.org/data/2.5/forecast/daily?" + location + "&APPID=4a61d170b251cc18c4c9417e7663d602";
    manager->get (QNetworkRequest(QUrl(address)));
}

void WeatherRequest::onReply(QNetworkReply *reply)
{
    if(reply->error () != QNetworkReply::NoError)
    {
        reply->deleteLater ();
        return;
    }
    QTextCodec *codec = QTextCodec::codecForName ("utf-8");
    QString all = codec->toUnicode (reply->readAll ());
    QString temp = all;

}
