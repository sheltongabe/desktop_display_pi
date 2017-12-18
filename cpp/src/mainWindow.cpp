#include "headers/mainWindow.h"

MainWindow::MainWindow() {
    centralWidget = new QWidget();
    layout = new QGridLayout();
    timePane = new TimePane();
    statPane = new WeatherStatPane();

    //create styleMap from file
    styleMap = new StyleMap(StyleReader::read(":/styles/timePane.txt"));

    //configure grid layout
    configureUI();
}

/*MainWindow::MainWindow(MainWindow& window) {
    layout = window.layout;
    timePane = window.timePane;
    statPane = window.statPane;
}*/
#include <iostream>
void MainWindow::configureUI() {
    timePane->setStyleSheet(styleMap->getStyle("timeLbl"));
    std::cout << timePane->styleSheet().toStdString() << std::endl;
    layout->addWidget(timePane, 0, 0);
    //layout.addItem(statPane, 1, 0);

    centralWidget->setLayout(layout);
    setCentralWidget(centralWidget);
}

MainWindow::~MainWindow() {
    delete layout;
    delete timePane;
    delete statPane;
}