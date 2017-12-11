#ifndef WEATHER_STAT_PANE_H
#define WEATHER_STAT_PANE_H

#include <QWidget>
#include <QLabel>
#include <QTimer>

class WeatherStatPane : public QWidget {
    public:
        WeatherStatPane();
        WeatherStatPane(WeatherStatPane& pane);

        ~WeatherStatPane();

    private:
        //Labels for gui for temperature
        QLabel* farenheitLbl, celsiusLbl;

        //Labels for internet speed
        QLabel* downSpeedLbl, upSpeedLbl;
};

#endif