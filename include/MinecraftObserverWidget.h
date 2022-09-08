

#ifndef MINECRAFTFISHERWIDGET_H
#define MINECRAFTFISHERWIDGET_H


#include <QWidget>
#include <QPoint>
#include <QThread>
#include <QTimer>


// namespace Ui
// {
//     class MyHelloWorldWidget;
// // }


// class Worker :public QObject
// {
//     Q_OBJECT

// public slots:
//     void doWork(const QString &parameter)
//     {
//         QString result;
//         /* ... here is the expensive or blocking operation ... */
//         emit resultReady(result);
//     }

// signals:
//     void resultReady(const QString &result);

// };

class MinecraftObserverWidget : public QWidget
{
    Q_OBJECT

public:
    MinecraftObserverWidget(QWidget* parent=0);
    virtual ~MinecraftObserverWidget();

    void registerCommander(QWidget* widget);

public slots:

    void updateImage();

signals:

    void observerMovedSignal(const QPoint& pos);
    void observerResizedSignal(const QRect& rect);

    void observerImageSignal(const QPixmap& image);

protected:

    void paintEvent(QPaintEvent* event) override;

    void mousePressEvent(QMouseEvent* event) override;
    void mouseMoveEvent(QMouseEvent* event) override;
    void mouseReleaseEvent(QMouseEvent* event) override;
    // void paintEvent(QPaintEvent* event) override;
    void resizeEvent(QResizeEvent* event) override;

    void dragEnterEvent(QDragEnterEvent* event) override;
    void dragLeaveEvent(QDragLeaveEvent* event) override;
    void dragMoveEvent(QDragMoveEvent* event) override;
    
    
    void moveEvent (QMoveEvent* event) override;

    // bool event(QEvent* event) override;

private:


    QWidget* m_commanderWidget;

    // void screenshot();

    QPoint m_offset;
    // Ui::MyHelloWorldWidget* ui;

    // QThread m_workerThread;
    QTimer* m_timer;
};




#endif // MINECRAFTFISHERWIDGET_H
