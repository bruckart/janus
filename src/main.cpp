

#include <QApplication>
#include <QSplashScreen>
#include <QTimer>
#include <QFrame>

#include "MinecraftObserverWidget.h"
#include "MinecraftCommanderWidget.h"


#include <iostream>

// int main(int argc, char* argv[]) 
// {
//     std::clog << "minecraftfisher" << std::endl;


// }


int main(int argc, char* argv[])
{


    QApplication app(argc, argv);
    app.setOrganizationName("");
    app.setApplicationName("minecrafter");
    app.setApplicationVersion("1.0.0");

    QPixmap pixmap("splash.jpg");
    QSplashScreen splash(pixmap, Qt::WindowStaysOnTopHint);
    splash.show();
    QTimer::singleShot(3000, &splash, &QWidget::close); // keep displayed for 5 seconds


    // Register the commander with the observer to update the
    // size and position.
    MinecraftCommanderWidget c;
    c.show();

    MinecraftObserverWidget o;
    o.registerCommander(&c);
    o.show();

    // QFrame frame;
    // frame.setFrameRect(QRect(100, 100, 100, 100));
    // frame.setLineWidth(3);
    // frame.setFrameShape(QFrame::Box);




    return app.exec();
}