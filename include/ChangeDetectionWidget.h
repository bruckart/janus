

#ifndef CHANGEDETECTIONWIDGET_H
#define CHANGEDETECTIONWIDGET_H


#include <QWidget>
#include <QChart>
#include <QChartView>
#include <QLineSeries>
#include <QValueAxis>
// #include <QPointF>

#include <iostream>

///***
/// This class charts the difference in pixels on 1 increment frames. 
/// 
//***
class ChangeDetectionWidget : public QWidget
{
    Q_OBJECT

public:
    ChangeDetectionWidget(QWidget* parent=0);
    virtual ~ChangeDetectionWidget();

public slots:

    void updateChangeDetectionSlot(const QPixmap&);

protected:

private:

    QChart*      m_chart;
    QChartView*  m_chartView;
    QLineSeries* m_lineSeries;

    QPixmap      m_lastPixmap;

    unsigned int m_ticker;
};


#endif // CHANGEDETECTIONWIDGET_H
