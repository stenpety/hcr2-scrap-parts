#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent) {

    scrapper = new Scrapper;
    setCentralWidget(scrapper);
    setWindowTitle("Parts to scrap");

}

MainWindow::~MainWindow() {}
