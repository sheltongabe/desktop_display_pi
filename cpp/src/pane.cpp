#include "headers/pane.h"

Pane::Pane() {
    layout = new QGridLayout();
    setupTimer();
}

void Pane::setupTimer() {
//configure update timer
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(updateWidgets()));
    timer->start(UPDATE_INTERVAL);
}

Pane::~Pane() {

}