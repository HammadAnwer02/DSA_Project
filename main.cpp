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
#include <iostream>
#include "helper.h"
#include "Graph.h"
using namespace std;





int main(int argc, char *argv[])
{

    std::vector<std::vector<double>> data;
    data.resize(150);
    for (auto &row : data)
    {
        row.resize(4);
    }
    fstream input;
    input.open("data1.txt", ios::in);
    if (!input)
    {
        cout << "No such file";
    }
    else
    {
        for (int i = 0; i < 150; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                input >> data[i][j];
            }
        }
    }
    input.close();
    cout << endl;

    shuFFleing(data);

    vector<vector<double>> coeff;
    coeff.resize(150);
    for (auto &row : coeff)
    {
        row.resize(150);
    }

    ofstream output("outputmatrix.txt");
    for (size_t i = 0; i < 150; i++)
    {
        for (size_t j = 0; j < 150; j++)
        {
            coeff[i][j] = pearson(data[i], data[j]);
            output << coeff[i][j] << " ";

        }
        output << endl;
    }
    output.close();
    cout << endl;



    cout << "Enter a threshold value for the edges: ";
    double threshold;
    threshold=0.99;
    for (size_t i = 0; i < 150; i++)
    {
        for (size_t j = 0; j < 150; j++)
        {
            if (coeff[i][j] < threshold)
            {
                coeff[i][j] = 0;
            }
        }
    }

    vector<double> nodeWeights;
    nodeWeights.resize(150);

    for (size_t i = 0; i < 150; i++)
    {
        double sumWeights = 0;
        for (size_t j = 0; j < 150; j++)
        {
            sumWeights += coeff[i][j];
        }
        nodeWeights[i] = sumWeights;
    }

    vector<Cluster> clusters;


    while (!isEmptyClusters(nodeWeights))
    {
        auto maxElementIter = std::max_element(nodeWeights.begin(), nodeWeights.end());

        // Calculate the index of the maximum element using std::distance
        size_t maxElementIndex = std::distance(nodeWeights.begin(), maxElementIter);

        qDebug() << "Your cluster is :\n";

        cout << "Node " << maxElementIndex << " with the value " << *maxElementIter << endl;

        cout << "The nodes adjacent to this are: \n\n";

        nodeWeights[maxElementIndex] = INT_MIN;
        Node maxNode(maxElementIndex, maxElementIndex);

        Cluster currCluster;

        currCluster.nodes.push_back(maxNode);

        for (size_t j = 0; j < 150; j++)
        {
            if (coeff[maxElementIndex][j] != 0)
            {
                cout << "Node " << j << " with the value of " << coeff[maxElementIndex][j] << endl;
                nodeWeights[j] = INT_MIN;
                Node connnectedNode(j, j);
                Edge edgetoMax(maxNode, connnectedNode, coeff[maxElementIndex][j]);
                currCluster.edges.push_back(edgetoMax);
                currCluster.nodes.push_back(connnectedNode);
            }
        }
        clusters.push_back(currCluster);












}
    QApplication app(argc, argv);


    // Create nodes and edges and add them to a cluster


    // Add the cluster to the vector

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









