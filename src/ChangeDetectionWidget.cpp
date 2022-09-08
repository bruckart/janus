
#include "ChangeDetectionWidget.h"

#include <QGridLayout>
#include <QRandomGenerator>


ChangeDetectionWidget::ChangeDetectionWidget(QWidget* parent)
:
    QWidget(parent),
    m_chart(new QChart()),
    m_chartView(new QChartView()),
    m_lineSeries(new QLineSeries()),
    m_lastPixmap(),
    m_ticker(0)
{

    m_chart->addSeries(m_lineSeries);


    QValueAxis* xAxis = new QValueAxis();
    xAxis->setTitleText("X Axis");
    xAxis->setRange(0, 64);
    xAxis->setTickInterval(1);
    m_chart->addAxis(xAxis, Qt::AlignBottom);

    QValueAxis* yAxis = new QValueAxis();
    yAxis->setRange(0, 30);
    yAxis->setTitleText("Y Axis");
    yAxis->setTickInterval(1);
    m_chart->addAxis(yAxis, Qt::AlignLeft);

    // QLogValueAxis* yAxis = new QLogValueAxis();
    // // yAxis->setRange(0,10000);
    // yAxis->setTitleText("Frequency");
    // yAxis->setLabelFormat("%g");
    // yAxis->setBase(8.0);
    // yAxis->setMinorTickCount(-1);
    // m_chart->addAxis(yAxis, Qt::AlignLeft);

    m_lineSeries->attachAxis(xAxis);
    m_lineSeries->attachAxis(yAxis);

    m_chart->setTitle("Change Detection");
    m_chart->setAnimationOptions(QChart::SeriesAnimations);

    m_chart->legend()->setAlignment(Qt::AlignBottom);
    m_chart->legend()->setVisible(true);
    // m_chart->legend()->hide();

    m_chartView->setRenderHint(QPainter::Antialiasing);
    m_chartView->setChart(m_chart);

    // chart->legend()->hide();
    // chart->createDefaultAxes();


    QGridLayout* mainLayout = new QGridLayout();
    mainLayout->addWidget(m_chartView, 0, 0);
    setLayout(mainLayout);
}

ChangeDetectionWidget::~ChangeDetectionWidget()
{
}

void ChangeDetectionWidget::updateChangeDetectionSlot(const QPixmap& pm)
{
    m_lastPixmap = pm;

    // Compare this image to the last one.

    QImage image = pm.toImage();
    qDebug() << "Image Depth: " << image.depth();
    qDebug() << "Image Bits: " << image.bits();
    qDebug() << "Dimensions: (" << image.width() << "," << image.height() << ")";
    qDebug() << image;


    qreal val =  QRandomGenerator::global()->bounded(0, 25);
    qDebug() << "Adding " << m_ticker << "and" << val;
    *m_lineSeries << QPointF(m_ticker, val);

    m_ticker++;
}