#include "mainwindow.h"
#include "dsa_project.h"
#include <QPushButton>
#include <QVBoxLayout>
#include <QWidget>
#include <QDebug>
MainWindow::MainWindow()
{
    DSA_Project *project = new DSA_Project;
    QPushButton *button1 = new QPushButton("Task 1");
        QPushButton *button2 = new QPushButton("Task 2");
        QPushButton *button3 = new QPushButton("Task 3");

        // Create layout and add buttons
        QVBoxLayout *layout = new QVBoxLayout;
        layout->addWidget(button1);
        layout->addWidget(button2);
        layout->addWidget(button3);
        connect(button1, &QPushButton::clicked, project, &DSA_Project::runtask1);
connect(button2, &QPushButton::clicked, project, &DSA_Project::runtask2);
connect(button3, &QPushButton::clicked, project, &DSA_Project::runtask3);
        // Set layout for main window

        this->setLayout(layout);
this->showFullScreen();
        this->show();
}

