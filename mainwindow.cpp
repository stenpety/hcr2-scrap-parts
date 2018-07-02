#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent) {

    scrapper = new Scrapper;
    setCentralWidget(scrapper);
    createMenus();
    setWindowTitle("Parts to scrap");

}

MainWindow::~MainWindow() {}

void MainWindow::createMenus() {
    partsMenu = menuBar()->addMenu(tr("Parts"));
    settingsAct = new QAction(tr("Settings"), this);
    partsMenu->addAction(settingsAct);
    connect(settingsAct, &QAction::triggered, this, &MainWindow::openSettings);

}

void MainWindow::openSettings() {
    printf("I open settings");
}
