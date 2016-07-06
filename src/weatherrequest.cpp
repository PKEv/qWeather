#include "weatherrequest.h"

// example
// http://api.openweathermap.org/data/2.5/forecast/daily?q=Moscow&&units=metric&APPID=4a61d170b251cc18c4c9417e7663d602

QString WeatherRequest::cityName = "Moscow";

WeatherRequest::WeatherRequest(QObject *parent) : QObject(parent)
{
    manager = new QNetworkAccessManager(0);
    status = StatusRequest::Edle;

    QObject::connect(manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(onReply(QNetworkReply*)));
}

void WeatherRequest::GetWeekWeather()
{
    if (status != StatusRequest::Edle)
        return;

    status = StatusRequest::WeekRequest;

    QString location = "q=" + cityName;// + //"&units=metric";//"&cnt=" + QString::number(dayCount);
    QString address = "http://api.openweathermap.org/data/2.5/forecast/daily?" + location + "&APPID=4a61d170b251cc18c4c9417e7663d602";
    manager->get(QNetworkRequest( QUrl(address) ));
}

void WeatherRequest::GetCurrentWeather()
{
    if (status != StatusRequest::Edle)
        return;

    status = StatusRequest::CurrentRequest;

    QString location = "q=" + cityName;// + //"&units=metric";//"&cnt=" + QString::number(dayCount);
    QString address = "http://api.openweathermap.org/data/2.5/weather?" + location + "&APPID=4a61d170b251cc18c4c9417e7663d602";
    manager->get(QNetworkRequest( QUrl(address) ));
}



void WeatherRequest::onReply(QNetworkReply *reply)
{
    if(reply->error() != QNetworkReply::NoError)
    {
        reply->deleteLater();
        return;
    }
    QTextCodec *codec = QTextCodec::codecForName("utf-8");
    QString all = codec->toUnicode( reply->readAll() );
    if (status == StatusRequest::WeekRequest)
        ParsingWeekWeather(all);
    else if (status == StatusRequest::CurrentRequest)
        ParsingCurrentWeather(all);

    reply->deleteLater();
    status = StatusRequest::Edle;
    return;

}

void WeatherRequest::ParsingWeekWeather(QString &data)
{
    QJsonDocument jsonResponse = QJsonDocument::fromJson(data.toUtf8());
    QJsonObject jsonObject = jsonResponse.object();
    QJsonArray jsonArray = jsonObject["list"].toArray();
    weathers.clear();

    foreach (const QJsonValue & value, jsonArray)
    {
        WeatherWeekStruct weatherStr;
        QJsonObject obj = value.toObject();
        weatherStr.clouds = obj.take("clouds").toVariant().toFloat();
        weatherStr.deg = obj.take("deg").toVariant().toFloat();
        weatherStr.dt = obj.take("dt").toVariant().toFloat();
        weatherStr.humid = obj.take("humidity").toVariant().toFloat();
        weatherStr.pressure = obj.take("pressure").toVariant().toFloat();
        weatherStr.speed = obj.take("speed").toVariant().toFloat();
        QJsonObject temp = obj["temp"].toObject();
        weatherStr.temps.day = temp.take("day").toVariant().toFloat();
        weatherStr.temps.eve = temp.take("eve").toVariant().toFloat();
        weatherStr.temps.max = temp.take("max").toVariant().toFloat();
        weatherStr.temps.min = temp.take("min").toVariant().toFloat();
        weatherStr.temps.morn = temp.take("morn").toVariant().toFloat();
        weatherStr.temps.night = temp.take("night").toVariant().toFloat();
        QJsonObject weather = obj["weather"].toArray().takeAt(0).toObject();
        weatherStr.weather.des = weather.take("description").toString();
        weatherStr.weather.icon = weather.take("icon").toString();
        weatherStr.weather.id = weather.take("id").toVariant().toString();
        weatherStr.weather.main = weather.take("main").toVariant().toString();
        weathers.push_back(weatherStr);
    }
}

void WeatherRequest::ParsingCurrentWeather(QString &data)
{
    QJsonDocument jsonResponse = QJsonDocument::fromJson(data.toUtf8());
    QJsonObject jsonObject = jsonResponse.object();

    currentWeather.main.clouds = jsonObject["clouds"].toObject().take("all").toVariant().toFloat();
    currentWeather.dt = jsonObject["dt"].toVariant().toFloat();
    currentWeather.main.temp = jsonObject["main"].toObject().take("temp").toVariant().toFloat();
    currentWeather.main.pressure = jsonObject["main"].toObject().take("pressure").toVariant().toFloat();
    currentWeather.main.humidity = jsonObject["main"].toObject().take("humidity").toVariant().toFloat();
    currentWeather.main.temp_min = jsonObject["main"].toObject().take("temp_min").toVariant().toFloat();
    currentWeather.main.temp_max = jsonObject["main"].toObject().take("temp_max").toVariant().toFloat();

    currentWeather.sys.sunrise = jsonObject["sys"].toObject().take("sunrise").toInt();
    currentWeather.sys.sunset = jsonObject["sys"].toObject().take("sunset").toInt();

    currentWeather.wind.deg = jsonObject["wind"].toObject().take("deg").toInt();
    currentWeather.wind.speed = jsonObject["wind"].toObject().take("speed").toVariant().toFloat();

    QJsonObject weather = jsonObject["weather"].toArray().takeAt(0).toObject();
    currentWeather.weather.des = weather.take("description").toString();
    currentWeather.weather.icon = weather.take("icon").toString();
    currentWeather.weather.id = weather.take("id").toVariant().toString();
    currentWeather.weather.main = weather.take("main").toVariant().toString();
}

void WeatherRequest::setCityName(const QString name)
{
    cityName = name;
}
