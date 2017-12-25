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

void WeatherStatPane::updateWidgets() {
    //values for testing
    double downSpeed = 15.643;
    double upSpeed = 2.354;

    QString downText = "Download Speed: ";
    downText.append(QString::number(downSpeed));

    QString upText = "Upload Speed: ";
    upText.append(QString::number(upSpeed));

    downSpeedLbl->setText(downText);
    upSpeedLbl->setText(upText);
}

WeatherStatPane::~WeatherStatPane() {

}