#ifndef WEATHER_STAT_PANE_H
#define WEATHER_STAT_PANE_H

#include <QWidget>
#include <QGridLayout>
#include <QLabel>
#include <QString>
#include <QTimer>

#include "pane.h"

class WeatherStatPane : public Pane {
    public:
        WeatherStatPane();
        WeatherStatPane(WeatherStatPane& pane);

        ~WeatherStatPane();
    
    public slots:
        virtual void updateWidgets();

    private:
        const int UPDATE_INTERVAL = 5000;

        //Labels for gui for temperature
        QLabel* farenheitLbl, *celsiusLbl;

        //Labels for internet speed
        QLabel* downSpeedLbl, *upSpeedLbl;
};

#endif