#ifndef PART_H
#define PART_H

#include <QObject>
#include <QStandardItemModel>
#include <QStringListModel>
#include <iostream>

enum PartType {common, rare, epic, legend};

class Part : public QObject {

    Q_OBJECT

public:
    explicit Part(QObject *parent = nullptr);
    QStandardItemModel *getModel();
    QStringListModel *getTypeModel();

    int getMinLevel();
    int getMaxLevel();

signals:
    void minLevelValueChanged(int newValue);
    void maxLevelValueChanged(int newValue);

public slots:
    void setPartType(const int index);

private:
    void setupModel();

    PartType partType;
    int minLevel;
    int maxLevel;

    int requiredParts;
    int desiredMaxLevel;

    QStandardItemModel *model;
    QStringListModel *typeModel;
};

#endif // PART_H
