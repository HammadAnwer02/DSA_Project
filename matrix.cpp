#include "matrix.h"
#include "./ui_matrix.h"

matrix::matrix(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::matrix)
{
    ui->setupUi(this);
}

matrix::~matrix()
{
    delete ui;
}

