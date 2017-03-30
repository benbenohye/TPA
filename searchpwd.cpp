#include "searchpwd.h"
#include "ui_searchpwd.h"
#include <QDebug>

searchpwd::searchpwd(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::searchpwd)
{
    ui->setupUi(this);
    this->setupconnections();
}

searchpwd::~searchpwd()
{
    delete ui;
}

void searchpwd::setupconnections()
{
    connect(this->ui->searchButton,SIGNAL(clicked(bool)),this,SLOT(handlesearchButtonClicked()));
    connect(this->ui->prevButton,SIGNAL(clicked(bool)),this,SLOT(handleprevButtonClicked()));
    connect(this->ui->nextButton,SIGNAL(clicked(bool)),this,SLOT(handlenextButtonClicked()));
}

void searchpwd::handlesearchButtonClicked()
{
    qDebug()<<"to search this one";
}

void searchpwd::handleprevButtonClicked()
{
    qDebug()<<"to the prev page";
}

void searchpwd::handlenextButtonClicked()
{
    qDebug()<<"to the next page";
}

