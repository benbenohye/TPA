#ifndef MANAGEPSW_H
#define MANAGEPSW_H

#include <QMainWindow>
#include <QLayout>
#include <json.hpp>
#include <vector>
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

public slots:
    void showPw(int i);

    void handlenewButtonClicked();
    void handlemodifyButtonClicked();
    void handledeleteButtonClicked();

    void handlefinishButtonClicked();

    void handleprevButtonClicked();
    void handlenextButtonClicked();

private:
    int page;
    int total;

    vector<json> data;

    Ui::managepsw *ui;
};



#endif // MANAGEPSW_H
