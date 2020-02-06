#ifndef NAVEGADOR_H
#define NAVEGADOR_H

#include <QWidget>

namespace Ui {
class Navegador;
}

class Navegador : public QWidget
{
    Q_OBJECT

public:
    explicit Navegador(QWidget *parent = nullptr);
    ~Navegador();

private:
    Ui::Navegador *ui;
};

#endif // NAVEGADOR_H
