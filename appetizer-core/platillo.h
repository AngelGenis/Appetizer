#ifndef PLATILLO_H
#define PLATILLO_H

#include <QWidget>

namespace Ui {
class Platillo;
}

class Platillo : public QWidget
{
    Q_OBJECT

public:
    explicit Platillo(QWidget *parent = nullptr);
    ~Platillo();

private:
    Ui::Platillo *ui;
};

#endif // PLATILLO_H
