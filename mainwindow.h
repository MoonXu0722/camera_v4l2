#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <camera.h>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
public slots:
    void showNewImage(QImage img);
private:
    Ui::MainWindow *ui;
    camera cam;
};
#endif // MAINWINDOW_H
