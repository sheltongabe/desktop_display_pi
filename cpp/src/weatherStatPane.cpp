#include "headers/weatherStatPane.h"

WeatherStatPane::WeatherStatPane() {
    //Create the widgets
    speedLbl = new QLabel();
    tempLbl = new QLabel();
    intTempLbl = new QLabel();

    layout->addWidget(speedLbl, 0, 0);
    layout->addWidget(tempLbl, 1, 0);
    layout->addWidget(intTempLbl, 2, 0);
    layout->setSpacing(0);
    layout->setMargin(0);

    //setup stylesheet
    styleMap = new StyleMap(StyleReader::read(":/styles/statPane.txt"));
    speedLbl->setStyleSheet(styleMap->getStyle("speedLbl"));
    tempLbl->setStyleSheet(styleMap->getStyle("tempLbl"));
    intTempLbl->setStyleSheet(styleMap->getStyle("intTempLbl"));

    setLayout(layout);

}
void WeatherStatPane::updateWidgets() {
    //values for testing
    QString downSpeed;
    QString tempFarenheit;
    QString tempCelsius;
    QString intTempCel, intTempFar;

    //setup file input
    QFile file(dataFileName);
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;
    QTextStream dataFile(&file);

    //read in the download and upload speed
    downSpeed = dataFile.readLine();
    tempFarenheit = dataFile.readLine();
    tempCelsius = dataFile.readLine();
    intTempCel = dataFile.readLine();
    intTempFar = dataFile.readLine();
    file.close();

    QString downText = "Internet Speed: ";

    //if the DownSpeed was valid
    if(downSpeed != "-")
        downText.append(QString::number(downSpeed.toDouble()));
    else
        downText.append(QString("-"));
    downText.append("Mb/sec down");

    //--External temp
    //setup the temperature label
    QString tempText = "External Temperature: ";

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

    //--Internal Temp--
    //setup the temperature label
    QString intTempText = "Internal Temperature: ";

    //if the temperature was valid
    if(intTempFar != "-")
        intTempText.append(QString::number(intTempFar.toDouble()));
    else   
        intTempText.append(QString("-"));
    intTempText.append(QChar(0260)).append("F");
    //setup the celsius labels
    intTempText.append(" / ");

    //if temperature was valid
    if(intTempCel != "-")
        intTempText.append(QString::number(intTempCel.toDouble()));
    else    
        intTempText.append(QString("-"));
    intTempText.append(QChar(0260)).append("C");

    //--write values to labels    
    speedLbl->setText(downText);
    tempLbl->setText(tempText);
    intTempLbl->setText(intTempText);
}

WeatherStatPane::~WeatherStatPane() {
    delete speedLbl;
    delete tempLbl;
}
