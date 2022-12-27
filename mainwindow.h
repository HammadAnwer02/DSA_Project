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
#include "Graph.h"
using namespace std;

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
