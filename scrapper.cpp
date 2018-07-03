#include "scrapper.h"

Scrapper::Scrapper(QWidget *parent) : QWidget(parent) {

    part = new Part;

    // Required
    QLabel *requiredLabel = new QLabel(tr("Parts required for NEXT upgrade:"));

    requiredSlider = new QSlider(Qt::Horizontal);
    requiredSlider->setFocusPolicy(Qt::StrongFocus);
    requiredSlider->setTickPosition(QSlider::TicksBothSides);
    requiredSlider->setMinimum(part->getMinLevel());
    requiredSlider->setMaximum(part->getMaxLevel());
    requiredSlider->setValue(part->getCurrentLevel());
    requiredSlider->setTickInterval(1);
    requiredSlider->setSingleStep(1);
    connect(part, &Part::minLevelValueChanged, requiredSlider, &QSlider::setMinimum);
    connect(part, &Part::maxLevelValueChanged, requiredSlider, &QSlider::setMaximum);
    connect(part, &Part::currentLevelValueChanged, requiredSlider, &QSlider::setValue);
    connect(requiredSlider, &QSlider::valueChanged, part, &Part::setCurrentLevel);

    requiredNumberLabel = new QLabel(QString::number(part->getPartsForLevel(part->getCurrentLevel())));
    connect(part, &Part::currentLevelValueChanged,
            [=](){ requiredNumberLabel->setText(QString::number(part->getPartsForLevel(part->getCurrentLevel()))); });

    auto *requiredBox = new QHBoxLayout;
    requiredBox->addWidget(requiredSlider);
    requiredBox->addWidget(requiredNumberLabel);

    // Desired max
    QLabel *desiredLabel = new QLabel(tr("Desired max upgrade level:"));

    desiredMaxSlider = new QSlider(Qt::Horizontal);
    desiredMaxSlider->setFocusPolicy(Qt::StrongFocus);
    desiredMaxSlider->setTickPosition(QSlider::TicksBothSides);
    desiredMaxSlider->setMinimum(part->getMinLevel());
    desiredMaxSlider->setMaximum(part->getMaxLevel());
    desiredMaxSlider->setValue(part->getDesiredMaxLevel());
    desiredMaxSlider->setTickInterval(1);
    desiredMaxSlider->setSingleStep(1);
    connect(part, &Part::minLevelValueChanged, desiredMaxSlider, &QSlider::setMinimum);
    connect(part, &Part::maxLevelValueChanged, desiredMaxSlider, &QSlider::setMaximum);
    connect(part, &Part::desiredMaxLevelValueChanged, desiredMaxSlider, &QSlider::setValue);
    connect(desiredMaxSlider, &QSlider::valueChanged, part, &Part::setDesiredMaxLevel);

    desiredMaxNumberLabel = new QLabel(QString::number(part->getDesiredMaxLevel()+2));
    connect(part, &Part::desiredMaxLevelValueChanged,
            [=](){ desiredMaxNumberLabel->setText(QString::number(part->getDesiredMaxLevel()+2)); } );

    auto desiredMaxBox = new QHBoxLayout;
    desiredMaxBox->addWidget(desiredMaxSlider);
    desiredMaxBox->addWidget(desiredMaxNumberLabel);

    // Needed parts - total
    QLabel *scrapLabel = new QLabel(tr("Total parts needed:"));
    numOfParts = new QLabel(QString::number(part->getTotalPartsNeeded()));
    connect(part, &Part::totalPartsNeededValueChanged,
            [=](){ numOfParts->setText(QString::number(part->getTotalPartsNeeded())); } );

    // Has parts
    QLabel *partsHaveLabel = new QLabel(tr("Parts have: "));
    partsHave = new QLineEdit;
    partsHave->setAlignment(Qt::AlignHCenter);
    connect(partsHave, &QLineEdit::textChanged, part, &Part::setPartsHaveFromString);
    auto *haveBox = new QHBoxLayout;
    haveBox->addWidget(partsHaveLabel);
    haveBox->addWidget(partsHave);

    // Safe to scrap
    QLabel *safeToScrapLabel = new QLabel(tr("Safe to scrap: "));
    safeToScrap = new QLabel("");
    connect(part, &Part::safeToScrapValueChanged,
            [=](){ safeToScrap->setText(QString::number(part->getSafeToScrap())); } );
    auto *scrapBox = new QHBoxLayout;
    scrapBox->addWidget(safeToScrapLabel);
    scrapBox->addWidget(safeToScrap);

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
    mainLayout->addLayout(requiredBox, 1, 0, Qt::AlignCenter);
    mainLayout->addWidget(desiredLabel, 2, 0, Qt::AlignCenter);
    mainLayout->addLayout(desiredMaxBox, 3, 0, Qt::AlignCenter);
    mainLayout->addLayout(lblsBox, 4, 0, Qt::AlignCenter);
    mainLayout->addWidget(typeComboBox, 1, 1, Qt::AlignCenter);
    mainLayout->addLayout(haveBox, 5, 0, Qt::AlignCenter);
    mainLayout->addLayout(scrapBox, 6, 0, Qt::AlignHCenter);

    setLayout(mainLayout);
}
