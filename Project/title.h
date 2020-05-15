#ifndef TITLE_H
#define TITLE_H

#include <QWidget>
#include <QMouseEvent>

namespace Ui {
class Title;
}

class Title : public QWidget
{
    Q_OBJECT


protected:
    void mouseMoveEvent(QMouseEvent* event);
    void mousePressEvent(QMouseEvent* event);
    void mouseReleaseEvent(QMouseEvent* event);

public:
    explicit Title(QWidget *parent = nullptr);
    ~Title();

private:
    Ui::Title *ui;
    QPoint mLastMousePosition;\
    bool mMoving;
    QString stylesheet[6] = {"QPushButton{image: url(:/images/home.png); border-style:outset; }QPushButton:hover{image: url(:/images/home_hover.png);}",
                            "QPushButton{image: url(:/images/course.png); border-style:outset; }QPushButton:hover{image: url(:/images/course_hover.png);}",
                            "QPushButton{image: url(:/images/discuss.png); border-style:outset; }QPushButton:hover{image: url(:/images/discuss_hover.png);}",
                            "image: url(:/images/home_pressed.png);border-style:outset;", "image: url(:/images/course_pressed.png);border-style:outset;", "image: url(:/images/discuss_pressed.png);border-style:outset;"};
    int choise = 1;

signals:
    void minClicked();
    void maxClicked();
    void closeClicked();
    void settingClicked();
    void homeClicked();
    void courseClicked();
    void discussClicked();

private slots:
    void on_btnMin_clicked();
    void on_btnMax_clicked();
    void on_btnClose_clicked();
    void on_btnSetting_clicked();
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
};

#endif // TITLE_H
