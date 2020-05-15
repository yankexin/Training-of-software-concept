#ifndef SETTING_H
#define SETTING_H

#include <QWidget>

namespace Ui {
class Setting;
}

class Setting : public QWidget
{
    Q_OBJECT

public:
    explicit Setting(QWidget *parent = nullptr);
    ~Setting();

private slots:
    void on_btnExit_clicked();

private:
    Ui::Setting *ui;

signals:
    void exitClicked();
};

#endif // SETTING_H
