

#include <QMouseEvent>
#include <QGraphicsPixmapItem>

// #include "QwtPlotHistogram.h"
// #include <qwt_plot_histogram.h>
#include "HistogramWidget.h"

#include "MinecraftCommanderWidget.h"
#include <iostream>

#include "ui_MinecraftCommanderWidget.h"


MinecraftCommanderWidget::MinecraftCommanderWidget(QWidget* parent)
:
    QWidget(parent),
    m_scene(new QGraphicsScene),
    ui(new Ui::MinecraftCommanderWidget)
{
    setWindowTitle("Minecraft Commander");

    ui->setupUi(this);

    ui->m_graphicsView->setScene(m_scene);
    // ui->m_graphicsView->show();


    move(100, 100);

    // connect(ui->m_leftClickButton, 
    //         SIGNAL(pressed()),
    //         this,
    //         SLOT(leftClickPressed()));

    connect(this,                  SIGNAL(updateImageSignal(const QPixmap&)),
            ui->m_histogramWidget, SLOT(updateHistogramSlot(const QPixmap&)));

    connect(this,                        SIGNAL(updateImageSignal(const QPixmap&)),
            ui->m_changeDetectionWidget, SLOT(updateChangeDetectionSlot(const QPixmap&)));



    // connect(this,                  SIGNAL(updateAnalyticsSignal(const QPixmap&)),
    //         ui->m_analyticsWidget, SLOT(updateAnalyticsSlot(const QPixmap&)));



//  QObject::connect(&a, &Counter::valueChanged,
//                      &b, &Counter::setValue);


    std::clog << "MinecraftCommander" << std::endl;
}

MinecraftCommanderWidget::~MinecraftCommanderWidget()
{
    delete m_scene;

    delete ui;
}

// void MinecraftCommanderWidget::testSlot()
// {
//     std::clog << "MinecraftCommanderWidget::testSlot" << std::endl;
// }
// void MinecraftCommanderWidget::registerObserver(QWidget* observerWidget)
// {
//     m_observerWidget = observerWidget;


//     // connect(m_observerWidget, SIGNAL(moved()),
//     //         this,             SLOT(observerUpdate());

//     // connect(m_observerWidget, SIGNAL(moved()),
//     //         this,             SLOT(observerUpdate());


// }

void MinecraftCommanderWidget::mousePressEvent(QMouseEvent* event)
{
    std::clog << "MinecraftCommanderWidget::mousePressEvent" << std::endl;
}
void MinecraftCommanderWidget::mouseMoveEvent(QMouseEvent* event)
{
    std::clog << "MinecraftCommanderWidget::mouseMoveEvent" << std::endl;
}
void MinecraftCommanderWidget::mouseReleaseEvent(QMouseEvent* event)
{
    std::clog << "MinecraftCommanderWidget::mouseReleaseEvent" << std::endl;
}
// void MinecraftCommanderWidget::paintEvent(QPaintEvent* event)
// {
//     std::clog << "MinecraftCommanderWidget::paintEvent" << std::endl;
// }
void MinecraftCommanderWidget::resizeEvent(QResizeEvent* event)
{
    std::clog << "MinecraftCommanderWidget::resizeEvent" << std::endl;
}

void MinecraftCommanderWidget::leftClickPressed() const
{
    std::clog << "MinecraftCommanderWidget::leftClickPressed" << std::endl;
}
    
void MinecraftCommanderWidget::rightClickPressed() const
{
    std::clog << "MinecraftCommanderWidget::rightClickPressed" << std::endl;
}

void MinecraftCommanderWidget::enterPressed() const
{
    std::clog << "MinecraftCommanderWidget::enterPressed" << std::endl;
}

void MinecraftCommanderWidget::updateObserverPositionSlot(const QPoint& point)
{
    std::clog << "MinecraftCommanderWidget::updateObserverPositionSlot" << std::endl;
    std::clog << "point: " << point.x() << ", " << point.y() << std::endl;

    ui->m_x->setText(QString::number(point.x()));
    ui->m_y->setText(QString::number(point.y()));

    repaint();
}

void MinecraftCommanderWidget::updateObserverResizeSlot(const QRect& rect)
{
    std::clog << "MinecraftCommanderWidget::updateObserverResizeSlot" << std::endl;
    std::clog << "rect: " << rect.width() << ", " << rect.height() << std::endl;

    ui->m_width->setText(QString::number(rect.width()));
    ui->m_height->setText(QString::number(rect.height()));

    repaint();
}

void MinecraftCommanderWidget::updateObserverImageSlot(const QPixmap& image)
{
    // std::clog << ">>>>> MinecraftCommanderWidget::updateObserverImageSlot" << std::endl;

    // std::clog << "view size: " << ui->m_graphicsView->width() << ", " << ui->m_graphicsView->height() << std::endl;

    // resize to the widget size
    QPixmap scaledImage = image.scaled(ui->m_graphicsView->width(),
                                       ui->m_graphicsView->height(),
                                       Qt::KeepAspectRatio);

    
    // m_scene->addText("Hello, world!");
    m_scene->clear();

    // ui->m_imageLabel->setPixmap(image);
    QGraphicsPixmapItem* item = new QGraphicsPixmapItem(scaledImage);
    m_scene->addItem(item);
    
    // std::clog << "sending signal to update the histogram" << std::endl;

    emit updateImageSignal(image);
    // Update histogram widget.

    // repaint();
}