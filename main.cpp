#include "mainwindow.h"
#include <sign_in.h>
#include <sign_up.h>
#include <home_screen.h>
#include <managepsw.h>
#include <QApplication>
#include <fstream>
#include <json.hpp>
#include <QDebug>
char*getenv(char*name);
using json = nlohmann::json;
json j;
int a;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    /*
    sign_in s1;
    s1.show();
    sign_up s2;
    s2.show();
    home_screen h;
    h.show();
    managepsw m;
    m.show();


    j["username"]="benben";   //input username
    j["userid"]="007";   //userid is automatic
    j["password"]="1234";   //input password
    j["list"]={1};   //save the first password
    j["list"][1]["pwd"]="34567"; //the first pwd duplicate
    j["list"][1]["pwd"]["34567"]["detail"]="just a try1"; //the password description
    std::ofstream o("/root/file.json");
    o << j;

    j["username"]="nana";
    j["userid"]="A01";
    j["password"]="5678";
    j["list"]={3,2}; //save two pwd
    j["list"][3]["pwd"]="hhhh";  //the first pwd duplicate
    j["list"][3]["pwd"]["hhhh"]["detail"]="just a try2";  //the first pwd description
    j["list"][2]["pwd"]="kkkk";// the second pwd duplicate
    j["lsit"][2]["pwd"]["kkkk"]["detail"]="just a try3";  //the second pwd description
    {
    std::ofstream o("/root/file.json");
    o << j;
    }


    {
    json u1,u2,u3;
    j["username"]="benben";   //input username
    //j["userid"]="007";   //userid is automatic
    j["password"]="1234";   //input password
    u1["usrname"]="benben"; //the first usr
    u1["pwd"]="34567"; //the first pwd duplicate
    u1["detail"]="just a try1"; //the firstpwd description
    u2["usrname"]="sb"; //the second usr
    u2["pwd"]="34568"; //the first pwd duplicate
    u2["detail"]="just a try2"; //the second description
    u3["usrname"]="nana";   //the third usr
    u3["pwd"]="34569"; //the first pwd duplicate
    u3["detail"]="just a try3"; //the third description
    j["list"]={u1,u2,u3}; //save three password
    for(int i=0;i<50;i++){
        j["list"].push_back(u1);
        j["list"].push_back(u2);
        j["list"].push_back(u3);
    }
    }
    {
    std::ofstream o("/root/file.json");
    o << j;
    }
    //qDebug()<<j.dump(4).c_str();
    */
    std::ifstream i(string(getenv("HOME"))+"/file.json");
    if(i){
    i >> j;

    }
    else{}
    return a.exec();

}
