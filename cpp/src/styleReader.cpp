#include "headers/styleReader.h"

StyleReader::StyleReader() {

}

StyleReader::StyleReader(StyleReader& reader) {

}

QVector<QString> read(QString filename) {
    QVector<QString> results;

    //open file
    QFile file(fileName);
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text)
        return results;
    
    //create a textstream with the file
    QTextStream inFile(&file);

    //while we are not at the end of the file
    while(!inFile.atEnd()) {
        QString key = inFile.readLine() + "=";

        //while the next char is not a ~, seperator for styles
        while(inFile.device()->peek(1) != '~') {
            key += inFile.readLine();
        }

        results.push_back(key);
    }

    return results;
}

StyleReader::~StyleReader() {

}