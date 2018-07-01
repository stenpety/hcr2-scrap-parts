#ifndef SCRAPPER_H
#define SCRAPPER_H

#include <QWidget>
#include <QtWidgets>
#include <QDataWidgetMapper>

#include "part.h"

class Scrapper : public QWidget {
    Q_OBJECT

public:
    explicit Scrapper(QWidget *parent = nullptr);

signals:

public slots:

private:
    Part *part;

    QComboBox *typeComboBox;
    QDataWidgetMapper *mapper;
};

#endif // SCRAPPER_H
