#include "mainwindow.h"
#include <QThread>
#include <QGraphicsEllipseItem>
MainWindow::MainWindow(std::vector<Cluster>& clusters) : clusters(clusters)
{
    mainLayout = new QVBoxLayout;
    // Create the "Show Graph" button
      showGraphButton = new QPushButton("Show Graph");

      // Add the button to the layout
      mainLayout->addWidget(showGraphButton);

      // Connect the button to the showGraph slot function
      connect(showGraphButton, &QPushButton::clicked, this, &MainWindow::showGraph);
      setLayout(mainLayout);
//    // Create a QImage with the desired size and format
//    QImage image(150, 150, QImage::Format_RGB888);
//    qDebug() << v.size() << " " << v[0].size();


////QThread::msleep(5000);

//try{
//    // Set all pixels to green
//    for (int i = 0; i < image.height(); i++) {
//        for (int j = 0; j < image.width(); j++) {
//            if (v[i][j]==1){
//            image.setPixel(i, j, qRgb(0, 254, 0));
//        }
//            else if (v[i][j]==0){
//                image.setPixel(i, j, qRgb(0, 0, 0));
//            }
//        }
//    }
//}
//    catch (const std::out_of_range &exception){
//        qDebug()<<"Out of range" << exception.what();
//    }
//    // Create a QGraphicsView to display the image
//    view = new QGraphicsView();
//    view->setRenderHint(QPainter::Antialiasing);
//    view->setTransformationAnchor(QGraphicsView::AnchorUnderMouse);

//    // Set the image as the background image for the view
//    QGraphicsScene *scene = new QGraphicsScene();
//    scene->addPixmap(QPixmap::fromImage(image));
//    view->setScene(scene);

//    // Create + and - buttons
//    QPushButton *buttonPlus = new QPushButton("+");
//    buttonPlus->setMaximumWidth(40);
//    QPushButton *buttonMinus = new QPushButton("-");
//    buttonMinus->setMaximumWidth(40);

//    // Connect buttons to zoom functions
//    connect(buttonPlus, &QPushButton::clicked, this, &MainWindow::zoomIn);
//    connect(buttonMinus, &QPushButton::clicked, this, &MainWindow::zoomOut);

//    // Add buttons to a layout
//    QHBoxLayout *buttonLayout = new QHBoxLayout();
//    buttonLayout->addStretch();
//    buttonLayout->addWidget(buttonPlus);
//    buttonLayout->addWidget(buttonMinus);
//    buttonLayout->addStretch();

//    // Add the view and button layout to the main layout
//    QVBoxLayout *mainLayout = new QVBoxLayout();
//    mainLayout->addWidget(view);
//    mainLayout->addLayout(buttonLayout);
//    setLayout(mainLayout);
}

void MainWindow::zoomIn()
{
    view->scale(1.2, 1.2);
}

void MainWindow::zoomOut()
{
    view->scale(1 / 1.2, 1 / 1.2);
}

void MainWindow::openFile()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"), "", tr("Text Files (*.txt)"));

    textWidget = new QWidget(this);
    textLayout = new QVBoxLayout(textWidget);

    textEdit = new QTextEdit(this);
        layout()->addWidget(textEdit);
        if (!fileName.isEmpty()) {
            QFile file(fileName);
            if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
                QTextStream in(&file);
                QString text = in.readAll();
                file.close();
                textEdit->setText(text);
            }
        }
        textLayout->addWidget(textEdit);
        closeButton = new QPushButton("Close", this);
        buttonLayout = new QHBoxLayout();
        buttonLayout->addWidget(closeButton);
        textLayout->addLayout(buttonLayout);
        layout()->addWidget(textWidget);
        connect(closeButton, &QPushButton::clicked, this, &MainWindow::closeFile);
}

void MainWindow::closeFile()
{
    textEdit->clear();
    textEdit->close();
    closeButton->hide();
}
void MainWindow::showGraph()
{
    int nodeRadius= 5;
  // Create a QGraphicsView widget and a QGraphicsScene
  QGraphicsView* view = new QGraphicsView;
  QGraphicsScene* scene = new QGraphicsScene;
    int color = 0;

  // Iterate through the clusters and create a QGraphicsItem for each node and edge
  for (const auto& cluster : clusters) {

      // Create a QGraphicsEllipseItem for each node in the cluster
    for (const auto& node : cluster.nodes) {
      QGraphicsEllipseItem* ellipse = new QGraphicsEllipseItem(node.x - nodeRadius, node.y - nodeRadius, 2 * nodeRadius, 2 * nodeRadius);
      if (color==0){


      ellipse->setBrush(QBrush(Qt::black));  // Set the fill color
      }
      else if(color==1) {
          ellipse->setBrush(QBrush(Qt::red));
      }
      else if(color==2){
          ellipse->setBrush(QBrush(Qt::green));
      }
      ellipse->setPen(QPen(Qt::black));  // Set the outline color and width
      scene->addItem(ellipse);
    }

    // Create a QGraphicsLineItem for each edge in the cluster
    for (const auto& edge : cluster.edges) {
      QLineF line(edge.from.x, edge.from.y, edge.to.x, edge.to.y);
      QGraphicsLineItem* lineItem = new QGraphicsLineItem(line);
      lineItem->setPen(QPen(Qt::black, edge.weight));  // Set the pen style, width, and color
      scene->addItem(lineItem);
    }
    color++;
  }

  // Set the scene for the view and add the view to the layout
  view->setScene(scene);
  layout()->addWidget(view);
}
