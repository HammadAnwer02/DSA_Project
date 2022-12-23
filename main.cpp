#include <QApplication>
#include <QImage>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QWheelEvent>
#include <QObject>
#include "mainwindow.h"
#include <QFile>
#include <QDebug>
#include <QTextStream>
#include <QVector>
#include <iostream>
#include <QString>
#include <fstream>
using namespace std;
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MainWindow window;
    window.showFullScreen();
    window.show();
    return app.exec();
}






////#include "matrix.h"

//#include <QtCore/qglobal.h>
//#if QT_VERSION >= 0x050000
//#include <QtWidgets/QApplication>
//#else
//#include <QtGui/QApplication>
//#endif
//#include <QLocale>
//#include "QMainWindow"
//#include <QTranslator>
//#include <QLabel>
//#include <QImage>
//#include <QGraphicsView>
//#include <QGraphicsScene>
//#include <QGraphicsPixmapItem>
//#include <QObject>
//#include <QPixmap>
//#include <QPainter>
//#include <QWheelEvent>
//#include <QShortcut>
//int main(int argc, char *argv[])
//{
////    int rows = 6, cols = 8;
//    QApplication a(argc, argv);
//    QMainWindow window;
//    window.showFullScreen();
//    window.show();
////    QVector<QVector<int>> matrix_2d = {{1, 2, 3, 128, 128, 6, 7, 8}, {1, 2, 3,128, 128, 6, 7, 8}, {1, 2, 3,128, 128, 6, 7, 8}, {1, 2, 3, 128, 128, 6, 7, 8}, {1, 2, 3, 128, 128, 6, 7, 8}, {1, 2, 3, 128, 128, 6, 7, 8}};


////    QImage image(cols, rows, QImage::Format_RGB888);

////    for (int y = 0; y < rows; y++) {
////        for (int x = 0; x < cols; x++) {
////            matrix_2d[y][x] = qRgb(0, 255, 0);
////            image.setPixel(x, y, matrix_2d[y][x]);

////        }
////    }

//////    int newWidth = cols * 20;
//////       int newHeight = rows * 20;

//////       QImage scaledImage = image.scaled(newWidth, newHeight, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
//////    // Create the scene and view
//////    QGraphicsPixmapItem *item = new QGraphicsPixmapItem(QPixmap::fromImage(image));
//////    // Create the scene and view
//////    QGraphicsScene *scene = new QGraphicsScene;
//////       scene->addItem(item);
//////       QGraphicsView *view = new QGraphicsView(scene);
//////    view->setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform);
//////    view->setTransformationAnchor(QGraphicsView::AnchorUnderMouse);
//////    view->NoAnchor;
//////    view->setWindowTitle("matrix_2d Viewer");
//////    view->setGeometry(100,100,400,400);
//////    view->show();




////    QGraphicsView view = new QGraphicsView;
////    view.setRenderHint(QPainter::Antialiasing);
////    view.setTransformationAnchor(QGraphicsView::AnchorUnderMouse);

////    QGraphicsScene *scene = new QGraphicsScene();
////    scene->addPixmap(QPixmap::fromImage(image));
////    view.setScene(scene);

//////        // Create the QPixmap and draw the matrix_2d onto it using QPainter
//////        QPixmap pixmap(400, 400);
//////        QPainter painter(&pixmap);
//////        // Draw the matrix_2d here...
//////        painter.end();




//////    QLabel label;
////    // Handle mouse wheel events to zoom in and out
////    view.setMouseTracking(true);
////    view.installEventFilter(new WheelFilter(&view));

////    view.show();





////    matrix_2d m;
////    matrix_2d.show();
//    return a.exec();
//}




