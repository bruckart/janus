#ifndef MINECRAFTCOMMANDERWIDGET_H
#define MINECRAFTCOMMANDERWIDGET_H


#include <QWidget>
#include <QPoint>
// #include <QPixmap>
#include <QGraphicsScene>

namespace Ui
{
    class MinecraftCommanderWidget;
}

class MinecraftCommanderWidget : public QWidget
{
    Q_OBJECT

public:
    MinecraftCommanderWidget(QWidget* parent=0);
    virtual ~MinecraftCommanderWidget();

    // void registerObserver(QWidget* observerWidget);
signals:

    void updateImageSignal(const QPixmap&);

public slots:
    // void updateObserverPosition();
    // void updateObserverSize();

    /// This method is called 
    // void testSlot();

    void updateObserverPositionSlot(const QPoint&); 
    void updateObserverResizeSlot(const QRect&);
    void updateObserverImageSlot(const QPixmap&);

private slots:
    void leftClickPressed() const;
    void rightClickPressed() const;
    void enterPressed() const;

protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    // void paintEvent(QPaintEvent *event) override;
    void resizeEvent(QResizeEvent *event) override;


private:
    // QWidget* m_observerWidget;

    Ui::MinecraftCommanderWidget* ui;

    QGraphicsScene* m_scene;
};

#endif // MINECRAFTCOMMANDERWIDGET_H
