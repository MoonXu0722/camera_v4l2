#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(&cam, SIGNAL(newImageReady(QImage)),
            this, SLOT(showNewImage(QImage)));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showNewImage(QImage img)
{
    ui->label->setPixmap(QPixmap::fromImage(img));
}
