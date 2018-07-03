#ifndef PART_H
#define PART_H

#include <QObject>
#include <QStandardItemModel>
#include <QStringListModel>

enum PartType {common, rare, epic, legend};

class Part : public QObject {

    Q_OBJECT

public:
    explicit Part(QObject *parent = nullptr);
    QStandardItemModel *getModel();
    QStringListModel *getTypeModel();

    int getMinLevel();
    int getMaxLevel();
    int getCurrentLevel();
    int getDesiredMaxLevel();
    int getTotalPartsNeeded();
    int getSafeToScrap();

    int getPartsForLevel(const int);

signals:
    void minLevelValueChanged(int newValue);
    void maxLevelValueChanged(int newValue);
    void currentLevelValueChanged(int newValue);
    void desiredMaxLevelValueChanged(int newValue);
    void totalPartsNeededValueChanged(int newValue);
    void safeToScrapValueChanged(int newValue);

public slots:
    void setPartType(const int index);
    void setCurrentLevel(const int level);
    void setDesiredMaxLevel(const int level);
    void setPartsHaveFromString(const QString ps);

private:
    void setupModel();
    void calcTotalParts();
    void calcSafeToScrap();

    PartType partType;
    int minLevel;
    int maxLevel;

    int currentLevel;
    int desiredMaxLevel;
    int totalPartsNeeded;

    int partsHave;
    int safeToScrap;

    QVector<int> partsAtLevel;

    QStandardItemModel *model;
    QStringListModel *typeModel;
};

#endif // PART_H
