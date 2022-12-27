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
#include <QMenu>
#include <QMenuBar>
#include <QMainWindow>
#include "mainwindow.h"
#include <vector>
using namespace std;





int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    std::vector<Cluster> clusters;

    // Create nodes and edges and add them to a cluster
    Node node1{10, 20};
    Node node2{30, 40};
    Edge edge{node1, node2, 5};
    Cluster cluster;
    cluster.nodes.push_back(node1);
    cluster.nodes.push_back(node2);
    cluster.edges.push_back(edge);

    // Add the cluster to the vector
    clusters.push_back(cluster);
    QFile file("output1.txt");
       if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
           // Handle error

       }

       // Create a text stream for reading the file
       QTextStream in(&file);

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
//    MainWindow window(matrix);
    MainWindow window(clusters);
    //menu
//    QMenuBar *menuBar = new QMenuBar(&window);
//    menuBar->setNativeMenuBar(menuBar);
//    QMenu *fileMenu = new QMenu("File", &window);
//    menuBar->addMenu(fileMenu);
//    QAction *openAction = new QAction("Open", &window);
//    fileMenu->addAction(openAction);
//    window.connect(openAction, &QAction::triggered, &window, &MainWindow::openFile);
//    QAction *saveAction = new QAction("Save", &window);
//    fileMenu->addAction(saveAction);
//    QMenu *editMenu = new QMenu("Edit", &window);
//    menuBar->addMenu(editMenu);
//    QMenu *formatMenu = new QMenu("Format", &window);
//    editMenu->addMenu(formatMenu);


    window.showFullScreen();
    window.show();
    return app.exec();
}









