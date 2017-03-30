#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <sign_in.h>
#include <sign_up.h>
#include <json.hpp>
using json = nlohmann::json;
extern json j;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
public:
    void setupConnections();
public slots:
    void handlesign_InButtonClicked();
    void handlesign_UpButtonClicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
