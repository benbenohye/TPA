#include "managepsw.h"
#include "ui_managepsw.h"
#include <QDebug>
#include <QStringListModel>
#include <string>

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
    //qDebug()<<"yao xinjian le wo";
    ui->newWidget->setVisible(true);
    ui->modifyWidget->setVisible(false);
}

void managepsw::handlemodifyButtonClicked()
{
    //qDebug()<<"yao xiugai le wo";
    ui->newWidget->setVisible(false);
    ui->modifyWidget->setVisible(true);
   /*
    QStringList num;
    num<<QString("1")<<QString("2")<<QString("3");
    QStringListModel*model = new QStringListModel(num);
    ui->pwdlistView->setModel(model);
   */

    QStringList detail;
    for(auto&x:j["list"])
    {
    std::string s = x["detail"];
    detail += QString(s.c_str());
    }
    QStringListModel*model = new QStringListModel(detail);
    ui->pwdlistView->setModel(model);
    model->setStringList(detail);

    /*
    for(auto&x:j["list"])
    {
        Button *x->setToolButtonStyle(QT::ToolButtonTextUnderIcon);
    }*/

}

void managepsw::handledeleteButtonClicked()
{
    qDebug()<<"yao shanchu le wo";
}

void managepsw::handlefinishButtonClicked()
{
    qDebug()<<"xinjian haole wo";
}

void managepsw::handleprevButtonClicked()
{

}

void managepsw::handlenextButtonClicked()
{

}
