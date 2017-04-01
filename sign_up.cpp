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
        j2["username"] = u.toStdString();
        j2["password"] = p.toStdString();
        {
                std::ofstream i(string(getenv("HOME"))+"/file.json");
                i << j2;
        }
        QMessageBox::information(this,"warning","successfully!");
        this->close();
    }
    else
    {
        QMessageBox::warning(this,tr("Warning"),tr("the password is different!"),QMessageBox::Yes);
        ui->confirmPWEdit->clear();
        ui->passwordEdit->setFocus();
    }

}
