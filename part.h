#ifndef PART_H
#define PART_H

#include <QObject>

enum PartType {normal, rare, epic, legend};

class Part : public QObject {

    Q_OBJECT

public:
    explicit Part(QObject *parent = nullptr);

public slots:
    void setPartType(PartType const partType);

private:
    PartType partType;

};

#endif // PART_H
