//#include "matrix.h"

#include <QtCore/qglobal.h>
#if QT_VERSION >= 0x050000
#include <QtWidgets/QApplication>
#else
#include <QtGui/QApplication>
#endif
#include <QLocale>
#include <QTranslator>
#include<QLabel>
#include<QImage>

int main(int argc, char *argv[])
{
    int rows = 6, cols = 8;
    QApplication a(argc, argv);
    QVector<QVector<int>> matrix = {{1, 2, 3, 255, 255, 6, 7, 8}, {1, 2, 3,255, 255, 6, 7, 8}, {1, 2, 3,255, 255, 6, 7, 8}, {1, 2, 3, 255, 255, 6, 7, 8}, {1, 2, 3, 255, 255, 6, 7, 8}, {1, 2, 3, 255, 255, 6, 7, 8}};


    QImage image(cols, rows, QImage::Format_RGB888);

    for (int y = 0; y < rows; y++) {
        for (int x = 0; x < cols; x++) {
            matrix[y][x] = qRgb(0, 128, 0);
            image.setPixel(x, y, matrix[y][x]);

        }
    }



    int newWidth = cols * 20;
       int newHeight = rows * 20;

       QImage scaledImage = image.scaled(newWidth, newHeight, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);

    QLabel label;
    label.setPixmap(QPixmap::fromImage(scaledImage));
    label.show();


//    QTranslator translator;
//    const QStringList uiLanguages = QLocale::system().uiLanguages();
//    for (const QString &locale : uiLanguages) {
//        const QString baseName = "DSA_Project_" + QLocale(locale).name();
//        if (translator.load(":/i18n/" + baseName)) {
//            a.installTranslator(&translator);
//            break;
//        }
//    }
//    Matrix w;
//    w.show();
    return a.exec();
}

//#include <QLabel>
//#include <QImage>
//#include <QApplication>
//#include <opencv2/opencv.hpp> // For the cv::Mat class

//int main(int argc, char *argv[])
//{
//    QApplication app(argc, argv);

//    // Create a matrix with some random data
//    cv::Mat mat(100, 100, CV_8UC3, cv::Scalar(0, 0, 255));

//    // Convert the matrix to a QImage
//    QImage image = QImage((const unsigned char*)mat.data, mat.cols, mat.rows, mat.step, QImage::Format_RGB888);

//    // Create a QLabel widget to display the image
//    QLabel label;
//    label.setPixmap(QPixmap::fromImage(image));
//    label.show();

//    return app.exec();
//}
