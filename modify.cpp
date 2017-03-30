#include "modify.h"
#include "ui_modify.h"
#include <QDebug>

modify::modify(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::modify)
{
    ui->setupUi(this);
    this->setupconnections();
}

modify::~modify()
{
    delete ui;
}

void modify::setupconnections()
{
    connect(this->ui->saveButton,SIGNAL(clicked(bool)),this,SLOT(handlesaveButtonClicked()));
}

void modify::handlesaveButtonClicked()
{
  qDebug()<<"modify sucessfully!";
}
