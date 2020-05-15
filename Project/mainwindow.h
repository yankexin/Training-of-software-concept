#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMouseEvent>
#include "title.h"
#include "setting.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

protected:
    void mouseReleaseEvent(QMouseEvent* event);

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    Title    *title;
    Setting  *setting;

private slots:
    void btnSetting_clicked();
    void btnHome_clicked();
    void btnCourse_clicked();
    void btnDiscuss_clicked();

    //在此行之后添加代码
};
#endif // MAINWINDOW_H
