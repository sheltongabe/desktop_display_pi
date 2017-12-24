#include "headers/timePane.h"

TimePane::TimePane() {
    //build the layout
    layout = new QGridLayout();

    timeLbl = new QLabel("Time");
    layout->addWidget(timeLbl);

    dateLbl = new QLabel("Date");
    layout->addWidget(dateLbl);

    //sets the margin around the elements to 0
    layout->setMargin(0);
    layout->setSpacing(0);

    //add layout to widget
    setLayout(layout);

    //configure the timer to update the date
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(updateTime()));
    timer->start(UPDATE_TIME);
}

/*TimePane::TimePane(TimePane& pane) {
    timeLbl = pane.timeLbl;
    dateLbl = dateLbl;
}*/

void TimePane::updateTime() {
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