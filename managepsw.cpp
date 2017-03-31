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
    dataShow();
}

managepsw::~managepsw()
{
    delete ui;
}

void managepsw::showPw(int i)
{

    QMessageBox::information(this,"password",data[i]["pwd"].get<std::string>().c_str());
}

void managepsw::dataShow()
{

   if(j["list"].size()){
       if(page==0){
           page=1;
       }

       total=(j["list"].size()+4)/5;
       if(page>total){
           page=total;
       }
       data.clear();
       for(int i=0;i<5;i++){
           data.push_back(j["list"][(page-1)*5+i]);
       }
       if(data[0] .size())
       ui->oneButton->setText((data[0]["usrname"].get<std::string>()+"("+data[0]["detail"].get<std::string>()+")").c_str());
       else
           ui->oneButton->hide();

       if(data[1] .size())
       ui->twoButton->setText((data[1]["usrname"].get<std::string>()+"("+data[1]["detail"].get<std::string>()+")").c_str());
       else
           ui->twoButton->hide();

       if(data[2] .size())
       ui->threeButton->setText((data[2]["usrname"].get<std::string>()+"("+data[2]["detail"].get<std::string>()+")").c_str());
       else
           ui->threeButton->hide();

       if(data[3] .size())
       ui->fourButton->setText((data[3]["usrname"].get<std::string>()+"("+data[3]["detail"].get<std::string>()+")").c_str());
       else
           ui->fourButton->hide();

       if(data[4] .size())
       ui->fiveButton->setText((data[4]["usrname"].get<std::string>()+"("+data[4]["detail"].get<std::string>()+")").c_str());
       else
           ui->fiveButton->hide();


   }
   else{
       page=0;
       total=0;
   }
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
