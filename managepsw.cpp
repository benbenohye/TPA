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
    page=1;//the first page is 1
    //dataShow();//show the list
    ui->editW->setVisible(false);
}

managepsw::~managepsw()
{
    delete ui;
}

void managepsw::showPw(int i)//the show of password
{

    QMessageBox::information(this,"password",data[i]["pwd"].get<std::string>().c_str());
}

void managepsw::dataShow()
{
    ui->oneButton->show();
    ui->e1->show();
    ui->r1->show();
    ui->twoButton->show();
    ui->e2->show();
    ui->r2->show();
    ui->threeButton->show();
    ui->e3->show();
    ui->r3->show();
    ui->fourButton->show();
    ui->e4->show();
    ui->r4->show();
    ui->fiveButton->show();
    ui->e5->show();
    ui->r5->show();

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
       {
           ui->oneButton->hide();
           ui->e1->hide();
           ui->r1->hide();
       }

       if(data[1] .size())
       ui->twoButton->setText((data[1]["usrname"].get<std::string>()+"("+data[1]["detail"].get<std::string>()+")").c_str());
       else
       {
           ui->twoButton->hide();
           ui->e2->hide();
           ui->r2->hide();
       }

       if(data[2] .size())
       ui->threeButton->setText((data[2]["usrname"].get<std::string>()+"("+data[2]["detail"].get<std::string>()+")").c_str());
       else
       {
           ui->threeButton->hide();
           ui->e3->hide();
           ui->r3->hide();
       }

       if(data[3] .size())
       ui->fourButton->setText((data[3]["usrname"].get<std::string>()+"("+data[3]["detail"].get<std::string>()+")").c_str());
       else
       {
           ui->fourButton->hide();
           ui->e4->hide();
           ui->r4->hide();
       }

       if(data[4] .size())
       ui->fiveButton->setText((data[4]["usrname"].get<std::string>()+"("+data[4]["detail"].get<std::string>()+")").c_str());
       else
       {
           ui->fiveButton->hide();
           ui->e5->hide();
           ui->r5->hide();
       }


   }
   else
   {
       page=0;
       total=0;
   }
   ui->pageText->setText((to_string( page)+"/"+to_string(total)).c_str());
}
void managepsw::setupconnections()
{


    connect(this->ui->finishButton,SIGNAL(clicked(bool)),this,SLOT(handlefinishButtonClicked()));
    connect(this->ui->newB,SIGNAL(clicked(bool)),this,SLOT(handlenewBClicked()));


    connect(ui->oneButton,  &QPushButton::clicked, this, [this]{ showPw(0); });
    connect(ui->twoButton,  &QPushButton::clicked, this, [this]{ showPw(1); });

    connect(ui->threeButton,  &QPushButton::clicked, this, [this]{ showPw(2); });

    connect(ui->fourButton,  &QPushButton::clicked, this, [this]{ showPw(3); });
    connect(ui->fiveButton,  &QPushButton::clicked, this, [this]{ showPw(4); });

    connect(ui->firstB,  &QPushButton::clicked, this, [this]{ page=1;dataShow() ;});
    connect(ui->lastB,  &QPushButton::clicked, this, [this]{ page=total;dataShow(); });

    connect(ui->prevB,  &QPushButton::clicked, this, [this]{ if(page==1)return;page--;dataShow() ;});
    connect(ui->nextB,  &QPushButton::clicked, this, [this]{ if(page==total)return;page++;dataShow(); });

    connect(ui->newB,  &QPushButton::clicked, this, [this]{  auto& t=j["list"];
        json newJ=R"(
                  {
                    "usrname": "daye",
                    "pwd": "3.14",
                    "detail":"qq"
                  }
                )"_json;

                t.insert(t.begin(),newJ);

                page=1;dataShow();
                {
                std::ofstream o("/root/file.json");
                o << j;
                }
    });

    //auto re=[this](int i){j["list"].erase(j["list"].begin()+(page-1)*5+i);};

    connect(ui->r1,  &QPushButton::clicked, this, [this]{ removePw(0); });
    connect(ui->r2,  &QPushButton::clicked, this, [this]{ removePw(1); });
    connect(ui->r3,  &QPushButton::clicked, this, [this]{ removePw(2); });
    connect(ui->r4,  &QPushButton::clicked, this, [this]{ removePw(3); });
    connect(ui->r5,  &QPushButton::clicked, this, [this]{ removePw(4); });


}
void managepsw::removePw(int i)
{
    j["list"].erase(j["list"].begin()+(page-1)*5+i);
    dataShow();
                    {
                    std::ofstream o("/root/file.json");
                    o << j;
    }
}

void managepsw::handlenewBClicked()
{
    //ui->browseW->hide();
    ui->editW->setVisible(true);
}

void managepsw::handlemodifyButtonClicked()
{
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
