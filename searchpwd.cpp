#include "searchpwd.h"
#include "ui_searchpwd.h"
#include <QDebug>
#include <string>
#include <fstream>
#include <QMessageBox>
using namespace std;
extern string username;
searchpwd::searchpwd(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::searchpwd)
{
    ui->setupUi(this);
    this->setupconnections();
    ui->oldpwdEdit->setEchoMode(QLineEdit::Password);
    ui->newpwdEdit->setEchoMode(QLineEdit::Password);
    ui->confpwdEdit->setEchoMode(QLineEdit::Password);
}

searchpwd::~searchpwd()
{
    delete ui;
}

void searchpwd::setupconnections()
{
    connect(this->ui->saveButton,SIGNAL(clicked(bool)),this,SLOT(handlesaveButtonClicked()));
}

void searchpwd::handlesaveButtonClicked()
{
    auto op = ui->oldpwdEdit->text();
    auto p = ui->newpwdEdit->text();
    auto cp = ui->confpwdEdit->text();
    string password = md5(op.toStdString());
    if(j[username]["password"]==password)
    {
    if(p!=NULL)
    {
    if ( p==cp)
    {
       if(p.length()<6)
        {
           QMessageBox::information(this,"warning","the password is too short!");
        }
        else if(p.length()>30)
        {
           QMessageBox::information(this,"warning","the password is too long!");
        }
        else
       {
        j[username]["password"] = md5(p.toStdString());
        {
                std::ofstream i(string(getenv("HOME"))+"/file.json");
                i << j;
        }
        QMessageBox::information(this,"warning","successfully!");
        this->close();
        }
    }
        else
        {
              QMessageBox::warning(this,"fail","the new password is different!",QMessageBox::Yes);
        }
    }
    else
    {
        QMessageBox::warning(this,"fail","the new password is NULL!",QMessageBox::Yes);
    }
    }
    else
    {
        QMessageBox::warning(this,"fail","the old password is error!",QMessageBox::Yes);
    }
    }



