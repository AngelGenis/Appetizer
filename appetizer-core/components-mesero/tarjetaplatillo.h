#ifndef TARJETAPLATILLO_H
#define TARJETAPLATILLO_H

#include <QWidget>

namespace Ui {
class TarjetaPlatillo;
}

class TarjetaPlatillo : public QWidget
{
    Q_OBJECT

public:
    explicit TarjetaPlatillo(QWidget *parent = nullptr);
    ~TarjetaPlatillo();

private:
    Ui::TarjetaPlatillo *ui;
};

#endif // TARJETAPLATILLO_H
