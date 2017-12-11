#ifndef TIME_PANE
#define TIME_PANE

#include <QWidget>
#include <QGridLayout>
#include <QDateTime>
#include <QLabel>
#include <QTimer>

class TimePane : public QWidget {
    public:

        const static int UPDATE_TIME = 500;

        TimePane();
        TimePane(TimePane& pane);

        ~TimePane();

    public slots:
        void updateTime();

    private:
        //layout to contain the labels
        QGridLayout* layout;

        //labels for the gui date and time
        QLabel* timeLbl;
        QLabel* dateLbl;

        //timer to update the time and date
        QTimer* timer;
};

#endif