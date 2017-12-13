#ifndef STYLE_READER
#define STYLE_READER

#include <QString>

class StyleReader {

    public:
        StyleReader();
        StyleReader(StyleReader& reader);

        static QString read(QString fileName);

        ~StyleReader();

    private:

};

#endif