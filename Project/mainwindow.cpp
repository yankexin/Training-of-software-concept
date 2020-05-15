#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowIcon(QIcon(":/images/logo.ico"));
    this->setWindowFlags(Qt::FramelessWindowHint);

    title = new Title(ui->centralwidget);
    title->setGeometry(0, 0, 1200, 80);
    setting = new Setting(ui->centralwidget);
    setting->setGeometry(960, 30, 150, 200);
    setting->setVisible(false);
    ui->tabWidget->setCurrentIndex(0);

    connect(title, SIGNAL(closeClicked()), this, SLOT(close()));
    connect(title, SIGNAL(minClicked()), this, SLOT(showMinimized()));
    connect(title, SIGNAL(settingClicked()), this, SLOT(btnSetting_clicked()));
    connect(title, SIGNAL(homeClicked()), this, SLOT(btnHome_clicked()));
    connect(title, SIGNAL(courseClicked()), this, SLOT(btnCourse_clicked()));
    connect(title, SIGNAL(discussClicked()), this, SLOT(btnDiscuss_clicked()));
    connect(setting, SIGNAL(exitClicked()), this, SLOT(close()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::btnSetting_clicked()
{
    if(setting->isVisible())
    {
        setting->setVisible(false);
    }
    else
    {
        setting->setVisible(true);
    }
}

void MainWindow::mouseReleaseEvent(QMouseEvent* event)
{
    setting->setVisible(false);
}

void MainWindow::btnHome_clicked()
{
    ui->tabWidget->setCurrentIndex(0);
}

void MainWindow::btnCourse_clicked()
{
    ui->tabWidget->setCurrentIndex(1);
}

void MainWindow::btnDiscuss_clicked()
{
    ui->tabWidget->setCurrentIndex(2);
}

//在此行后添加代码
