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
    QFile file("output.txt");
       if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
           // Handle error

       }

       // Create a text stream for reading the file
       QTextStream in(&file);

       // Read the number of rows and columns from the first two lines of the file
       int rows = in.readLine().toInt();
       int columns = in.readLine().toInt();

       // Read the data from the rest of the file
       QVector<QVector<int>> matrix;
       while (!in.atEnd()) {
           // Read a line of data and split it into individual values
           QStringList values = in.readLine().split('\t');

           // Convert the values to integers and store them in a vector
           QVector<int> row;
           for (const QString& value : values) {
               row.append(value.toInt());
           }

           // Add the vector to the matrix
           matrix.append(row);
       }

       // Close the file
       file.close();
    MainWindow window(matrix);
    window.showFullScreen();
    window.show();
    return app.exec();
}









