#include "headers/timePane.h"

TimePane::TimePane() {
    //build the layout
    layout = new QGridLayout();

    timeLbl = new QLabel("Time");
    layout->addWidget(timeLbl);

    dateLbl = new QLabel("Date");
    layout->addWidget(dateLbl);

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
    timeLbl->setText(QDateTime::currentDateTime().toString());
}

TimePane::~TimePane() {
    delete timeLbl;
    delete dateLbl;

    timer->stop();
    delete timer;
}