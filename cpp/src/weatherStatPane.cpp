#include "headers/weatherStatPane.h"

WeatherStatPane::WeatherStatPane() {
    //Create the widgets
    downSpeedLbl = new QLabel();
    farenheitLbl = new QLabel();

    layout->addWidget(downSpeedLbl, 0, 0);
    layout->addWidget(farenheitLbl, 1, 0);
    layout->setSpacing(0);
    layout->setMargin(0);

    //setup stylesheet
    styleMap = new StyleMap(StyleReader::read(":/styles/statPane.txt"));
    downSpeedLbl->setStyleSheet(styleMap->getStyle("downSpeedLbl"));
    farenheitLbl->setStyleSheet(styleMap->getStyle("farenheitLbl"));

    setLayout(layout);

}
void WeatherStatPane::updateWidgets() {
    //values for testing
    double downSpeed = 15.643;
    double tempFarenheit = 32.123;
    double tempCelsius = 0.123;

    //setup file input
    QFile file(dataFileName);
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;
    QTextStream dataFile(&file);

    //read in the download and upload speed
    downSpeed = dataFile.readLine().toDouble();
    tempFarenheit = dataFile.readLine().toDouble();
    tempCelsius = dataFile.readLine().toDouble();
    file.close();

    QString downText = "Internet Speed: ";
    downText.append(QString::number(downSpeed));
    downText.append("Mb/sec down");

    //setup the temperature labels
    QString tempText = "Temperature: ";
    tempText.append(QString::number(tempFarenheit));
    tempText.append(QChar(0260)).append("F");

    //setup the celsius labels
    tempText.append(" / ");
    tempText.append(QString::number(tempCelsius));
    tempText.append(QChar(0260)).append("C");

    downSpeedLbl->setText(downText);
    farenheitLbl->setText(tempText);
}

WeatherStatPane::~WeatherStatPane() {
    delete downSpeedLbl;
    delete farenheitLbl;
}
