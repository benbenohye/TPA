#include "modify.h"
#include "ui_modify.h"
#include <QDebug>
#include <string>
#include <fstream>
#include <QMessageBox>
extern int a;


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
  //qDebug()<<"modify sucessfully!";
           auto&ja = j["list"][a];
            auto usr1 = ui->usrnameEdit->text();
            auto pwd1 = ui->passwordEdit->text();
            auto pwd2 = ui->confirmpwdEdit->text();
            auto desc1 =ui->descriptionEdit->toPlainText();
            if(pwd1 == pwd2)
            {
                if(usr1!= NULL)
                {
                ja["usrname"] = usr1.toStdString();
                ja["pwd"] = pwd1.toStdString();
                ja["detail"]=desc1.toStdString();
                {
                std::ofstream k("/root/file.json");
                k<< j;
                }
                QMessageBox::information(this,"OK","modify successfully!",QMessageBox::Yes);
                this->close();
                }
                else
                {
                     QMessageBox::warning(this,"fail","the usrname is NULL!",QMessageBox::Yes);
                }
            }
            else
            {
                QMessageBox::warning(this,"fail","the passwords are different!",QMessageBox::Yes);
                //this->show();
                ui->confirmpwdEdit->clear();
                ui->confirmpwdEdit->setFocus();
            }
}
