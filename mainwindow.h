#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "scrapper.h"

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void openSettings();

private:
    Scrapper *scrapper;

    QMenu *partsMenu;
    QAction *settingsAct;

    void createMenus();
};

#endif // MAINWINDOW_H
