#ifndef DAILYWIDGET_H
#define DAILYWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>
#include <QGridLayout>

class DailyWidget : public QWidget
{
    Q_OBJECT
public:
    explicit DailyWidget(QWidget *parent = 0);

    QLabel *sityLabel;
    QLabel *dateLabel;

    QFrame *tempFrame;
    QGridLayout *tempFrameLayout;
    QLabel *tempLabel;
    QLabel *tempDimLabel;
    QLabel *maxTempLabel;
    QLabel *minTempLabel;
    QLabel *picLabel;
    QLabel *lineLabel;

    QLabel *fin1LineLabel;
    QLabel *fin2LineLabel;

    QLabel *fin3LineLabel;
    QLabel *fin4LineLabel;

    QLabel *fin5LineLabel;
    QLabel *fin6LineLabel;

    QLabel *fin7LineLabel;
    QLabel *fin8LineLabel;

    QVBoxLayout * humidityLayout;
    QFrame *humidityFrame;
    QLabel *humidityLabel;
    QLabel *humidityValueLabel;
    QLabel *humidityDimLabel;

    QVBoxLayout * windLayout;
    QFrame *windFrame;
    QLabel *windLabel;
    QLabel *windValueLabel;
    QLabel *windDimLabel;

    QFrame *presFrame;
    QVBoxLayout * presLayout;
    QLabel *presLabel;
    QLabel *presValueLabel;
    QLabel *presDimLabel;

    QFrame *precipitationFrame;
    QVBoxLayout * precipitationLayout;
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
    inline void setupH1Layout();
    inline void setupH2Layout();
    inline void setupSmallW(QFrame *parent, QVBoxLayout * layout, QLabel* laybel, QLabel* value, QLabel* dim , QLabel *line1, QLabel *line2);
};

#endif // DAILYWIDGET_H
