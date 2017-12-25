#include "headers/mainWindow.h"

MainWindow::MainWindow() {
    centralWidget = new QWidget();
    layout = new QGridLayout();
    timePane = new TimePane();
    statPane = new WeatherStatPane();

    //set the layout margin to 0
    layout->setMargin(0);
    layout->setSpacing(0);

    //configure grid layout
    configureUI();
}

/*MainWindow::MainWindow(MainWindow& window) {
    layout = window.layout;
    timePane = window.timePane;
    statPane = window.statPane;
}*/

void MainWindow::configureUI() {
    layout->addWidget(timePane, 0, 0);
    layout->addWidget(statPane, 1, 0);

    centralWidget->setLayout(layout);
    setCentralWidget(centralWidget);
}

MainWindow::~MainWindow() {
    delete layout;
    delete timePane;
    delete statPane;
}