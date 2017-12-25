#ifndef PANE_H
#define PANE_H

#include <QWidget>
#include <QGridLayout>
#include <QTimer>

#include "styleMap.h"
#include "styleReader.h"

class Pane : public QWidget {

    Q_OBJECT

    public:
        Pane();
        Pane(Pane &pane);

        ~Pane();

        QGridLayout* getLayout() { return layout; }
        StyleMap* getStyleMap() { return styleMap; }

    public slots:
        virtual void updateWidgets() = 0;

    protected:
        //update interval
        const int UPDATE_INTERVAL = 500;

        //layout
        QGridLayout* layout;

        //stylemap for widgets
        StyleMap* styleMap;

        //timer for update
        QTimer* timer;

        //method to setup the timer
        void setupTimer();
};

#endif