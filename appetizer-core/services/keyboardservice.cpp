#include "keyboardservice.h"
#include <QDebug>

QLabel *KeyboardService::teclado = 0;

KeyboardService::KeyboardService(QWidget *parent) : QMainWindow(parent)
{}

void KeyboardService::setTeclado(QLabel *teclado){
    this->teclado = teclado;
}

void KeyboardService::hideTeclado(){
    teclado->hide();
}

void KeyboardService::showTeclado(QWidget * old, QWidget * now){
    Q_UNUSED(old);
    if(now != nullptr && QString::compare(now->metaObject()->className(), "QLineEdit")){
        teclado->hide();
    } else{
        teclado->show();
    }
}

void KeyboardService::showTecladoEdit(){
    teclado->show();
}


