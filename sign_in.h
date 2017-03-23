#ifndef SIGN_IN_H
#define SIGN_IN_H

#include <QMainWindow>

namespace Ui {
class sign_in;
}

class sign_in : public QMainWindow
{
    Q_OBJECT

public:
    explicit sign_in(QWidget *parent = 0);
    ~sign_in();
public:
    void setupCOnnections();

public slots:
    void handleloginButtonClicked();

private:
    Ui::sign_in *ui;
};

#endif // SIGN_IN_H
