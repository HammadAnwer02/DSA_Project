#ifndef MATRIX_H
#define MATRIX_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class matrix; }
QT_END_NAMESPACE

class matrix : public QMainWindow
{
    Q_OBJECT

public:
    matrix(QWidget *parent = nullptr);
    ~matrix();

private:
    Ui::matrix *ui;
};
#endif // MATRIX_H
