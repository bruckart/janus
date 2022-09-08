

#ifndef HISTOGRAMWIDGET_H
#define HISTOGRAMWIDGET_H


#include <QWidget>
// #include <QGraphicsScene>
#include <QPainter>
#include <QMap>
#include <QChart>
#include <QChartView>
#include <QBarSet>
#include <QBarSeries>
// #include <QBarCategoryAxis>
#include <QValueAxis>

#include <iostream>


///***
/// This class creates a histogram
class HistogramWidget : public QWidget
{
    Q_OBJECT

public:
    HistogramWidget(QWidget* parent=0);
    virtual ~HistogramWidget();

    std::ostream& print(std::ostream& os) const;

public slots:

    void updateHistogramSlot(const QPixmap&);


protected:

    void updateChart();
    void setData(const QList<qreal> data);

    // void paintEvent(QPaintEvent* event) override;

private:

    QMap<qreal, qreal> m_redHistogram;
    QMap<qreal, qreal> m_greenHistogram;
    QMap<qreal, qreal> m_blueHistogram;

    // QGraphicsScene* m_scene;

    QChart*     m_chart;
    QChartView* m_chartView;

    // QBarSet* m_redBarSet;
    // QBarSet* m_greenBarSet;
    // QBarSet* m_blueBarSet;

    QBarSeries* m_series;
    // QValueAxis* m_xAxis;
    // QValueAxis* m_yAxis;
    // QLogValueAxis* m_yAxis;
};


inline std::ostream& operator<<(std::ostream& os, const HistogramWidget& h)
{
    return h.print(os);
}

#endif // HISTOGRAMWIDGET_H
