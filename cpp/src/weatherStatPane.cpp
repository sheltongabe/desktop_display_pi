#include "headers/weatherStatPane.h"

WeatherStatPane::WeatherStatPane() {
    //Create the widgets
    downSpeedLbl = new QLabel();
    farenheitLbl = new QLabel();
    celsiusLbl = new QLabel();

    layout->addWidget(downSpeedLbl, 0, 0);
    layout->addWidget(farenheitLbl, 1, 0);
    layout->addWidget(celsiusLbl, 1, 1);
    layout->setSpacing(0);
    layout->setMargin(0);

    //setup stylesheet
    styleMap = new StyleMap(StyleReader::read(":/styles/statPane.txt"));
    downSpeedLbl->setStyleSheet(styleMap->getStyle("downSpeedLbl"));
    farenheitLbl->setStyleSheet(styleMap->getStyle("farenheitLbl"));
    celsiusLbl->setStyleSheet(styleMap->getStyle("celsiusLbl"));

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
    file.close();

    //convert the farhenheit temp to celsius
    tempCelsius = (5 / 9) (tempFarenheit - 32);

    QString downText = "Internet Speed: ";
    downText.append(QString::number(downSpeed));
    downText.append("Mb/sec down");

    //setup the temperature labels
    QString tempFText = "Temperature: ";
    tempFText.append(QString::number(tempFarenheit));
    tempFText.append(QChar(0260)).append("F");

    //setup the celsius labels
    QString tempCText = " /  ";
    tempCText.append(QString::number(tempCelsius));
    tempCText.append(QChar(0260)).append("C");

    downSpeedLbl->setText(downText);
    farenheitLbl->setText(tempFText);
    celsiusLbl->setText(tempCText);
}

WeatherStatPane::~WeatherStatPane() {
    delete downSpeedLbl;
    delete farenheitLbl;
}
