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

    int getPartsForLevel(const int);

signals:
    void minLevelValueChanged(int newValue);
    void maxLevelValueChanged(int newValue);
    void currentLevelValueChanged(int newValue);

public slots:
    void setPartType(const int index);

private:
    void setupModel();

    PartType partType;
    int minLevel;
    int maxLevel;
    int currentLevel;

    int requiredParts;
    int desiredMaxLevel;

    QVector<int> partsAtLevel;

    QStandardItemModel *model;
    QStringListModel *typeModel;
};

#endif // PART_H
