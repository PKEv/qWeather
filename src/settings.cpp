#include "settings.h"

#include <QApplication>
#include <QThread>
#include <QMutexLocker>
#include <QFile>
#include <QDir>
#include <QSettings>

Settings* Settings::settings{nullptr};
bool Settings::loaded = false;
const QString Settings::globalSettingsFile = "settings.ini";
QThread* Settings::settingsThread{nullptr};

Settings::Settings() : QObject()
{
    settingsThread = new QThread();
    settingsThread->setObjectName("Settings");
    settingsThread->start(QThread::LowPriority);
    moveToThread(settingsThread);

}

Settings& Settings::getInstance()
{
    if (!settings)
    {
        settings = new Settings();
        loaded = false;
    }
    if (!loaded)
        settings->ReadSettings();

    return *settings;
}

void Settings::destroyInstance()
{
    delete settings;
    settings = nullptr;
}

Settings::~Settings()
{
    settingsThread->exit(0);
    settingsThread->wait();
    delete settingsThread;

}
void Settings::ReadSettings()
{
    if (loaded)
        return;

    if (QFile(qApp->applicationDirPath() + QDir::separator() + globalSettingsFile).exists())
    {
        QSettings ps(qApp->applicationDirPath()+QDir::separator()+globalSettingsFile, QSettings::IniFormat);
        ps.setIniCodec("UTF-8");
        cityName = ps.value("CityName", "Saint Petersburg,RU").toString();
        dim = static_cast<Settings::DimEnum> (ps.value("Dim", 0).toInt());
    }

    loaded = true;
}
void Settings::SaveSettings()
{
    QSettings ps(qApp->applicationDirPath() + QDir::separator() + globalSettingsFile, QSettings::IniFormat);
    ps.setIniCodec("UTF-8");
    ps.clear();
    ps.setValue("CityName", cityName);
    ps.setValue("Dim", dim);
}
