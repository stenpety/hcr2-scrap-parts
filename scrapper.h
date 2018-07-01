#ifndef SCRAPPER_H
#define SCRAPPER_H

#include <QWidget>

#include "part.h"

class Scrapper : public QWidget {
    Q_OBJECT

public:
    explicit Scrapper(QWidget *parent = nullptr);

signals:

public slots:

private:
    Part *part;
};

#endif // SCRAPPER_H
