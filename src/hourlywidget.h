#ifndef HOURLYWIDGET_H
#define HOURLYWIDGET_H

#include <QWidget>
#include <QScrollArea>
#include <QVBoxLayout>

#include "solitarywidget.h"

class HourlyWidget : public QWidget
{
    Q_OBJECT
public:
    explicit HourlyWidget(QWidget *parent = 0);

signals:

public slots:
private:
    QList<SolitaryWidget *> solitaryWidgetList;
    QScrollArea *scrollArea;
    QVBoxLayout *vLayout;
};

#endif // HOURLYWIDGET_H
