#include "mainwindow.h"
#include <sign_in.h>
#include <sign_up.h>
#include <home_screen.h>
#include <managepsw.h>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    sign_in s1;
    s1.show();
    sign_up s2;
    s2.show();
    home_screen h;
    h.show();
    managepsw m;
    m.show();
    return a.exec();
}
