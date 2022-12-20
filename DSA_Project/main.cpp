#include "matrix.h"

#include <QtCore/qglobal.h>
#if QT_VERSION >= 0x050000
#include <QtWidgets/QApplication>
#else
#include <QtGui/QApplication>
#endif
#include <QLocale>
#include <QTranslator>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "DSA_Project_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            a.installTranslator(&translator);
            break;
        }
    }
    Matrix w;
    w.show();
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
