#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <QMainWindow>
#include <QGridLayout>
#include <QWidget>

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

    private:
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