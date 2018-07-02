#include "scrapper.h"

Scrapper::Scrapper(QWidget *parent) : QWidget(parent) {

    part = new Part;

    QLabel *requiredLabel = new QLabel(tr("Parts required for NEXT upgrade:"));
    requiredSlider = new QSlider(Qt::Horizontal);
    requiredSlider->setFocusPolicy(Qt::StrongFocus);
    requiredSlider->setTickPosition(QSlider::TicksBothSides);
    requiredSlider->setMinimum(part->getMinLevel());
    requiredSlider->setMaximum(part->getMaxLevel());
    requiredSlider->setTickInterval(1);
    requiredSlider->setSingleStep(1);
    connect(part, &Part::minLevelValueChanged, requiredSlider, &QSlider::setMinimum);
    connect(part, &Part::maxLevelValueChanged, requiredSlider, &QSlider::setMaximum);

    QLabel *desiredLabel = new QLabel(tr("Desired max upgrade level:"));
    desiredMaxSlider = new QSlider(Qt::Horizontal);
    desiredMaxSlider->setFocusPolicy(Qt::StrongFocus);
    desiredMaxSlider->setTickPosition(QSlider::TicksBothSides);
    desiredMaxSlider->setMinimum(part->getMinLevel());
    desiredMaxSlider->setMaximum(part->getMaxLevel());
    desiredMaxSlider->setTickInterval(1);
    desiredMaxSlider->setSingleStep(1);
    connect(part, &Part::minLevelValueChanged, desiredMaxSlider, &QSlider::setMinimum);
    connect(part, &Part::maxLevelValueChanged, desiredMaxSlider, &QSlider::setMaximum);

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
    mainLayout->addWidget(requiredLabel, 0, 0, Qt::AlignCenter);
    mainLayout->addWidget(requiredSlider, 1, 0, Qt::AlignCenter);
    mainLayout->addWidget(desiredLabel, 2, 0, Qt::AlignCenter);
    mainLayout->addWidget(desiredMaxSlider, 3, 0, Qt::AlignCenter);
    mainLayout->addLayout(lblsBox, 4, 0, Qt::AlignCenter);
    mainLayout->addWidget(typeComboBox, 1, 1, Qt::AlignCenter);

    setLayout(mainLayout);
}
