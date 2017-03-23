#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setupConnections();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setupConnections()
{
    connect(this->ui->sign_InButton,SIGNAL(clicked(bool)),this,SLOT(handlesign_InButtonClicked()));
    connect(this->ui->sign_UpButton,SIGNAL(clicked(bool)),this,SLOT(handlesign_UpButtonClicked()));
}

void MainWindow::handlesign_InButtonClicked()
{
    qDebug() << "denglu! zhuandao sign_in";
}

void MainWindow::handlesign_UpButtonClicked()
{
    qDebug() <<"zhuce,zhuandao sign_up";
}
