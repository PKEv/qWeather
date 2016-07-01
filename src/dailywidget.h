#ifndef DAILYWIDGET_H
#define DAILYWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>

class DailyWidget : public QWidget
{
    Q_OBJECT
public:
    explicit DailyWidget(QWidget *parent = 0);

    QLabel *sityLabel;
    QLabel *dateLabel;

    QFrame *tempFrame;
    QLabel *tempLabel;
    QLabel *tempDimLabel;
    QLabel *maxTempLabel;
    QLabel *minTempLabel;
    QLabel *picLabel;

    QFrame *humidityFrame;
    QLabel *humidityLabel;
    QLabel *humidityValueLabel;
    QLabel *humidityDimLabel;

    QFrame *windFrame;
    QLabel *windLabel;
    QLabel *windValueLabel;
    QLabel *windDimLabel;

    QFrame *presFrame;
    QLabel *presLabel;
    QLabel *presValueLabel;
    QLabel *presDimLabel;

    QFrame *precipitationFrame;
    QLabel *precipitationLabel;
    QLabel *precipitationValueLabel;
    QLabel *precipitationDimLabel;

    QLabel *lastUpdateLabel;

    QVBoxLayout * vBoxLayout;
    QHBoxLayout * h1BoxLayout;
    QHBoxLayout * h2BoxLayout;


signals:

public slots:
private:
    void setupH1Layout();
};

#endif // DAILYWIDGET_H
