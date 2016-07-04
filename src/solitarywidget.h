#ifndef SOLITARYWIDGET_H
#define SOLITARYWIDGET_H

#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>

class SolitaryWidget : public QWidget
{
    Q_OBJECT
public:
    explicit SolitaryWidget(QWidget *parent = 0);

signals:

public slots:

private:
    QHBoxLayout *hLayout;
    QLabel * textLabel;
    QLabel * iconLebel;
    QVBoxLayout *vLayout;
    QLabel * maxValLabel;
    QLabel * minValLabel;
    QLabel * lineLabel;


};

#endif // SOLITARYWIDGET_H
