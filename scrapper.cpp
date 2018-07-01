#include <QtWidgets>

#include "scrapper.h"

Scrapper::Scrapper(QWidget *parent) : QWidget(parent) {
    QLabel *nextUpLabel = new QLabel(tr("Parts required for NEXT upgrade:"));


    QLabel *desiredLabel = new QLabel(tr("Desired max upgrade level:"));

    QLabel *scrapLabel = new QLabel(tr("Parts to scrap:"));
    QLabel *numOfParts = new QLabel("0");

    auto *lblsBox = new QHBoxLayout;
    lblsBox->addWidget(scrapLabel);
    lblsBox->addWidget(numOfParts);

    auto *typeComboBox = new QComboBox;
    typeComboBox->addItem(tr("Normal"));
    typeComboBox->addItem(tr("Rare"));
    typeComboBox->addItem(tr("Epic"));
    typeComboBox->addItem(tr("Legend"));

    auto *mainLayout = new QGridLayout;
    mainLayout->addWidget(nextUpLabel, 0, 0, Qt::AlignCenter);
    mainLayout->addWidget(desiredLabel, 2, 0, Qt::AlignCenter);
    mainLayout->addLayout(lblsBox, 4, 0, Qt::AlignCenter);
    mainLayout->addWidget(typeComboBox, 1, 1, Qt::AlignCenter);

    setLayout(mainLayout);

    part = new Part;
}
