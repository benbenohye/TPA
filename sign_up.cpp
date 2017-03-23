#include "sign_up.h"
#include "ui_sign_up.h"
#include <QDebug>

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
    qDebug()<<"cuowu//zhuce chenggong!";
}
