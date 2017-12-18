#include "headers/styleMap.h"

StyleMap::StyleMap() {
    
}

StyleMap::StyleMap(QVector<QString> styles) {
    for(int i = 0; i < styles.size(); i++) {
        QStringList pair = styles[i].split('=');
        this->styles[pair[0]] = pair[1];
    }
}

StyleMap::StyleMap(StyleMap& styles) {
    this->styles = styles.styles;
}

QString StyleMap::getStyle(QString key) {
    return styles[key];
}

void StyleMap::storeStyle(QString key, QString style) {
    styles[key] = style;
}

StyleMap::~StyleMap() {

}