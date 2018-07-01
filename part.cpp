#include "part.h"

Part::Part(QObject *parent) : QObject(parent) {

}

void Part::setPartType(const PartType partType) {
    this->partType = partType;
}
