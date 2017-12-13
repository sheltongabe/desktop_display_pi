#ifndef STYLE_MAP_H
#define STYLE_MAP_H

#include <QHash>
#include <QString>

class StyleMap {
    public:
        StyleMap();
        StyleMap(StyleMap& map);

        ~StyleMap();

    private:
        QHash<QString, QString> styles;
};

#endif