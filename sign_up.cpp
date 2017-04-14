#include "sign_up.h"
#include "ui_sign_up.h"
#include <QDebug>
#include <QMessageBox>
#include <fstream>
char*getenv(char*name);
//#include <getenv>
#include <string>
using namespace std;


//#include <char *getenv()>

sign_up::sign_up(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::sign_up)
{
    ui->setupUi(this);
    this->setupCOnnections();
}

sign_up::~sign_up()
{
    delete ui;
}

void sign_up::setupCOnnections()
{
    connect(this->ui->finishButton,SIGNAL(clicked(bool)),this,SLOT(handelfinishButtonClicked()));
}

void sign_up::handelfinishButtonClicked()
{
    //qDebug()<<"cuowu//zhuce chenggong!";
    json j2;
    auto u = ui->userNameEdit->text();
    auto p = ui->passwordEdit->text();
    if ( ui->confirmPWEdit->text()==p)
    {
        if(u == NULL||p == NULL)
        {
           QMessageBox::warning(this,"fail","the usrname or password is NULL!",QMessageBox::Yes);
        }
        else if(p.length()<6)
        {
           QMessageBox::information(this,"warning","the password is too short!");
        }
        else if(p.length()>30)
        {
           QMessageBox::information(this,"warning","the password is too long!");
        }
        else
        {
        j2["username"] = u.toStdString();
        j2["password"] = md5(p.toStdString());
        {
                std::ofstream o(string(getenv("HOME"))+"/file.json");
                o << j2;
        }
        QMessageBox::information(this,"warning","successfully!");
        this->close();
        }
    }
    else
    {
        QMessageBox::warning(this,tr("Warning"),tr("the password is different!"),QMessageBox::Yes);
        ui->confirmPWEdit->clear();
        ui->passwordEdit->setFocus();
    }

}
