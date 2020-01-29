#ifndef KEYPADWIDGET_H
#define KEYPADWIDGET_H

#include <QWidget>
#include <QLineEdit>

namespace Ui {
class KeypadWidget;
}
class QPushButton;

class KeypadWidget : public QWidget
{
    Q_OBJECT

public:
    enum UiMode {Desktop, Touch};
    explicit KeypadWidget(QWidget *parent = nullptr);
    ~KeypadWidget();
    void setEchoMode(QLineEdit::EchoMode mode);
    void setMode(UiMode mode);
protected:
    bool eventFilter(QObject *obj, QEvent *event) override;
public slots:
    void clear();
    void setInputFocus();
signals:
    void enterPressed(QString);
private:
    Ui::KeypadWidget *ui;

};

#endif // KEYPADWIDGET_H
