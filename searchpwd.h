#ifndef SEARCHPWD_H
#define SEARCHPWD_H

#include <QMainWindow>

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


private:
    Ui::searchpwd *ui;
};

#endif // SEARCHPWD_H
