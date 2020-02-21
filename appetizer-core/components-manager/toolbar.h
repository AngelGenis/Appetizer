#ifndef TOOLBAR_H
#define TOOLBAR_H

#include <QWidget>

namespace Ui {
    class toolbar;
}

class toolbar : public QWidget
{
    Q_OBJECT

public:
    explicit toolbar(QWidget *parent = nullptr);
    ~toolbar();

private slots:
    void on_btn_editarFondo_clicked();

    void on_btn_agregarMesa_clicked();

    void on_btn_editarAsientos_clicked();

    void on_btn_eliminarMesa_clicked();

signals:
    void clickedEditarFondo();

    void clickedAgregarMesa();

    void clickedEditarAsiento();

    void clickedEliminarMesa();

private:
    Ui::toolbar *ui;
};

#endif // TOOLBAR_H
