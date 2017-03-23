#include "home_screen.h"
#include "ui_home_screen.h"
#include <QDebug>

home_screen::home_screen(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::home_screen)
{
    ui->setupUi(this);
    this->setupconnections();
}

home_screen::~home_screen()
{
    delete ui;
}

void home_screen::setupconnections()
{
    connect(this->ui->manageButton,SIGNAL(clicked(bool)),this,SLOT(handlemanageButtonClicked()));
    connect(this->ui->searchButton,SIGNAL(clicked(bool)),this,SLOT(handlesearchButtonClicked()));
}

void home_screen::handlemanageButtonClicked()
{
    qDebug()<<"zhuandao manage_psw";
}

void home_screen::handlesearchButtonClicked()
{
    qDebug()<<"zhuandao search_psw";
}
