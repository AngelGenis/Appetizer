#ifndef HEADER_H
#define HEADER_H

#include <QWidget>

namespace Ui {
class Header;
}

class Header : public QWidget
{
    Q_OBJECT

public:
    explicit Header(QWidget *parent = nullptr);
    ~Header();

private:
    Ui::Header *ui;
};

#endif // HEADER_H
