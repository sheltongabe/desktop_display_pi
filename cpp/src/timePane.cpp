#include "headers/timePane.h"

TimePane::TimePane() {
    timeLbl = new QLabel("Time");
    dateLbl = new QLabel("Date");

    //configure the timer to update the date
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, updateTime());
    timer->start(UPDATE_TIME);
}

TimePane::TimePane(TimePane& pane) {
    timeLbl = pane.timeLbl;
    dateLbl = dateLbl;
}

void updateTime() {
    timeLbl->setText(QDateTime::currentDateTime().toString());
}

TimePane::~TimePane() {
    delete timeLbl;
    delete dateLbl;

    timer->stop();
    delete timer;
}