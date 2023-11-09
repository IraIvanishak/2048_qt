#include "iiv2048.h"

#include <QApplication>
#include<QWidget>
#include <QSplashScreen>
#include <QTimer>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QPixmap pix( ":/image/start.png" );
    QSplashScreen splashScreen( pix );
    splashScreen.show();
    QTimer::singleShot(5000, &splashScreen, &QWidget::close);
    MainWindow w;
    w.resize(800, 500);
    w.setWindowTitle("2048");
    w.setWindowIcon(QIcon(":/image/II.png"));
    QTimer::singleShot(5000, &w, SLOT(show()));

    return a.exec();
}
