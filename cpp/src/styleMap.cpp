#include "headers/styleMap.h"

StyleMap::StyleMap() {
    
}

StyleMap::StyleMap(QVector<QString> styles) {
    for(int i = 0; i < styles.size(); i++) {
        QStringList pair = styles[i].split('=');
        styles[pair[0].toString()] = pair[1].toString();
    }
}

StyleMap::StyleMap(StyleMap& styles) {
    this->styles = styles.styles;
}

QString getStyle(QString key) {
    return styles[key];
}

void storeStyle(QString key, QString style) {
    styles[key] = style;
}

StyleMap::~StyleMap() {

}