#ifndef MAINPAGE_H
#define MAINPAGE_H

#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>

#include "dailywidget.h"
#include "titlewidget.h"
#include "contentwidget.h"
#include "hourlywidget.h"
#include "settingswether.h"

#include "weatherrequest.h"


class mainpage : public QWidget
{
    Q_OBJECT

public:
    explicit mainpage(QWidget *parent = 0);
    ~mainpage();
     TitleWIdget *titleWidget;
     ContentWidget * contentWidget;
     WeatherRequest *request;
public slots:



private:

    DailyWidget * dailyWidget;
    HourlyWidget * hourlyWidget;
    SettingsWether * settingsWether;
    QVBoxLayout* vBoxLayout;
    QVBoxLayout* h1BoxLayout;
    QPushButton * button;

    QList<QWidget* > widgetList;

};

#endif // MAINPAGE_H
