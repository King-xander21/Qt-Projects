#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <random>
using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    //, xIsClicked(false)
    //, oIsClicked(false)
    //, btn0(false)
    //, btn1(false)
    //, btn2(false)
    //, btn3(false)
    //, btn4(false)
    //, btn5(false)
    //, btn6(false)
    //, btn7(false)
    //, btn8(false)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_x_Btn_clicked()
{
    xIsClicked = true;
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_o_Btn_clicked()
{
    oIsClicked = true;
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_Btn0_clicked()
{
    if (playerActive == true)
    {
        // removes 0 from the list.
        originalList.erase(remove(originalList.begin(), originalList.end(), 0), originalList.end());
        int size = originalList.size();
        ui->label_4->setText(QString::number(size));

        btn0 = true;
        ui->Btn0->setText("X");
        checkWinCondition();
        playerActive = false;
        if (playerActive == false)
        {
            ui->label_5->setText("false");
        }
        else
        {
            ui->label_5->setText("true");
        }
    }
    CPUCode();
}

void MainWindow::on_Btn1_clicked()
{
    if (playerActive == true)
    {
        // removes 1 from the list.
        originalList.erase(remove(originalList.begin(), originalList.end(), 1), originalList.end());
        int size = originalList.size();
        ui->label_4->setText(QString::number(size));

        btn1 = true;
        ui->Btn1->setText("X");
        checkWinCondition();
        playerActive = false;
    }
    CPUCode();
}

void MainWindow::on_Btn2_clicked()
{
    if (playerActive == true)
    {
        // removes 2 from the list.
        originalList.erase(remove(originalList.begin(), originalList.end(), 2), originalList.end());
        int size = originalList.size();
        ui->label_4->setText(QString::number(size));

        btn2 = true;
        ui->Btn2->setText("X");
        checkWinCondition();
        playerActive = false;
    }
    CPUCode();
}

void MainWindow::on_Btn3_clicked()
{
    if (playerActive == true)
    {
        // removes 3 from the list.
        originalList.erase(remove(originalList.begin(), originalList.end(), 3), originalList.end());
        int size = originalList.size();
        ui->label_4->setText(QString::number(size));

        btn3 = true;
        ui->Btn3->setText("X");
        checkWinCondition();
        playerActive = false;
    }
}

void MainWindow::on_Btn4_clicked()
{
    if (playerActive == true)
    {
        // removes 4 from the list.
        originalList.erase(remove(originalList.begin(), originalList.end(), 4), originalList.end());
        int size = originalList.size();
        ui->label_4->setText(QString::number(size));

        btn4 = true;
        ui->Btn4->setText("X");
        checkWinCondition();
        playerActive = false;
    }
    CPUCode();
}

void MainWindow::on_Btn5_clicked()
{
    if (playerActive == true)
    {
        // removes 5 from the list.
        originalList.erase(remove(originalList.begin(), originalList.end(), 5), originalList.end());
        int size = originalList.size();
        ui->label_4->setText(QString::number(size));

        btn5 = true;
        ui->Btn5->setText("X");
        checkWinCondition();
        playerActive = false;
    }
    CPUCode();
}

void MainWindow::on_Btn6_clicked()
{
    if (playerActive == true)
    {
        // removes 6 from the list.
        originalList.erase(remove(originalList.begin(), originalList.end(), 6), originalList.end());
        int size = originalList.size();
        ui->label_4->setText(QString::number(size));

        btn6 = true;
        ui->Btn6->setText("X");
        checkWinCondition();
        playerActive = false;
    }
    CPUCode();
}

void MainWindow::on_Btn7_clicked()
{
    if (playerActive == true)
    {
        // removes 7 from the list.
        originalList.erase(remove(originalList.begin(), originalList.end(), 7), originalList.end());
        int size = originalList.size();
        ui->label_4->setText(QString::number(size));

        btn7 = true;
        ui->Btn7->setText("X");
        checkWinCondition();
        playerActive = false;
    }
    CPUCode();
}

void MainWindow::on_Btn8_clicked()
{
    if (playerActive == true)
    {
        // removes 8 from the list.
        originalList.erase(remove(originalList.begin(), originalList.end(), 8), originalList.end());
        int size = originalList.size();
        ui->label_4->setText(QString::number(size));

        btn8 = true;
        ui->Btn8->setText("X");
        checkWinCondition();
        playerActive = false;
    }
    CPUCode();
}

void MainWindow::checkWinCondition()
{
    if (btn0 && btn1 && btn2)  // Top Straight
    {
        QMessageBox::information(this, "Status", "Player1 Wins");
        resetGame();
    }
    else if (btn0 && btn3 && btn6) // Left Down
    {
        QMessageBox::information(this, "Status","Player1 Wins");
        resetGame();
    }
    else if (btn0 && btn4 && btn8) // Left Diagonal
    {
        QMessageBox::information(this, "Status","Player1 Wins");
        resetGame();
    }

    else if (btn1 && btn4 && btn7) // Mid Down
    {
        QMessageBox::information(this, "Status","Player1 Wins");
        resetGame();
    }
    else if (btn2 && btn5 && btn8) // Right Down
    {
        QMessageBox::information(this, "Status","Player1 Wins");
        resetGame();
    }
    else if (btn3 && btn4 && btn5) // Mid Straight
    {
        QMessageBox::information(this, "Status","Player1 Wins");
        resetGame();
    }
    else if (btn6 && btn7 && btn8) // Down Straight
    {
        QMessageBox::information(this, "Status","Player1 Wins");
        resetGame();
    }
    else if (btn2 && btn4 && btn6) // Right Diagonal
    {
        QMessageBox::information(this, "Status","Player1 Wins");
        resetGame();
    }

    // Add other win conditions as needed
}

void MainWindow::CPUCode()
{
    int randomIndex;
    int randomNumber;
    int indexSize = originalList.size() -1;
    ui->label_6->setText("Running");

    // conditions for CPU control
    if (playerActive == false /*true*/ && btn0 == true)
    {
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> distr(0, indexSize);
        randomIndex = distr(gen);
        randomNumber = originalList[randomIndex];
        ui->label_3->setText(QString::number(randomNumber));
    }

    if (playerActive == false && btn1 == true)
    {
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> distr(0, indexSize);
        randomIndex = distr(gen);
        randomNumber = originalList[randomIndex];
        ui->label_3->setText(QString::number(randomNumber));
    }

    if (playerActive == false && btn2 == true)
    {
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> distr(0, indexSize);
        randomIndex = distr(gen);
        randomNumber = originalList[randomIndex];
        ui->label_3->setText(QString::number(randomNumber));
    }

    if (playerActive == false && btn3 == true)
    {
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> distr(0, indexSize);
        randomIndex = distr(gen);
        randomNumber = originalList[randomIndex];
        ui->label_3->setText(QString::number(randomNumber));
    }

    if (playerActive == false && btn4 == true)
    {
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> distr(0, indexSize);
        randomIndex = distr(gen);
        randomNumber = originalList[randomIndex];
        ui->label_3->setText(QString::number(randomNumber));
    }

    if (playerActive == false && btn5 == true)
    {
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> distr(0, indexSize);
        randomIndex = distr(gen);
        randomNumber = originalList[randomIndex];
        ui->label_3->setText(QString::number(randomNumber));
    }

    if (playerActive == false && btn6 == true)
    {
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> distr(0, indexSize);
        randomIndex = distr(gen);
        randomNumber = originalList[randomIndex];
        ui->label_3->setText(QString::number(randomNumber));
    }

    if (playerActive == false && btn7 == true)
    {
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> distr(0, indexSize);
        randomIndex = distr(gen);
        randomNumber = originalList[randomIndex];
        ui->label_3->setText(QString::number(randomNumber));
    }

    if (playerActive == false && btn8 == true)
    {
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> distr(0, indexSize);
        randomIndex = distr(gen);
        randomNumber = originalList[randomIndex];
        ui->label_3->setText(QString::number(randomNumber));
    }

    // Conditions for CPU Play
    if (randomNumber == 0)
    {
        ui->Btn0->setText("O");
        originalList.erase(remove(originalList.begin(), originalList.end(), randomNumber), originalList.end());
        playerActive = true;
    }

    if (randomNumber == 1)
    {
        ui->Btn1->setText("O");
        originalList.erase(remove(originalList.begin(), originalList.end(), randomNumber), originalList.end());
        playerActive = true;    
    }

    if (randomNumber == 2)
    {
        ui->Btn2->setText("O");
        originalList.erase(remove(originalList.begin(), originalList.end(), randomNumber), originalList.end());
        playerActive = true;
    }

    if (randomNumber == 3)
    {
        ui->Btn3->setText("O");
        originalList.erase(remove(originalList.begin(), originalList.end(), randomNumber), originalList.end());
        playerActive = true;
    }

    if (randomNumber == 4)
    {
        ui->Btn4->setText("O");
        originalList.erase(remove(originalList.begin(), originalList.end(), randomNumber), originalList.end());
        playerActive = true;
    }

    if (randomNumber == 5)
    {
        ui->Btn5->setText("O");
        originalList.erase(remove(originalList.begin(), originalList.end(), randomNumber), originalList.end());
        playerActive = true;
    }

    if (randomNumber == 6)
    {
        ui->Btn6->setText("O");
        originalList.erase(remove(originalList.begin(), originalList.end(), randomNumber), originalList.end());
        playerActive = true;
    }

    if (randomNumber == 7)
    {
        ui->Btn7->setText("O");
        originalList.erase(remove(originalList.begin(), originalList.end(), randomNumber), originalList.end());
        playerActive = true;
    }

    if (randomNumber == 8)
    {
        ui->Btn8->setText("O");
        originalList.erase(remove(originalList.begin(), originalList.end(), randomNumber), originalList.end());
        playerActive = true;
    }

    // Condition for empty list
    if (originalList.size()<0)
    {
        QMessageBox::information(this, "Player Status", "Draw");
        resetGame();
    }
}

void MainWindow::resetGame()
{
    originalList = {0,1,2,3,4,5,6,7,8};

    ui->Btn0->setText(" ");
    ui->Btn1->setText(" ");
    ui->Btn2->setText(" ");
    ui->Btn3->setText(" ");
    ui->Btn4->setText(" ");
    ui->Btn5->setText(" ");
    ui->Btn6->setText(" ");
    ui->Btn7->setText(" ");
    ui->Btn8->setText(" ");

    btn0 = false;
    btn1 = false;
    btn2 = false;
    btn3 = false;
    btn4 = false;
    btn5 = false;
    btn6 = false;
    btn7 = false;
    btn8 = false;
    playerActive = true;
}


