#include "keypadwidget.h"
#include "ui_keypadwidget.h"
#include <QKeyEvent>
#include <QPropertyAnimation>

KeypadWidget::KeypadWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::KeypadWidget)
{
    ui->setupUi(this);
    qApp->installEventFilter(this);
    setMode(Touch);
    connect(ui->line_numeros_ingresados,
            &QLineEdit::returnPressed,
            [=](){ emit enterPressed(ui->line_numeros_ingresados->text()); });
}

KeypadWidget::~KeypadWidget()
{
    qApp->removeEventFilter(this);
    delete ui;
}

bool KeypadWidget::eventFilter(QObject *obj, QEvent *event)
{
    QString text = ui->line_numeros_ingresados->text();

    if(obj == ui->btn_1 && event->type() == QEvent::MouseButtonPress)
    {
        ui->line_numeros_ingresados->setText(text + "1");
        return true;
    }
    if(obj == ui->btn_2 && event->type() == QEvent::MouseButtonPress)
    {
        ui->line_numeros_ingresados->setText(text + "2");    
        return true;
    }
    if(obj == ui->btn_3 && event->type() == QEvent::MouseButtonPress)
    {
        ui->line_numeros_ingresados->setText(text.append("3"));
        return true;
    }
    if(obj == ui->btn_4 && event->type() == QEvent::MouseButtonPress)
    {
        ui->line_numeros_ingresados->setText(text.append("4"));
        return true;
    }
    if(obj == ui->btn_5 && event->type() == QEvent::MouseButtonPress)
    {
        ui->line_numeros_ingresados->setText(text.append("5"));
        return true;
    }
    if(obj == ui->btn_6 && event->type() == QEvent::MouseButtonPress)
    {
        ui->line_numeros_ingresados->setText(text.append("6"));
        return true;
    }
    if(obj == ui->btn_7 && event->type() == QEvent::MouseButtonPress)
    {
        ui->line_numeros_ingresados->setText(text.append("7"));
        return true;
    }
    if(obj == ui->btn_8 && event->type() == QEvent::MouseButtonPress)
    {
        ui->line_numeros_ingresados->setText(text.append("8"));
        return true;
    }
    if(obj == ui->btn_9 && event->type() == QEvent::MouseButtonPress)
    {
        ui->line_numeros_ingresados->setText(text.append("9"));
        return true;
    }
    if(obj == ui->btn_0 && event->type() == QEvent::MouseButtonPress)
    {
        ui->line_numeros_ingresados->setText(text.append("0"));
        return true;
    }
    if(obj == ui->btn_entrar && event->type() == QEvent::MouseButtonPress)
    {
        emit enterPressed(text);
        return true;
    }
    return QWidget::eventFilter(obj, event);
    
}

void KeypadWidget::setMode(UiMode mode)
{
    if (mode == Desktop)
    {
        ui->numpad->hide();
    }
    if(mode == Touch)
    {
        ui->numpad->show();
    }
}
void KeypadWidget::setEchoMode(QLineEdit::EchoMode mode)
{
    ui->line_numeros_ingresados->setEchoMode(mode);
}

void KeypadWidget::clear()
{
    ui->line_numeros_ingresados->clear();
}

void KeypadWidget::setInputFocus()
{
    ui->line_numeros_ingresados->setFocus();
}
