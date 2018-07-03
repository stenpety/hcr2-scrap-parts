#include "part.h"

Part::Part(QObject *parent) : QObject(parent) {

    partsAtLevel = {3, 10, 17, 25, 34, 45, 58, 76, 100, 140, 200, 280, 410, 620};

    setupModel();
    partType = common;
    minLevel = 4;
    maxLevel = 13;
    currentLevel = minLevel;
    desiredMaxLevel = maxLevel;
    partsHave = 0;
    calcTotalParts();
    calcSafeToScrap();

}

void Part::setPartType(const int index) {
    if (index != partType) {
        switch (index) {
        case 0:
            partType = common;
            minLevel = 4;
            maxLevel = 13;
            break;
        case 1:
            partType = rare;
            minLevel = 2;
            maxLevel = 8;
            break;
        case 2:
            partType = epic;
            minLevel = 0;
            maxLevel = 5;
            break;
        case 3:
            partType = legend;
            minLevel = 0;
            maxLevel = 2;
            break;
        default:
            break;
        }
        currentLevel = minLevel;
        desiredMaxLevel = maxLevel;
        emit minLevelValueChanged(minLevel);
        emit maxLevelValueChanged(maxLevel);
        emit currentLevelValueChanged(currentLevel);
        emit desiredMaxLevelValueChanged(desiredMaxLevel);
        calcTotalParts();
    }
}

void Part::setCurrentLevel(const int level) {
    if (currentLevel != level) {
        currentLevel = level;
        calcTotalParts();
        emit currentLevelValueChanged(currentLevel);
    }

}

void Part::setDesiredMaxLevel(const int level) {
    if (desiredMaxLevel != level) {
        desiredMaxLevel = level;
        calcTotalParts();
        emit desiredMaxLevelValueChanged(desiredMaxLevel);
    }
}

void Part::setPartsHaveFromString(const QString ps) {
    if (ps.toInt()) {
        partsHave = ps.toInt();
        calcSafeToScrap();
    }
}

void Part::setupModel() {
    QStringList types;
    types << tr("Common") << tr("Rare") << tr("Epic") << tr("Legend");
    typeModel = new QStringListModel(types, this);

    model = new QStandardItemModel(4, 2, this);
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

int Part::getDesiredMaxLevel() {
    return desiredMaxLevel;
}

int Part::getPartsForLevel(const int level) {
    return partsAtLevel[level];
}

int Part::getTotalPartsNeeded() {
    return totalPartsNeeded;
}

int Part::getSafeToScrap() {
    return safeToScrap;
}

void Part::calcTotalParts() {
    int oldTotalPartsNeeded = totalPartsNeeded;
    totalPartsNeeded = 0;
    int i;
    for (i = currentLevel; i <= desiredMaxLevel; ++i) {
        totalPartsNeeded += partsAtLevel[i];
    }
    if (totalPartsNeeded != oldTotalPartsNeeded) {
        emit totalPartsNeededValueChanged(totalPartsNeeded);
    }
    calcSafeToScrap();
}

void Part::calcSafeToScrap() {
    int oldSafeToScrap = safeToScrap;
    safeToScrap = partsHave - totalPartsNeeded > 0 ? partsHave - totalPartsNeeded : 0;
    if (safeToScrap != oldSafeToScrap) {
        emit safeToScrapValueChanged(safeToScrap);
    }
}
