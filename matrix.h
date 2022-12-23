#ifndef MATRIX_H
#define MATRIX_H

#include <QtCore/qglobal.h>
#if QT_VERSION >= 0x050000
#include <QtWidgets/QMainWindow>
#else
#include <QtGui/QMainWindow>
#endif

QT_BEGIN_NAMESPACE
namespace Ui { class Matrix; }
QT_END_NAMESPACE

class Matrix : public QMainWindow
{
    Q_OBJECT

public:
    Matrix(QWidget *parent = nullptr);
    ~Matrix();

private:
    Ui::Matrix *ui;
};
#endif // MATRIX_H
