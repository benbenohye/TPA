#include "managepsw.h"
#include "ui_managepsw.h"
#include <QDebug>
#include <QStringListModel>
#include <QMessageBox>
#include <string>
#include <json.hpp>
using json = nlohmann::json;
extern json j;
managepsw::managepsw(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::managepsw)
{
    ui->setupUi(this);
    this->setupconnections();
    page=1;
}

managepsw::~managepsw()
{
    delete ui;
}

void managepsw::showPw(int i)
{

    QMessageBox::information(this,"password","test");
}

void managepsw::dataShow()
{

//   if(j["list"]){
//       if(page=0){
//           page=1;
//       }
//       int k
//   }
//   else{
//       page=0;
//       total=0;
//   }
}
void managepsw::setupconnections()
{


    connect(this->ui->finishButton,SIGNAL(clicked(bool)),this,SLOT(handlefinishButtonClicked()));

    connect(ui->oneButton,  &QPushButton::clicked, this, [this]{ showPw(0); });
    connect(ui->twoButton,  &QPushButton::clicked, this, [this]{ showPw(1); });

    connect(ui->threeButton,  &QPushButton::clicked, this, [this]{ showPw(2); });

    connect(ui->fourButton,  &QPushButton::clicked, this, [this]{ showPw(3); });
    connect(ui->fiveButton,  &QPushButton::clicked, this, [this]{ showPw(4); });


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
    ui->listWidget->setVisible(true);
    //ui->modifyWidget->setVisible(true);
   /*
    QStringList num;
    num<<QString("1")<<QString("2")<<QString("3");
    QStringListModel*model = new QStringListModel(num);
    ui->pwdlistView->setModel(model);
   */
    /*
    QStringList detail;
    for(auto&x:j["list"])
    {
    std::string s = x["detail"];
    detail += QString(s.c_str());
    }
    QStringListModel*model = new QStringListModel(detail);
    ui->pwdlistView->setModel(model);
    model->setStringList(detail);
    */
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
