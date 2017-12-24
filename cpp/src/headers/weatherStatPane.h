#ifndef WEATHER_STAT_PANE_H
#define WEATHER_STAT_PANE_H

#include <QWidget>
#include <QGridLayout>
#include <QLabel>
#include <QString>
#include <QTimer>

class WeatherStatPane : public QWidget {

    Q_OBJECT

    public:
        //update interval of 5 seconds
        const int UPDATE_TIME = 5000;

        WeatherStatPane();
        WeatherStatPane(WeatherStatPane& pane);

        ~WeatherStatPane();

    public slots:
        void updateWidgets();

    private:
        //layout for pane
        QGridLayout* layout;

        //Labels for gui for temperature
        QLabel* farenheitLbl, *celsiusLbl;

        //Labels for internet speed
        QLabel* downSpeedLbl, *upSpeedLbl;

        //timer for update
        QTimer* timer;
};

#endif