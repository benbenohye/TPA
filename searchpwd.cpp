#include "searchpwd.h"
#include "ui_searchpwd.h"

searchpwd::searchpwd(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::searchpwd)
{
    ui->setupUi(this);
}

searchpwd::~searchpwd()
{
    delete ui;
}
