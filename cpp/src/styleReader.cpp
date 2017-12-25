#include "headers/styleReader.h"

StyleReader::StyleReader() {

}

StyleReader::StyleReader(StyleReader& reader) {

}

QVector<QString> StyleReader::read(QString fileName) {
    QVector<QString> results;

    //open file
    QFile file(fileName);
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return results;
    
    //create a textstream with the file
    QTextStream inFile(&file);

    //while we are not at the end of the file
    while(!inFile.atEnd()) {
        QString key = inFile.device()->readLine().append("=");

        char buf[1];
        //while the next char is not a ~, seperator for styles
        inFile.device()->peek(buf, 1);
        while(buf[0] != '~' && !inFile.atEnd()) {
            key += inFile.device()->readLine();

            inFile.device()->peek(buf, 1);

        }
        //consume the '~' marking character
        inFile.device()->readLine();

        results.push_back(key.remove('\n'));
    }

    return results;

}

StyleReader::~StyleReader() {

}