#include "sign_in.h"
#include "ui_sign_in.h"
#include <QDebug>

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
}

void sign_in::handleloginButtonClicked()
{
    qDebug()<<"mima/yonghu cuowu //login sucessfully!";
}
