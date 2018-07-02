#include "scrapper.h"

Scrapper::Scrapper(QWidget *parent) : QWidget(parent) {

    part = new Part;

    QLabel *nextUpLabel = new QLabel(tr("Parts required for NEXT upgrade:"));
    requiredSlider = new QSlider(Qt::Horizontal);
    requiredSlider->setFocusPolicy(Qt::StrongFocus);
    requiredSlider->setTickPosition(QSlider::TicksBothSides);
    requiredSlider->setTickInterval(10);
    requiredSlider->setSingleStep(1);

    QLabel *desiredLabel = new QLabel(tr("Desired max upgrade level:"));
    desiredMaxSlider = new QSlider(Qt::Horizontal);
    desiredMaxSlider->setFocusPolicy(Qt::StrongFocus);
    desiredMaxSlider->setTickPosition(QSlider::TicksBothSides);
    desiredMaxSlider->setTickInterval(5);
    desiredMaxSlider->setSingleStep(1);

    QLabel *scrapLabel = new QLabel(tr("Parts to scrap:"));
    QLabel *numOfParts = new QLabel("0");

    auto *lblsBox = new QHBoxLayout;
    lblsBox->addWidget(scrapLabel);
    lblsBox->addWidget(numOfParts);

    typeComboBox = new QComboBox();
    typeComboBox->setModel(part->getTypeModel());
    connect(typeComboBox, QOverload<int>::of(&QComboBox::currentIndexChanged), part, &Part::setPartType);

    mapper = new QDataWidgetMapper(this);
    mapper->setModel(part->getModel());


    auto *mainLayout = new QGridLayout;
    mainLayout->addWidget(nextUpLabel, 0, 0, Qt::AlignCenter);
    mainLayout->addWidget(requiredSlider, 1, 0, Qt::AlignCenter);
    mainLayout->addWidget(desiredLabel, 2, 0, Qt::AlignCenter);
    mainLayout->addWidget(desiredMaxSlider, 3, 0, Qt::AlignCenter);
    mainLayout->addLayout(lblsBox, 4, 0, Qt::AlignCenter);
    mainLayout->addWidget(typeComboBox, 1, 1, Qt::AlignCenter);

    setLayout(mainLayout);
}
