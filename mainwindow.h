#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QApplication>
#include <QImage>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    MainWindow(QVector<QVector<int>> &v);

private slots:
    void zoomIn();
    void zoomOut();

private:
    QGraphicsView *view;
};

#endif // MAINWINDOW_H
