#include "sign_in.h"
#include "ui_sign_in.h"
#include <QDebug>
#include <QMessageBox>
#include <string>

sign_in::sign_in(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::sign_in)
{
    ui->setupUi(this);
    this->setupCOnnections();
}

sign_in::~sign_in()
{
    delete ui;
}

void sign_in::setupCOnnections()
{
    connect(this->ui->loginButton,SIGNAL(clicked(bool)),this,SLOT(handleloginButtonClicked()));
    connect(this->ui->exitButton,SIGNAL(clicked(bool)),this,SLOT(handleexitButtonClicked()));
}

void sign_in::handleloginButtonClicked()
{
    auto user = ui->userNameEdit->text();
    auto pwd = ui->passwordEdit->text();
    //if(ui->userNameEdit->text()==tr("benben")&&ui->passwordEdit->text()==tr("1234"))
    if(user.toStdString()== j["username"]&&pwd.toStdString()==j["password"])
    {
    //qDebug()<<"mima/yonghu cuowu //login sucessfully!";
    h1.show();
    this->close();
    }
    else
    {
        QMessageBox::warning(this,tr("Warning"),tr("user name or password error"),QMessageBox::Yes);
        ui->userNameEdit->clear();
        ui->passwordEdit->clear();
        ui->userNameEdit->setFocus();
    }
}

void sign_in::handleexitButtonClicked()
{

}
