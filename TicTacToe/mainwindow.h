#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <random>
#include <vector>
#include <algorithm>

using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    bool xIsClicked = false;
    bool oIsClicked = false;
    bool btn0 = false;
    bool btn1 = false;
    bool btn2 = false;
    bool btn3 = false;
    bool btn4 = false;
    bool btn5 = false;
    bool btn6 = false;
    bool btn7 = false;
    bool btn8 = false;

    bool playerActive = true;

    bool gameActive = true;

    vector<int> originalList = {0,1,2,3,4,5,6,7,8};

private slots:
    void on_x_Btn_clicked();

    void on_o_Btn_clicked();

    void on_Btn0_clicked();

    void on_Btn1_clicked();

    void on_Btn2_clicked();

    void on_Btn3_clicked();

    void on_Btn4_clicked();

    void on_Btn5_clicked();

    void on_Btn6_clicked();

    void on_Btn7_clicked();

    void on_Btn8_clicked();

    void checkWinCondition();

    void CPUCode();
    void resetGame();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
