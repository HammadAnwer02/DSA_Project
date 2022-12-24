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

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    MainWindow(QVector<QVector<int>> &v);
       void openFile();
       void closeFile();
        void displayColored(QVector<QVector<int>> &v);

private slots:
    void zoomIn();
    void zoomOut();


private:
    QGraphicsView *view;
    QTextEdit *textEdit;
    QWidget *textWidget;
    QVBoxLayout *textLayout;
    QPushButton *closeButton;
    QHBoxLayout *buttonLayout;
    QGraphicsScene *scene;

};

#endif // MAINWINDOW_H
