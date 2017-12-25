#ifndef TIME_PANE
#define TIME_PANE

#include <QWidget>
#include <QGridLayout>
#include <QDateTime>
#include <QLabel>
#include <QTimer>

#include "pane.h"

class TimePane : public Pane {
    public:
        TimePane();
        TimePane(TimePane& pane);

        ~TimePane();

    public slots:
        virtual void updateWidgets();

    private:
        //labels for the gui date and time
        QLabel* timeLbl;
        QLabel* dateLbl;
};

#endif