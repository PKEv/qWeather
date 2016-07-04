#ifndef TITLEWIDGET_H
#define TITLEWIDGET_H

#include <QWidget>
#include "horizonalslider.h"
#include <QWheelEvent>

class TitleWIdget : public QWidget
{
    Q_OBJECT
public:
    explicit TitleWIdget(QWidget *parent = 0);
    
    void wheelEvent(QWheelEvent *ev) Q_DECL_OVERRIDE;

    void setTitles(const QStringList &titles);
    void nextTitle();
    void prevTitle();
    void firstTitle();

signals:
    void nextTitleSignal();

    void prevTitleSignal();

    void firstTitleSignal();

protected:
    void resizeEvent(QResizeEvent *re);

private:
    QStringList _titles;

    HorizonalSlider *horizonalSlider;
};

#endif // TITLEWIDGET_H
