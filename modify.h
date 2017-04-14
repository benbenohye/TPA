#ifndef MODIFY_H
#define MODIFY_H

#include <QMainWindow>
#include <md5.h>
#include "stdafx.h"
#include <aes.h>
#include <cstring>
#include <json.hpp>
using json = nlohmann::json;
extern json j;

namespace Ui {
class modify;
}

class modify : public QMainWindow
{
    Q_OBJECT

public:
    explicit modify(QWidget *parent = 0);
    ~modify();
public:
    void setupconnections();

public slots:
    void handlesaveButtonClicked();


private:
    Ui::modify *ui;
};

#endif // MODIFY_H
