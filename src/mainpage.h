#ifndef MAINPAGE_H
#define MAINPAGE_H

#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>

#include "dailywidget.h"
#include "titlewidget.h"


class mainpage : public QWidget
{
    Q_OBJECT

public:
    explicit mainpage(QWidget *parent = 0);
    ~mainpage();
     TitleWIdget *titleWidget;

public slots:



private:

    DailyWidget * dailyWidget;
    QVBoxLayout* vBoxLayout;
    QVBoxLayout* h1BoxLayout;
    QPushButton * button;

};

#endif // MAINPAGE_H
