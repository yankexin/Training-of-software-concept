#include "title.h"
#include "ui_title.h"

Title::Title(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Title)
{
    ui->setupUi(this);
}

Title::~Title()
{
    delete ui;
}

void Title::on_btnMin_clicked()
{
    emit minClicked();
}

void Title::on_btnMax_clicked()
{
    emit maxClicked();
}

void Title::on_btnClose_clicked()
{
    emit closeClicked();
}

void Title::mousePressEvent(QMouseEvent* event)
{
    if(event->button() == Qt::LeftButton)
    {
        mMoving = true;
        mLastMousePosition = event->globalPos();
    }
}

void Title::mouseMoveEvent(QMouseEvent* event)
{
    if( event->buttons().testFlag(Qt::LeftButton) && mMoving)
    {
        this->window()->move(this->window()->pos() + (event->globalPos() - mLastMousePosition));
        mLastMousePosition = event->globalPos();
    }
}

void Title::mouseReleaseEvent(QMouseEvent* event)
{
    if(event->button() == Qt::LeftButton)
    {
        mMoving = false;
    }
}

void Title::on_btnSetting_clicked()
{
    emit settingClicked();
}

void Title::on_pushButton_clicked()
{
    if(choise != 1)
    {
        ui->pushButton->setStyleSheet(stylesheet[3]);
        if(choise == 2)
            ui->pushButton_2->setStyleSheet(stylesheet[1]);
        else
            ui->pushButton_3->setStyleSheet(stylesheet[2]);
        choise = 1;
        emit homeClicked();
    }
}

void Title::on_pushButton_2_clicked()
{
    if(choise != 2)
    {
        ui->pushButton_2->setStyleSheet(stylesheet[4]);
        if(choise == 1)
            ui->pushButton->setStyleSheet(stylesheet[0]);
        else
            ui->pushButton_3->setStyleSheet(stylesheet[2]);
        choise = 2;
        emit courseClicked();
    }
}

void Title::on_pushButton_3_clicked()
{
    if(choise != 3)
    {
        ui->pushButton_3->setStyleSheet(stylesheet[5]);
        if(choise == 1)
            ui->pushButton->setStyleSheet(stylesheet[0]);
        else
            ui->pushButton_2->setStyleSheet(stylesheet[1]);
        choise = 3;
        emit discussClicked();
    }
}
