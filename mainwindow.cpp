#include "mainwindow.h"

MainWindow::MainWindow()
{
    // Create a QImage with the desired size and format
    QImage image(400, 400, QImage::Format_RGB888);

    // Set all pixels to green
    for (int i = 0; i < image.width(); i++) {
        for (int j = 0; j < image.height(); j++) {
            image.setPixel(i, j, qRgb(0, 255, 0));
        }
    }

    // Create a QGraphicsView to display the image
    view = new QGraphicsView();
    view->setRenderHint(QPainter::Antialiasing);
    view->setTransformationAnchor(QGraphicsView::AnchorUnderMouse);

    // Set the image as the background image for the view
    QGraphicsScene *scene = new QGraphicsScene();
    scene->addPixmap(QPixmap::fromImage(image));
    view->setScene(scene);

    // Create + and - buttons
    QPushButton *buttonPlus = new QPushButton("+");
    buttonPlus->setMaximumWidth(40);
    QPushButton *buttonMinus = new QPushButton("-");
    buttonMinus->setMaximumWidth(40);

    // Connect buttons to zoom functions
    connect(buttonPlus, &QPushButton::clicked, this, &MainWindow::zoomIn);
    connect(buttonMinus, &QPushButton::clicked, this, &MainWindow::zoomOut);

    // Add buttons to a layout
    QHBoxLayout *buttonLayout = new QHBoxLayout();
    buttonLayout->addStretch();
    buttonLayout->addWidget(buttonPlus);
    buttonLayout->addWidget(buttonMinus);
    buttonLayout->addStretch();

    // Add the view and button layout to the main layout
    QVBoxLayout *mainLayout = new QVBoxLayout();
    mainLayout->addWidget(view);
    mainLayout->addLayout(buttonLayout);
    setLayout(mainLayout);
}

void MainWindow::zoomIn()
{
    view->scale(1.2, 1.2);
}

void MainWindow::zoomOut()
{
    view->scale(1 / 1.2, 1 / 1.2);
}
