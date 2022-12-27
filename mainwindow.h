#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QApplication>
#include <QImage>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QFileDialog>
#include <QTextStream>
#include <QTextEdit>
#include <iostream>
using namespace std;
class Node
{
public:
  int x;
  int y;
  // Other node properties, such as weight, label, etc.
};
class Edge
{
public:
  Node from;
  Node to;
  int weight;
  // Other edge properties, such as label, color, etc.
};
class Cluster
{
public:
  std::vector<Node> nodes;
  std::vector<Edge> edges;
  // Other cluster properties, such as size, label, etc.
};

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    MainWindow(std::vector<Cluster>& clusters);
       void openFile();
       void closeFile();

private slots:
    void zoomIn();
    void zoomOut();
    void showGraph();



private:
    QGraphicsView *view;
    QTextEdit *textEdit;
    QWidget *textWidget;
    QVBoxLayout *textLayout;
    QPushButton *closeButton;
    QHBoxLayout *buttonLayout;
    QPushButton* showGraphButton;
    QVBoxLayout* mainLayout;
    std::vector<Cluster>& clusters;
};

#endif // MAINWINDOW_H
