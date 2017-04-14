#include "searchpwd.h"
#include "ui_searchpwd.h"
#include <QDebug>
#include <string>
#include <fstream>
#include <QMessageBox>
using namespace std;

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
    connect(this->ui->saveButton,SIGNAL(clicked(bool)),this,SLOT(handlesaveButtonClicked()));

}

void searchpwd::handlsaveButtonClicked()
{
    auto p = ui->newpwdEdit->text();
    auto cp = ui->confpwdEdit->text();
    if(p!=NULL)
    {
    if ( p==cp)
    {
        j["password"] = md5(p.toStdString());
        {
                std::ofstream i("/root/file.json");
                i << j;
        }
        QMessageBox::information(this,"warning","successfully!");
        this->close();
        }
        else
        {
              QMessageBox::warning(this,"fail","the password is different!",QMessageBox::Yes);
        }
    }
    else
    {
        QMessageBox::warning(this,"fail","the password is NULL!",QMessageBox::Yes);
    }
    }



