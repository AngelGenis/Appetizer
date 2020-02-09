#ifndef KEYBOARDSERVICE_H
#define KEYBOARDSERVICE_H

#include <QLabel>
#include <QMainWindow>

class KeyboardService : public QMainWindow
{
    Q_OBJECT
private:

public:
    static QLabel *teclado;
    explicit KeyboardService(QWidget *parent = nullptr);
    void setTeclado(QLabel *t);

signals:

public slots:
    void hideTeclado();
    void showTeclado(QWidget * old, QWidget * now);
    void showTecladoEdit();
};

#endif // KEYBOARDSERVICE_H
