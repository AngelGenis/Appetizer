#ifndef REALIZAR_COBRO2_H
#define REALIZAR_COBRO2_H

#include <QWidget>

namespace Ui {
class realizar_cobro2;
}

class realizar_cobro2 : public QWidget
{
    Q_OBJECT

public:
    explicit realizar_cobro2(QWidget *parent = nullptr);
    ~realizar_cobro2();

private:
    Ui::realizar_cobro2 *ui;
};

#endif // REALIZAR_COBRO2_H
