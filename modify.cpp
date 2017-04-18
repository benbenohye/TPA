#include "modify.h"
#include "ui_modify.h"
#include <QDebug>
#include <string>
#include <fstream>
#include <QMessageBox>
#include "base64.h"
extern int a;
char*getenv(char*name);
using namespace std;
extern string username;


modify::modify(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::modify)
{
    ui->setupUi(this);
    this->setupconnections();
    ui->passwordEdit->setEchoMode(QLineEdit::Password);
    ui->confirmpwdEdit->setEchoMode(QLineEdit::Password);
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
            auto&ja = j[username]["list"][a];
            auto usr1 = ui->usrnameEdit->text();
            auto pwd1 = ui->passwordEdit->text();
            auto pwd2 = ui->confirmpwdEdit->text();
            auto desc1 =ui->descriptionEdit->toPlainText();
            if(pwd1 == pwd2)
            {
                if(usr1!= NULL)
                {
                    unsigned char key[16];
                    string str2 = j[username]["password"];
                    strcpy((char*)key,str2.c_str());
                    AES aes(key);
                    string str1 = pwd1.toStdString();
                    unsigned char str[16];
                    strcpy((char*)str,str1.c_str());
                    string str3 = (char*)aes.Cipher(str);
                    string encoded = base64_encode(reinterpret_cast<const unsigned char*>(str3.c_str()), str3.length());
                ja["usrname"] = usr1.toStdString();
                ja["pwd"] = encoded;
                ja["detail"]=desc1.toStdString();
                {
                std::ofstream k(string(getenv("HOME"))+"/file.json");
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
