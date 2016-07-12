#ifndef WEATHERREQUEST_H
#define WEATHERREQUEST_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QTextCodec>

#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

struct TempStruct
{
    float day;
    float eve;
    float max;
    float min;
    float morn;
    float night;
};

struct WeatherStrStruct
{
    QString des;
    QString icon;
    QString id;
    QString main;
};
struct WeatherMain
{
    float temp;
    float pressure ;
    float humidity ;
    float temp_min;
    float temp_max;
    float clouds;
};

struct WeatherSys
{
    int sunrise ;
    int sunset  ;
};

struct Wind
{
    float speed ;
    int deg  ;
};

struct WeatherWeekStruct
{
    float clouds;
    float deg;
    float dt;
    float humid;
    float pressure;
    float speed;
    WeatherStrStruct weather;
    TempStruct temps;
};

struct WeatherCurrentStruct
{
    WeatherSys sys;
    WeatherMain main;
    WeatherStrStruct weather ;
    Wind wind;
    float dt;
};

enum StatusRequest
{
    Edle,
    WeekRequest,
    CurrentRequest
};


class WeatherRequest : public QObject
{
    Q_OBJECT
public:
    explicit WeatherRequest(QObject *parent = 0);

    void GetWeekWeather();
    void GetCurrentWeather();

    QList <WeatherWeekStruct> weathers;
    WeatherCurrentStruct currentWeather;

    void static setCityName(const QString name);
signals:
    void DataReady();

private slots:
    void onReply(QNetworkReply *reply);

public slots:

private:
    QNetworkAccessManager *manager;
    StatusRequest status;
    static QString cityName;

    void ParsingWeekWeather(QString &data);
    void ParsingCurrentWeather(QString &data);
};

#endif // WEATHERREQUEST_H
