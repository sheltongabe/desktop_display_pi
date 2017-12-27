#include "headers/weatherStatPane.h"

WeatherStatPane::WeatherStatPane() {
    //Create the widgets
    downSpeedLbl = new QLabel();
    upSpeedLbl = new QLabel();

    layout->addWidget(downSpeedLbl, 0, 0);
    layout->addWidget(upSpeedLbl, 0, 1);
    layout->setSpacing(0);
    layout->setMargin(0);

    //setup stylesheet
    styleMap = new StyleMap(StyleReader::read(":/styles/statPane.txt"));
    downSpeedLbl->setStyleSheet(styleMap->getStyle("downSpeedLbl"));
    upSpeedLbl->setStyleSheet(styleMap->getStyle("upSpeedLbl"));


    setLayout(layout);

}
void WeatherStatPane::updateWidgets() {
    //values for testing
    double downSpeed = 15.643;
    double upSpeed = 2.354;

    //setup file input
    QFile file(dataFileName);
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;
    QTextStream dataFile(&file);

    //read in the download and upload speed
    downSpeed = dataFile.readLine().toDouble();
    upSpeed = dataFile.readLine().toDouble();

    file.close();

    QString downText = "Internet Speed: ";
    downText.append(QString::number(downSpeed));
    downText.append("Mbs down");

    QString upText = " / ";
    upText.append(QString::number(upSpeed));
    upText.append("Mbs up");

    downSpeedLbl->setText(downText);
    upSpeedLbl->setText(upText);
}

WeatherStatPane::~WeatherStatPane() {

}