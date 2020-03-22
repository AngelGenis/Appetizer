#ifndef REALIZAR_COBRO_H
#define REALIZAR_COBRO_H

#include <QWidget>

namespace Ui {
class realizar_cobro;
}

class realizar_cobro : public QWidget
{
    Q_OBJECT

public:
    explicit realizar_cobro(QWidget *parent = nullptr);
    ~realizar_cobro();

private:
    Ui::realizar_cobro *ui;
};

#endif // REALIZAR_COBRO_H
