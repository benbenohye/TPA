#ifndef SEARCHPWD_H
#define SEARCHPWD_H


#include <QMainWindow>
#include <md5.h>
#include "stdafx.h"
#include <aes.h>
#include <cstring>
#include <json.hpp>
using json = nlohmann::json;
extern json j;

namespace Ui {
class searchpwd;
}

class searchpwd : public QMainWindow
{
    Q_OBJECT

public:
    explicit searchpwd(QWidget *parent = 0);
    ~searchpwd();

public:
    void setupconnections();

public slots:
    void handlesaveButtonClicked();


private:
    Ui::searchpwd *ui;
};

#endif // SEARCHPWD_H
