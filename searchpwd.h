#ifndef SEARCHPWD_H
#define SEARCHPWD_H

#include <QMainWindow>
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
    void handlesearchButtonClicked();
    void handleprevButtonClicked();
    void handlenextButtonClicked();


private:
    Ui::searchpwd *ui;
};

#endif // SEARCHPWD_H
