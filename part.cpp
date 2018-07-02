#include "part.h"

Part::Part(QObject *parent) : QObject(parent) {
    setupModel();
    partType = common;
    minLevel = 5;
    maxLevel = 14;
    currentLevel = minLevel;
}

void Part::setPartType(const int index) {
    if (index != partType) {
        switch (index) {
        case 0:
            partType = common;
            minLevel = 5;
            maxLevel = 14;
            break;
        case 1:
            partType = rare;
            minLevel = 3;
            maxLevel = 9;
            break;
        case 2:
            partType = epic;
            minLevel = 1;
            maxLevel = 6;
            break;
        case 3:
            partType = legend;
            minLevel = 1;
            maxLevel = 3;
            break;
        default:
            break;
        }
        currentLevel = minLevel;
        emit minLevelValueChanged(minLevel);
        emit maxLevelValueChanged(maxLevel);
        emit currentLevelValueChanged(currentLevel);
    }
}


void Part::setupModel() {
    QStringList types;
    types << tr("Common") << tr("Rare") << tr("Epic") << tr("Legend");
    typeModel = new QStringListModel(types, this);

    model = new QStandardItemModel(4, 2, this);
    /*
    model->setItem(0, 0, "5");
    model->setItem(0, 1, "14");
    model->setItem(1, 0, "3");
    model->setItem(1, 1, "9");
    model->setItem(2, 0, "1");
    model->setItem(2, 1, "6");
    model->setItem(3, 0, "1");
    model->setItem(3, 1, "3");
    */

}

QStandardItemModel *Part::getModel() {
    return model;
}

QStringListModel *Part::getTypeModel() {
    return typeModel;
}

int Part::getMinLevel() {
    return minLevel;
}

int Part::getMaxLevel(){
    return maxLevel;
}

int Part::getCurrentLevel() {
    return currentLevel;
}
