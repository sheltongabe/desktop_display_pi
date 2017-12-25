#include "headers/timePane.h"

TimePane::TimePane() {
    timeLbl = new QLabel("Time");
    layout->addWidget(timeLbl);

    dateLbl = new QLabel("Date");
    layout->addWidget(dateLbl);

    //sets the margin around the elements to 0
    layout->setMargin(0);
    layout->setSpacing(0);

    //create styleMap from file
    styleMap = new StyleMap(StyleReader::read(":/styles/timePane.txt"));
    timeLbl->setStyleSheet(styleMap->getStyle("timeLbl"));
    dateLbl->setStyleSheet(styleMap->getStyle("dateLbl"));

    //add layout to widget
    setLayout(layout);
}

/*TimePane::TimePane(TimePane& pane) {
    timeLbl = pane.timeLbl;
    dateLbl = dateLbl;
}*/

void TimePane::updateWidgets() {
    //grab the current date/time
    QDateTime current = QDateTime::currentDateTime();

    //output it to the QLabels
    timeLbl->setText(current.time().toString());
    dateLbl->setText(current.date().toString());
}

TimePane::~TimePane() {
    delete timeLbl;
    delete dateLbl;

    timer->stop();
    delete timer;
}