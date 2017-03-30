#ifndef HOME_SCREEN_H
#define HOME_SCREEN_H

#include <QMainWindow>
#include <managepsw.h>
#include <searchpwd.h>
#include <json.hpp>
using json = nlohmann::json;
extern json j;

namespace Ui {
class home_screen;
}

class home_screen : public QMainWindow
{
    Q_OBJECT

public:
    explicit home_screen(QWidget *parent = 0);
    ~home_screen();

public:
    void setupconnections();

public slots:
    void handlemanageButtonClicked();
    void handlesearchButtonClicked();

private:
    Ui::home_screen *ui;
};

#endif // HOME_SCREEN_H
