#ifndef STYLE_MAP_H
#define STYLE_MAP_H

#include <QHash>
#include <QString>
#include <QStringList>
#include <QVector>

class StyleMap {
    public:
        StyleMap();
        StyleMap(QVector<QString> styles);
        StyleMap(StyleMap& styles);

        QString getStyle(QString key);
        void storeStyle(QString key, QString style);

        QHash<QString, QString> getHash() { return styles; }

        ~StyleMap();

    private:
        QHash<QString, QString> styles;
};

#endif