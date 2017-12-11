#include "headers/mainWindow.h"

MainWindow::MainWindow() {
    layout = new QGridLayout();
    timePane = new TimePane();
    statPane = new StatPane();

    //configure grid layout
    configureUI();
}

MainWindow::MainWindow(MainWindow& window) {
    layout = window.layout;
    timePane = window.timePane;
    statPane = window.statPane;
}

void MainWindow::configureUI() {
    layout.addItem(timePane, 0, 0);
    //layout.addItem(statPane, 1, 0);

    setCentralWidget(layout);
}

MainWindow::~MainWindow() {
    delete layout;
    delete timePane;
    delete statPane;
}