
#include "HistogramWidget.h"

#include <QValueAxis>
#include <QBarCategoryAxis>
#include <QBarSeries>
#include <QBarSet>
#include <QDebug>
#include <QGridLayout>
#include <QLogValueAxis>
#include <QRandomGenerator>


const double EPSILON = 1;
// class HistogramProcessor(QImage* image)
// {
// public:
//     HistogramProcessor(QImage* image);


// private:
//     QImage m_image;
// };


HistogramWidget::HistogramWidget(QWidget* parent)
:
    QWidget(parent),
    m_redHistogram(),
    m_greenHistogram(),
    m_blueHistogram(),
    // m_scene(new QGraphicsScene(this)),
    m_chart(new QChart()),
    m_chartView(new QChartView()),
    // m_redBarSet(new QBarSet("Red")),
    // m_greenBarSet(new QBarSet("Green")),
    // m_blueBarSet(new QBarSet("Blue")),
    m_series(new QBarSeries())
    // m_xAxis(new QValueAxis()),
    // m_yAxis(new QLogValueAxis())
{

    // resize(128, 128);
    // setGeometry(0, 0, 300, 100);

    // setMinimumSize(255, 155);

    // QPalette pal = QPalette();

    // set black background
    // // Qt::black / "#000000" / "black"
    // pal.setColor(QPalette::Window, Qt::black);

    // setAutoFillBackground(true); 
    // setPalette(pal);
    // show();

    ///
    // m_redBarSet = new QBarSet("Red");
    // m_redBarSet->setColor(QColor(255, 0, 0));
    // m_redBarSet->setLabelColor(QColor(55, 55, 55));
    // QPen pen(Qt::green, 3, Qt::DashDotLine, Qt::RoundCap, Qt::RoundJoin);
    // m_redBarSet->setPen(pen);

    // m_greenBarSet = new QBarSet("Green");
    // m_redBarSet->setColor(QColor(255, 0, 0));
    // m_greenBarSet->setColor(QColor(0, 255, 0));
    // m_blueBarSet->setColor(QColor(0, 0, 255));

#pragma region

    // m_blueBarSet = new QBarSet("Blue");
    // m_blueBarSet->setColor(QColor(0, 0, 255));

    // QBarSet* m_redBarSet = new QBarSet("Red");
    // QBarSet* g = new QBarSet("Green");
    // QBarSet* b = new QBarSet("Blue");
    // QBarSet *set3 = new QBarSet("Mary");
    // QBarSet *set4 = new QBarSet("Samantha");

    // *m_redBarSet << 1 << 20 << 33 << 44 << 52 << 255;
    // *m_greenBarSet << 25 << 90 << 100 << 4 << 01 << 17;
    // *m_blueBarSet << 35 << 55 << 85 << 135 << 85 << 55;
    // *set3 << 5 << 6 << 7 << 3 << 4 << 5;
    // *set4 << 9 << 7 << 5 << 3 << 1 << 2;
    
    // QBarSeries* series = new QBarSeries();

    // QBarSeries* greenSeries = new QBarSeries();
    // QBarSeries* blueSeries = new QBarSeries();
    // greenSeries->append(m_greenBarSet);
    // blueSeries->append(m_blueBarSet);
    // series->append(set3);
    // series->append(set4);
    // QBarSet* m_redSet = new QBarSet("Red");

    // *m_redBarSet << 1.0 << 73.0 << 268.0 << 4325.0 << 733.0;
    // series->append(m_redBarSet);

    // *m_redBarSet << QPointF(1.0, 1.0) 
    //              << QPointF(2.0, 73.0)
    //              << QPointF(3.0, 268.0)
    //              << QPointF(4.0, 17.0)
    //              << QPointF(5.0, 4325.0) 
    //              << QPointF(6.0, 723.0);
    // redSeries->append(m_redBarSet);
    // *redSeries << 1.0
    //             << 73.0
    //             << 268.0
    //             << 17.0
    //             << 4325.0 
    //             << 723.0;

    // m_chart->addSeries(series);

    // m_chart->setTitle("Image Histogram");
    // m_chart->setAnimationOptions(QChart::SeriesAnimations);


    // QStringList categories;
    // // categories << "Jan" << "Feb" << "Mar" << "Apr" << "May" << "Jun";
    // for (unsigned int i = 0; i <= 255; ++i)
    // {
    //     categories << QString::number(i);
    // }


    // m_xAxis = new QValueAxis();
    // m_xAxis->setRange(0, 255);
    // m_xAxis->setTickInterval(10);
    // m_xAxis->setTickType(QValueAxis::TicksFixed);
    // m_xAxis->setTickType(QValueAxis::TicksDynamic);
    // m_xAxis->setTickCount(255);

    // QLineSeries *series = new QLineSeries();
    // *series << QPointF(1.0, 1.0) << QPointF(2.0, 73.0) << QPointF(3.0, 268.0) << QPointF(4.0, 17.0)
    //         << QPointF(5.0, 4325.0) << QPointF(6.0, 723.0);


    // m_xAxis->append(categories);
    // m_chart->addAxis(m_xAxis, Qt::AlignBottom);
    // m_redBarSet->attachAxis(m_xAxis);



    // m_yAxis = new QValueAxis();
    // m_yAxis->setRange(0,400);
    // m_yAxis->setTickCount(25);
    // QLogValueAxis* yAxis = new QLogValueAxis();
    // yAxis->setTitleText("Values");

    // yAxis->setLabelFormat("%g");
    // yAxis->setBase(8.0);
    // yAxis->setMinorTickCount(-1);
    // m_chart->addAxis(yAxis, Qt::AlignLeft);
// series->attachAxis(axisY);

    // m_chart->addAxis(yAxis, Qt::AlignLeft);
    // redSeries->attachAxis(yAxis);


    // m_chart->legend()->setAlignment(Qt::AlignBottom);

    // QChartView *chartView = new QChartView(chart);
    // m_chartView->setRenderHint(QPainter::Antialiasing);
    // m_chartView->setChart(m_chart);
#pragma endregion
//---

    m_chart->addSeries(m_series);

    // for (qreal i = 0; i <= 255; ++i)
    // {
    //     // m_redHistogram[i]   = 0 + EPSILON;
    //     // m_greenHistogram[i] = 0 + EPSILON;
    //     // m_blueHistogram[i]  = 0 + EPSILON;

    //     // *m_redBarSet   << 0 + EPSILON;
    //     // *m_greenBarSet << 0 + EPSILON;
    //     // *m_blueBarSet  << 0 + EPSILON;

    //     // qreal value1 =  QRandomGenerator::global()->bounded(10, 10000);
    //     // *m_redBarSet << value1;

    //     // qreal value2 =  QRandomGenerator::global()->bounded(10, 500);
    //     // *m_greenBarSet << value2;

    //     // qreal value3 =  QRandomGenerator::global()->bounded(50, 100);
    //     // *m_blueBarSet << value3;
    // }
    // m_series->append(m_redBarSet);
    // m_series->append(m_greenBarSet);
    // m_series->append(m_blueBarSet);



    QValueAxis* xAxis = new QValueAxis();
    xAxis->setTitleText("Pixel Value");
    xAxis->setRange(0, 255);
    xAxis->setTickInterval(1);
    m_chart->addAxis(xAxis, Qt::AlignBottom);

    QLogValueAxis* yAxis = new QLogValueAxis();
    // yAxis->setRange(0,10000);
    yAxis->setTitleText("Frequency");
    yAxis->setLabelFormat("%g");
    yAxis->setBase(8.0);
    yAxis->setMinorTickCount(-1);
    m_chart->addAxis(yAxis, Qt::AlignLeft);

    m_series->attachAxis(xAxis);
    m_series->attachAxis(yAxis);


    m_chart->setTitle("Image Histogram");
    m_chart->setAnimationOptions(QChart::SeriesAnimations);

    m_chart->legend()->setAlignment(Qt::AlignBottom);
    m_chart->legend()->setVisible(true);
    // m_chart->legend()->hide();

    m_chartView->setRenderHint(QPainter::Antialiasing);
    m_chartView->setChart(m_chart);

    QGridLayout* mainLayout = new QGridLayout();
    mainLayout->addWidget(m_chartView, 0, 0);
    setLayout(mainLayout);
}

HistogramWidget::~HistogramWidget()
{
    // delete m_chartView;

    delete m_chart;

    // delete m_redBarSet;
    // delete m_greenBarSet;
    // delete m_blueBarSet;

    // delete m_xAxis;
    // delete m_yAxis;
}

void HistogramWidget::updateHistogramSlot(const QPixmap& pm)
{
    QImage image = pm.toImage();
    // qDebug() << "Image Depth: " << image.depth();
    // qDebug() << "Image Bits: " << image.bits();
    // qDebug() << "Dimensions: (" << image.width() << "," << image.height() << ")";
    // qDebug() << image;

    //***
    // Buckets:
    // R: from 0 to 255
    // G: from 0 to 255
    // B: from 0 to 255
    //***
    // if (image.valid(100, 100))
    // {
    //     QRgb pixel = image.pixel(100, 100);
    //     qDebug() << pixel;
    //     qDebug() << "R" << qRed(pixel);
    //     qDebug() << "G" << qGreen(pixel);
    //     qDebug() << "B" << qBlue(pixel);
    // }

    // QMap<unsigned int, unsigned int> rHisto;
    // QMap<unsigned int, unsigned int> gHisto;
    // QMap<unsigned int, unsigned int> bHisto;

    // for (int i = 0; i < 255; ++i) 
    // {
    //     // redHisto.insert()
    //     m_redHistogram[i]   = 0;
    //     m_redBarSet->remove(i);
    //     // m_greenHistogram[i] = 0;
    //     // m_blueHistogram[i]  = 0;
    // }


    // m_redHistogram.clear();


    // for (unsigned int i = 0; i <= 255; ++i)
    // {
    //     m_redHistogram[i] = 0;
    //     // m_redBarSet->remove(i);

    //     *m_redBarSet << m_redHistogram[i];
    //     // m_redBarSet->remove(qreal(i), qreal(m_redHistogram[i]));
    //     // m_greenBarSet->remove(qreal(i), qreal(m_greenHistogram[i]));
    //     // m_blueBarSet->remove(qreal(i), qreal(m_blueHistogram[i]));
    // }


    // m_redBarSet = new QBarSet("Red");
    // m_redBarSet->setColor(QColor(255, 0, 0));

    for (unsigned int i = 0; i <= 255; ++i)
    {
        m_redHistogram[i]   = 0 + EPSILON;
        m_greenHistogram[i] = 0 + EPSILON;
        m_blueHistogram[i]  = 0 + EPSILON;
    }



    // QPair<unsigned int, unsigned int> redHisto;
    // QPair<unsigned int, unsigned int> greenHisto;
    // QPair<unsigned int, unsigned int> blueHisto;

    // repaint();

    // const uchar* imageBits = image.constBits();
    // const uchar* imageScanLine = image.constScanLine(0);

    // THIS LOOP IS TOO INEFFICIENT
    // for (unsigned int x = 0; x < image.width(); ++x)
    // {
    //     for (unsigned int y = 0; y < image.height(); ++y)
    //     {
    //         QRgb pixel = image.pixel(x, y);
    //         redHisto[qRed(pixel)]     = redHisto[qRed(pixel)]++;
    //         greenHisto[qGreen(pixel)] = greenHisto[qGreen(pixel)]++; 
    //         blueHisto[qBlue(pixel)]   = blueHisto[qBlue(pixel)]++; 


    //         // qDebug() << "R" << qRed(pixel);
    //         // qDebug() << "G" << qGreen(pixel);
    //         // qDebug() << "B" << qBlue(pixel);
    //         // QRgb pixel = image.pixel(x, y);
    //         // qDebug() << pixel; // 42 81 02 17 54
    //     }
    // }

    //***
    // Iterate through the image and increment the pixel bin which is the number
    // of times the pixel value has occured. 
    //
    //  qRed(line[x]) returns the pixel value (0 to 255) of the specific pixel.
    //  ++ increments this entry in the QMap. Consequently, this look returns 
    //  number of times each red pixel value was encountered.
    //
    //    |
    //    |
    //    |
    //    |______________
    //     0    ...   255
    //***
    for (int y = 0; y < image.height(); ++y)
    {
        QRgb* line = reinterpret_cast<QRgb*>(image.scanLine(y));
        for (int x = 0; x < image.width(); ++x)
        {
            // *m_redBarSet << qRed(line[x]);
            // QRgb& rgb = line[x];
            m_redHistogram[qRed(line[x])]++;
            m_greenHistogram[qGreen(line[x])]++;
            m_blueHistogram[qBlue(line[x])]++;
            // rgb = qRgba(qRed(rgb), qGreen(0), qBlue(rgb), qAlpha(rgb));
        }
    }


    std::clog << "the map size is: " << m_redHistogram.count() << std::endl;


    // Remove the exisint QBarSets.
    QList<QBarSet*> existingSets = m_series->barSets();
    QListIterator<QBarSet*> i(existingSets);
    while (i.hasNext())
    {
        QBarSet* set = i.next();
        m_series->remove(set);
    }


    // for (unsigned int i = 0; i <= 255; ++i)
    // {
    //     *m_redBarSet << m_redHistogram[i];
    // //     // m_greenBarSet->insert(qreal(i), qreal(m_greenHistogram[i]));
    // //     // m_blueBarSet->insert(qreal(i), qreal(m_blueHistogram[i]));

    // //     // std::clog << "i=" << i << ", " << m_redHistogram[i] << std::endl;
    // }

    // qDebug() << "Not sure";
    // qDebug() << this;

    // std::clog << "--- " << *this << std::endl;
    // print(std::clog);
    // repaint();

    // QChartView* chartView = new QChartView();

    // chartView->setRenderHint(QPainter::Antialiasing);
    // chartView->setChart(m_chart);

    // updateChart();
    QBarSet* rBarSet = new QBarSet("Red");
    rBarSet->setColor(QColor(255, 0, 0));

    QPen redPen;
    redPen.setColor(Qt::red);
    redPen.setWidth(2);
    rBarSet->setPen(redPen);

    QBarSet* gBarSet = new QBarSet("Green");
    gBarSet->setColor(QColor(0, 255, 0));

    QPen greenPen;
    greenPen.setColor(Qt::green);
    greenPen.setWidth(2);
    gBarSet->setPen(greenPen);

    QBarSet* bBarSet = new QBarSet("Blue");
    bBarSet->setColor(QColor(0, 0, 255));

    QPen bluePen;
    bluePen.setColor(Qt::blue);
    bluePen.setWidth(2);
    bBarSet->setPen(bluePen);



    for (unsigned int i = 0; i <= 255; ++i)
    {
        // *newData << m_redHistogram[i];
        *rBarSet << m_redHistogram[i];
        *gBarSet << m_greenHistogram[i];
        *bBarSet << m_blueHistogram[i];
    }

    QList<qreal> totalValues = m_redHistogram.values() + 
                               m_greenHistogram.values() + 
                               m_blueHistogram.values();

    QList<double>::iterator min = std::min_element(totalValues.begin(), totalValues.end());
    QList<double>::iterator max = std::max_element(totalValues.begin(), totalValues.end());

    QAbstractAxis* axis = (m_chart->axes(Qt::Vertical)).at(0);
    axis->setMax(*max);
    std::clog << "axis: " << (axis->titleText()).toStdString() << std::endl;
    std::clog << "Number of elements: " << totalValues.size() << std::endl;
    std::clog << "Minimum red value: " << *min << std::endl;
    std::clog << "Maximum red value: " << *max << std::endl;

    m_series->append(rBarSet);
    m_series->append(gBarSet);
    m_series->append(bBarSet);
}

void HistogramWidget::setData(const QList<qreal> data)
{
    std::clog << "setData" << std::endl;

    // series->replace(points);
}

void HistogramWidget::updateChart()
{
    // std::clog << "HistogramWidget::updateChart()" << std::endl;

    // m_chart->removeAllSeries();
    // m_series->hide();
    // m_series->clear();

    // // m_redBarSet->deleteLater();
    // // QBarSet* bs = new QBarSet();
    // // *bs << 1 << 2 << 3 << 4 << 5;

    // for (unsigned int i = 0; i <= 255; ++i)
    // {
    //     qDebug() << "--- (" << i << ") = " << m_redHistogram[i];
    //     // *m_redBarSet << m_redHistogram[i];
    //     // m_redBarSet->insert(i, m_redHistogram[i]);
    // // //     // m_greenBarSet->insert(qreal(i), qreal(m_greenHistogram[i]));
    // // //     // m_blueBarSet->insert(qreal(i), qreal(m_blueHistogram[i]));

    // // //     // std::clog << "i=" << i << ", " << m_redHistogram[i] << std::endl;
    // }
    // m_redBarSet->remove(0, m_redBarSet->count());

    // QList<qreal> vals = m_redHistogram.values();
    // // m_redBarSet->append(vals);


    // std::clog << "number in red set: " << m_redBarSet->count() << std::endl;
    // std::clog << "number of series:  " << m_series->count() << std::endl;

    // // crash 1
    // // m_series->append(m_redBarSet);
    // // crash 2
    // // m_chart->addSeries(m_series);

    // m_series->show();

    // m_chartView->update();
}

std::ostream& HistogramWidget::print(std::ostream& os) const
{
    os << "HistogramWidget\n";
    os << "Red:\n";

    for (unsigned int i = 0; i <= 255; ++i)
    {
        os << "Key (" << i << ")" << ": " << m_redHistogram[i] << "\n";
    }

    // for (unsigned int i = 0; i <= 255; ++i)
    // {
    //     os << "Key (" << i << ")" << ": " << m_blueHistogram[i] << "\n";
    // }

    // for (unsigned int i = 0; i <= 255; ++i)
    // {
    //     os << "Key (" << i << ")" << ": " << m_greenHistogram[i] << "\n";
    // }

    return os;
}

// void HistogramWidget::paintEvent(QPaintEvent* event)
// {
//     std::clog << "??? HistogramWidget::paintEvent()" << std::endl;

//     QPainter painter(this);
//     // QRect geo = this->geometry();

//     // int x, y, width, height;

//     // x = geo.x()-10;
//     // y = geo.y()-10;
//     // width = geo.width()-3;
//     // height = geo.height()-5;

//     // painter.fillRect(x, y, width, height, QColor(220,220,220));

//     // painter.drawText(x+10, y+10, "Machine " + QString::number(id));


//     // painter.setBrush(Qt::DiagCrossPattern);
 
//     // QPen pen;
 
//     // pen.setColor(Qt::green);
//     // pen.setWidth(5);
 
//     // painter.setPen(pen);
//     // painter.drawRect(QRect(10,10,80,120));
// }
