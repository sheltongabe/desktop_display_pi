#ifndef STYLE_READER
#define STYLE_READER

#include<QVector>
#include <QString>
#include <QFile>
#include <QTextStream>
#include <QIODevice>

class StyleReader {

    public:
        StyleReader();
        StyleReader(StyleReader& reader);

        static QVector<QString> read(QString fileName);

        ~StyleReader();

    private:

};

#endif