#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <QMainWindow>
#include <QGridLayout>
#include <QWidget>
#include <QMouseEvent>

#include "timePane.h"
#include "weatherStatPane.h"
#include "styleMap.h"
#include "styleReader.h"

class MainWindow : public QMainWindow {

    Q_OBJECT

    public:
        MainWindow();
        MainWindow(MainWindow& window);

        ~MainWindow();

    protected:
        void mouseDoubleClickEvent(QMouseEvent* event);

    private:
        //strings for backlight control
        const char* BL_ON = "echo 0 > /sys/class/backlight/rpi_backlight/bl_power";
        const char* BL_OFF = "echo 1 > /sys/class/backlight/rpi_backlight/bl_power";

        //flag for backlight toggle
        enum BL_STATE {
            ON,
            OFF
        } blState;

        QWidget* centralWidget;
        QGridLayout* layout;
        StyleMap* styleMap;

        //Pane for time and date data
        TimePane* timePane;

        //pane for weather and internet speeds
        WeatherStatPane* statPane;

        //configures ui and grid layout
        void configureUI();
};

#endif