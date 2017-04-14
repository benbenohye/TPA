#ifndef MANAGEPSW_H
#define MANAGEPSW_H

#include <QMainWindow>
#include <QLayout>
#include <json.hpp>
#include <vector>
#include <deque>
#include <fstream>
#include <md5.h>
#include "stdafx.h"
#include <aes.h>
#include <cstring>
using namespace std;
using json = nlohmann::json;
extern json j;

namespace Ui {
class managepsw;
}

class managepsw : public QMainWindow
{
    Q_OBJECT

public:
    explicit managepsw(QWidget *parent = 0);
    ~managepsw();
public:
    void setupconnections();
    void dataShow();
    void removePw(int i);
    void editPw(int i);

public slots:
    void showPw(int i);

    void handlenewBClicked();
    void handlemodifyButtonClicked();
    void handledeleteButtonClicked();

    void handlefinishButtonClicked();

    void handleprevButtonClicked();
    void handlenextButtonClicked();
    void handlenexitButtonClicked();

private:
    int page;
    int total;

    vector<json> data;

    Ui::managepsw *ui;
};



#endif // MANAGEPSW_H
