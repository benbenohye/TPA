#ifndef SIGN_UP_H
#define SIGN_UP_H

#include <QWidget>
#include <json.hpp>
using json = nlohmann::json;
extern json j;

namespace Ui {
class sign_up;
}

class sign_up : public QWidget
{
    Q_OBJECT

public:
    explicit sign_up(QWidget *parent = 0);
    ~sign_up();
public:
    void setupCOnnections();

public slots:
    void handelfinishButtonClicked();

private:
    Ui::sign_up *ui;
};

#endif // SIGN_UP_H
