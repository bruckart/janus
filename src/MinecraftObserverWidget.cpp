


#include <QApplication>
#include <QScreen>
#include <QWindow>
#include <QGuiApplication>
#include <QGraphicsEffect>
#include <QMainWindow>
#include <QPainter>
#include <QPainterPath>
#include <QMouseEvent>


#include "MinecraftObserverWidget.h"
#include <iostream>

// #include "ui_MyHelloWorldWidget.h"


MinecraftObserverWidget::MinecraftObserverWidget(QWidget* parent)
:
    QWidget(parent)
    // ui(new Ui::MyHelloWorldWidget)
{
    // ui->setupUi(this);
    setWindowTitle("Minecraft Observer");
    resize(128, 128);

    // setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    // setWindowFlags(Qt::Window);

    setWindowFlags(Qt::Window | Qt::WindowStaysOnTopHint | Qt::FramelessWindowHint);
    // setAttribute(Qt::WA_NoSystemBackground, true);
    // setAttribute(Qt::WA_TranslucentBackground, true);

    // setStyleSheet("background-color: rgba(0,0,0,0)");
    // setStyleSheet("border: 5px solid red");

    // setAttribute(Qt::WA_NoSystemBackground);
    // setAttribute(Qt::WA_TranslucentBackground);
    // setAttribute(Qt::WA_PaintOnScreen);

    // setAttribute(Qt::WA_TransparentForMouseEvents);

    setPalette(Qt::transparent);
    // setAttribute( Qt::WA_TranslucentBackground, true );
    // setAttribute( Qt::WA_OpaquePaintEvent, true );
    // setAutoFillBackground(false);
    // setStyleSheet("QWidget{background-color: transparent;}");
    // setAttribute(Qt::WA_NoSystemBackground);

    // setWindowOpacity(1);

    // setWindowOpacity(0);
    // setWindowFlags(Qt::Window | Qt::FramelessWindowHint);

    // setAttribute(Qt::WA_NoSystemBackground);
    // setAttribute(Qt::WA_TranslucentBackground);
    // setAttribute(Qt::WA_PaintOnScreen);

    // setAttribute(Qt::WA_TransparentForMouseEvents);

    // setWindowFlags(Qt::FramelessWindowHint);
    // setAttribute(Qt::WA_NoSystemBackground);
    // setAttribute(Qt::WA_TranslucentBackground);
    // setAttribute(Qt::WA_TransparentForMouseEvents);

    // setStyleSheet("background-color: rgba(0,0,0,0)");

    // QGraphicsBlurEffect* p_blur = new QGraphicsBlurEffect;
    // p_blur->setBlurRadius(3);
    // p_blur->setBlurHints(QGraphicsBlurEffect::QualityHint);

    // // m_p_my_widget->
    // setGraphicsEffect(p_blur);


    // QPalette pal = QPalette();

    // set black background
    // Qt::black / "#000000" / "black"
    // pal.setColor(QPalette::Window, Qt::black);
    // pal.setColor(QPalette::Window, Qt::transparent);

    // setAutoFillBackground(true); 
    // setPalette(pal);

    // setBackgorund(Qt::transparent);
    // setAutoFillBackground(true);
    // Worker* worker = new Worker();
    // worker->moveToThread(&m_workerThread);

    // m_workerThread.start();
    
    m_timer = new QTimer(this);
    QObject::connect(m_timer, SIGNAL(timeout()),
                     this,    SLOT(updateImage()));

    
    m_timer->start(1000); // milliseconds, 1000 is 1 second.

    std::clog << "MinecraftObserverWidget" << std::endl;
}

MinecraftObserverWidget::~MinecraftObserverWidget()
{
    m_timer->stop();
    // delete ui;

    // m_workerThread.quit();
    // m_workerThread.wait();
    delete m_timer;
}

void MinecraftObserverWidget::registerCommander(QWidget* widget)
{
    m_commanderWidget = widget;

    // Connect this moved signal to the commander.
    // connect(this, SIGNAL(test()),
    //         m_commanderWidget, SLOT(testSlot()));
    // connect(this, SIGNAL(testSignal()),
    //         m_commanderWidget, SLOT(testSlot()));


    connect(this,              SIGNAL(observerMovedSignal(const QPoint&)),
            m_commanderWidget, SLOT(updateObserverPositionSlot(const QPoint&)));

    connect(this,              SIGNAL(observerResizedSignal(const QRect&)),
            m_commanderWidget, SLOT(updateObserverResizeSlot(const QRect&)));

    connect(this,              SIGNAL(observerImageSignal(const QPixmap&)),
            m_commanderWidget, SLOT(updateObserverImageSlot(const QPixmap&)));
}

void MinecraftObserverWidget::mousePressEvent(QMouseEvent* event)
{
    std::clog << "MinecraftCommanderWidget::mousePressEvent" << std::endl;

    m_offset = event->pos();
}

void MinecraftObserverWidget::mouseMoveEvent(QMouseEvent* event)
{
    std::clog << "MinecraftCommanderWidget::mouseMoveEvent" << std::endl;

    if (event->buttons() & Qt::LeftButton)
    {
        this->move(mapToParent(event->pos() - m_offset));
    }
}

void MinecraftObserverWidget::mouseReleaseEvent(QMouseEvent* event) 
{
    std::clog << "MinecraftCommanderWidget::mouseReleaseEvent" << std::endl;
    // emit observerMoved(pos());
    // emit observerMovedSignal(pos());
}

// void MinecraftObserverWidget::paintEvent(QPaintEvent* event)
// {
//     std::clog << "MinecraftCommanderWidget::paintEvent" << std::endl;

// }

void MinecraftObserverWidget::resizeEvent(QResizeEvent* event)
{
    std::clog << "MinecraftCommanderWidget::resizeEvent" << std::endl;
    // emit observerResized();
    emit observerResizedSignal(rect());
}

void MinecraftObserverWidget::dragEnterEvent(QDragEnterEvent* event)
{
    std::clog << "MinecraftObserverWidget::dragEnterEvent" << std::endl;
}

void MinecraftObserverWidget::dragLeaveEvent(QDragLeaveEvent* event)
{
    std::clog << "MinecraftObserverWidget::dragLeaveEvent" << std::endl;
}

void MinecraftObserverWidget::dragMoveEvent(QDragMoveEvent* event)
{
    std::clog << "MinecraftObserverWidget::dragMoveEvent" << std::endl;
}

void MinecraftObserverWidget::moveEvent(QMoveEvent* event)
{
    std::clog << "MinecraftObserverWidget::moveEvent" << std::endl;

    std::clog << "The location is now: " << x() << ", " << y() << std::endl;
    std::clog << "width (" << width() << ", " << height() << ")" << std::endl;

    emit observerMovedSignal(pos());
}

void MinecraftObserverWidget::updateImage()
{
    // std::clog << "MinecraftObserverWidget::updateImage" << std::endl;

    QScreen* screen = QGuiApplication::primaryScreen();
    if (const QWindow *window = windowHandle())
        screen = window->screen();
    if (!screen)
        return;

    // QApplication::beep();

    QPixmap pm;
    // std::clog << "x: " << x() << std::endl;
    // std::clog << "y: " << y() << std::endl;
    // std::clog << "width:  " << width() << std::endl;
    // std::clog << "height: " << height() << std::endl;
    // // hide();
    pm = screen->grabWindow(0, x(), y(), width(), height());

    // QImage img = pm.toImage();
    // img.save("/Users/robertbruckart/git/bruckart/minecraftfishing/cmake/_build/test.png");

    // QPalette palette;
    // palette.setBrush(QPalette::Window, QBrush(originalPixmap));
    // setPalette(palette);
    // show();
    // std::clog << "/// emitting observerScreenshot signal" << std::endl;
    emit observerImageSignal(pm);
    // const QString format = "png";
    // QString initialPath = QStandardPaths::writableLocation(QStandardPaths::PicturesLocation);
    // if (initialPath.isEmpty())
    //     initialPath = QDir::currentPath();
    // initialPath += tr("/untitled.") + format;

    // QFileDialog fileDialog(this, tr("Save As"), initialPath);
    // fileDialog.setAcceptMode(QFileDialog::AcceptSave);
    // fileDialog.setFileMode(QFileDialog::AnyFile);
    // fileDialog.setDirectory(initialPath);
    // QStringList mimeTypes;
    // const QList<QByteArray> baMimeTypes = QImageWriter::supportedMimeTypes();
    // for (const QByteArray &bf : baMimeTypes)
    //     mimeTypes.append(QLatin1String(bf));
    // fileDialog.setMimeTypeFilters(mimeTypes);
    // fileDialog.selectMimeTypeFilter("image/" + format);
    // fileDialog.setDefaultSuffix(format);
    // if (fileDialog.exec() != QDialog::Accepted)
    //     return;
    // const QString fileName = fileDialog.selectedFiles().first();
    // if (!originalPixmap.save(fileName)) {
    //     QMessageBox::warning(this, tr("Save Error"), tr("The image could not be saved to \"%1\".")
    //                          .arg(QDir::toNativeSeparators(fileName)));
    // }
}

// bool MinecraftObserverWidget::event(QEvent* event)
// {
//     std::clog << "MinecraftObserverWidget::event()" << std::endl;

//     // switch (event->type())
//     // {
//     // case QEvent::Show:
//     //     widget->show();
//     //     QTimer::singleShot(50, this, SLOT(widgetSizeMove())); 
//     //     //Wait until the Main Window be shown
//     //     break;
//     // case QEvent::WindowActivate:
//     // case QEvent::Resize:
//     // case QEvent::Move:
//     //     widgetSizeMove();
//     //     break;
//     // default:
//     //     break;
//     // }

//     return QMainWindow::event(event);
// }



void MinecraftObserverWidget::paintEvent(QPaintEvent* event)
{
    // std::cout << "MinecraftObserverWidget::paintEvent" << std::endl;

    QPainter p(this);
    p.setRenderHint(QPainter::Antialiasing);

    // QString text("Position Window Above Fishing Bopper");
    // QFontMetrics metrics(p.font());
    // p.drawText(rect(), Qt::AlignCenter, text);

    QPainterPath path;
    path.addRoundedRect(QRectF(0, 0, width(), height()), 10, 10);

    // path.addRoundedRect(QRectF(x(), y(), width(), height()), 10, 10);
    QPen pen(Qt::white, 1);
    p.setPen(pen);
    // p.fillPath(path, Qt::red);
    p.drawPath(path);
    // p.drawRect(rect());
}
