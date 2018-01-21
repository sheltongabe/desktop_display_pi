#include "headers/weatherStatPane.h"

WeatherStatPane::WeatherStatPane() {
    //Create the widgets
    speedLbl = new QLabel();
    tempLbl = new QLabel();

    layout->addWidget(speedLbl, 0, 0);
    layout->addWidget(tempLbl, 1, 0);
    layout->setSpacing(0);
    layout->setMargin(0);

    //setup stylesheet
    styleMap = new StyleMap(StyleReader::read(":/styles/statPane.txt"));
    speedLbl->setStyleSheet(styleMap->getStyle("speedLbl"));
    tempLbl->setStyleSheet(styleMap->getStyle("tempLbl"));

    setLayout(layout);

}
void WeatherStatPane::updateWidgets() {
    //values for testing
    QString downSpeed;
    QString tempFarenheit;
    QString tempCelsius;

    //setup file input
    QFile file(dataFileName);
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;
    QTextStream dataFile(&file);

    //read in the download and upload speed
    downSpeed = dataFile.readLine();
    tempFarenheit = dataFile.readLine();
    tempCelsius = dataFile.readLine();
    file.close();

    QString downText = "Internet Speed: ";

    //if the DownSpeed was valid
    if(downSpeed != "-")
        downText.append(QString::number(downSpeed.toDouble()));
    else
        downText.append(QString("-"));
    downText.append("Mb/sec down");

    //setup the temperature labels
    QString tempText = "Temperature: ";

    //if the temperature was valid
    if(tempFarenheit != "-")
        tempText.append(QString::number(tempFarenheit.toDouble()));
    else   
        tempText.append(QString("-"));
    tempText.append(QChar(0260)).append("F");
    //setup the celsius labels
    tempText.append(" / ");

    //if temperature was valid
    if(tempCelsius != "-")
        tempText.append(QString::number(tempCelsius.toDouble()));
    else    
        tempText.append(QString("-"));
    tempText.append(QChar(0260)).append("C");

    speedLbl->setText(downText);
    tempLbl->setText(tempText);
}

WeatherStatPane::~WeatherStatPane() {
    delete speedLbl;
    delete tempLbl;
}
