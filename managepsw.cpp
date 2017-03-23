#include "managepsw.h"
#include "ui_managepsw.h"
#include <QDebug>

managepsw::managepsw(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::managepsw)
{
    ui->setupUi(this);
    this->setupconnections();
}

managepsw::~managepsw()
{
    delete ui;
}

void managepsw::setupconnections()
{
    connect(this->ui->newButton,SIGNAL(clicked(bool)),this,SLOT(handlenewButtonClicked()));
    connect(this->ui->modifyButton,SIGNAL(clicked(bool)),this,SLOT(handlemodifyButtonClicked()));
    connect(this->ui->deleteButton,SIGNAL(clicked(bool)),this,SLOT(handledeleteButtonClicked()));

    connect(this->ui->finishButton,SIGNAL(clicked(bool)),this,SLOT(handlefinishButtonClicked()));
}

void managepsw::handlenewButtonClicked()
{
    qDebug()<<"yao xinjian le wo";
}

void managepsw::handlemodifyButtonClicked()
{
    qDebug()<<"yao xiugai le wo";
}

void managepsw::handledeleteButtonClicked()
{
    qDebug()<<"yao shanchu le wo";
}

void managepsw::handlefinishButtonClicked()
{
    qDebug()<<"xinjian haole wo";
}
