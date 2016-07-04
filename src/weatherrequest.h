#ifndef WEATHERREQUEST_H
#define WEATHERREQUEST_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QTextCodec>


class WeatherRequest : public QObject
{
    Q_OBJECT
public:
    explicit WeatherRequest(QObject *parent = 0);

signals:
private slots:
    void onReply(QNetworkReply *reply);

public slots:
private:
    QNetworkAccessManager *manager;
};

#endif // WEATHERREQUEST_H
