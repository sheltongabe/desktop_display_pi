#ifndef TIME_PANE
#define TIME_PANE

#include <QWidget>
#include <QLabel>
#include <QTimer>

class TimePane : public QWidget {
    public:
        TimePane();
        TimePane(TimePane& pane);

        ~TimePane();

    private:
        //labels for the gui date and time
        QLabel* timeLbl, dateLbl;

        //timer to update the time and date
        QTimer* timer;
};

#endif