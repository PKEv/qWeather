#ifndef SETTINGS_H
#define SETTINGS_H

#include <QObject>
#include <QMutex>
#include <QString>

class Settings : public QObject
{
    Q_OBJECT
public:
        static Settings& getInstance();
        static void destroyInstance();

        void ReadSettings();
        void SaveSettings();

    QString cityName;

    int getDim ()
    {
        return int(dim);
    }

    void setDim(int DIM)
    {
        dim = static_cast<Settings::DimEnum> (DIM);
    }


signals:

public slots:

private:
    Settings();
    ~Settings();
    static QThread* settingsThread;
    static QMutex bigLock;
    static Settings* settings;
    static const QString globalSettingsFile;

    bool static loaded;



    enum DimEnum
    {
        C,
        F
    };
    DimEnum dim;

};

#endif // SETTINGS_H
