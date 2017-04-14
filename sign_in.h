#ifndef SIGN_IN_H
#define SIGN_IN_H

#include <QMainWindow>
#include <managepsw.h>
#include <md5.h>
#include "stdafx.h"
#include <aes.h>
#include <cstring>
#include <json.hpp>
#include <home_screen.h>
using json = nlohmann::json;
extern json j;

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
    void handleexitButtonClicked();

private:
    Ui::sign_in *ui;
    home_screen h1;
};

#endif // SIGN_IN_H
