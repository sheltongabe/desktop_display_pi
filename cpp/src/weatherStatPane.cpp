#include "headers/weatherStatPane.h"

WeatherStatPane::WeatherStatPane() {
    //Create the widgets
    downSpeedLbl = new QLabel();
    upSpeedLbl = new QLabel();

    layout->addWidget(downSpeedLbl, 0, 0);
    layout->addWidget(upSpeedLbl, 1, 0);
    layout->setSpacing(0);
    layout->setMargin(0);
    setLayout(layout);

}
#include <iostream>
void WeatherStatPane::updateWidgets() {
    //values for testing
    double downSpeed = 15.643;
    double upSpeed = 2.354;

    std::cout << dataFileName.toStdString() << std::endl;

    //setup file input
    QFile file(dataFileName);
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;
    QTextStream dataFile(&file);

    //read in the download and upload speed
    downSpeed = dataFile.readLine().toDouble();
    upSpeed = dataFile.readLine().toDouble();

    file.close();

    QString downText = "Download Speed: ";
    downText.append(QString::number(downSpeed));

    QString upText = "Upload Speed: ";
    upText.append(QString::number(upSpeed));

    downSpeedLbl->setText(downText);
    upSpeedLbl->setText(upText);
}

WeatherStatPane::~WeatherStatPane() {

}