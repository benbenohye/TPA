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
string username;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    std::ifstream i(string(getenv("HOME"))+"/file.json");
    if(i){
    i >> j;
    }
    else{}
    return a.exec();

}
