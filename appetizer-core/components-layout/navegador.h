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
    void setDatosUsuario(QString nombre, QString cargo, QString foto);
    void setEditorMode(bool s);

private slots:
    void on_profileBtn_clicked();
    void on_hamBtn_clicked();

    void on_notifBtn_clicked();

    void on_btn_goMesas_clicked();

signals:
    void profileBtnClicked();
    void hamBtnClicked();
    void notificationBtnClicked();
    void btnAtrasMesasClicked();

private:
    Ui::Navegador *ui;
};

#endif // NAVEGADOR_H
