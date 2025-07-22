#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow){
    ui->setupUi(this);
}

MainWindow::~MainWindow(){
    delete ui;
}

void MainWindow::on_pushButton0_clicked()
{
    operand = operand * 10;
    updateLcdOperand();
}

void MainWindow::on_pushButton1_clicked()
{
    operand = operand * 10 + 1;
    updateLcdOperand();
}

void MainWindow::on_pushButton2_clicked()
{
    operand = operand * 10 + 2;
    updateLcdOperand();
}

void MainWindow::on_pushButton3_clicked()
{
    operand = operand * 10 + 3;
    updateLcdOperand();
}

void MainWindow::on_pushButton4_clicked()
{
    operand = operand * 10 + 4;
    updateLcdOperand();
}

void MainWindow::on_pushButton5_clicked()
{
    operand = operand * 10 + 5;
    updateLcdOperand();
}

void MainWindow::on_pushButton6_clicked()
{
    operand = operand * 10 + 6;
    updateLcdOperand();
}

void MainWindow::on_pushButton7_clicked()
{
    operand = operand * 10 + 7;
    updateLcdOperand();
}

void MainWindow::on_pushButton8_clicked()
{
    operand = operand * 10 + 8;
    updateLcdOperand();
}

void MainWindow::on_pushButton9_clicked()
{
    operand = operand * 10 + 9;
    updateLcdOperand();
}

void MainWindow::on_pushButtonSign_clicked()
{
    operand *= -1;
    updateLcdOperand();
}

void MainWindow::on_pushButtonClear_clicked()
{
    operand = 0;
    operand2 = 0;
    str.clear();
    updateLcdOperand();
    updateLineResult();
}

void MainWindow::on_pushButtonBackspace_clicked()
{
    operand = (int)operand / 10;
    updateLcdOperand();
}

void MainWindow::on_pushButtonCalculate_clicked()
{
    calc();
    updateLcdOperand();
    updateLineResult();
}

void MainWindow::on_pushButtonPlus_clicked()
{
    performAction('+');
}

void MainWindow::on_pushButtonMinus_clicked()
{
    performAction('-');
}

void MainWindow::on_pushButtonMultipl_clicked()
{
    performAction('*');
}

void MainWindow::on_pushButtonDevide_clicked()
{
    performAction('/');
}

void MainWindow::updateLcdOperand()
{
    ui->lcdNumber->display(operand);
}

void MainWindow::updateLineResult()
{
    ui->lineResult->setText(str);
}

void MainWindow::calc()
{
    if (action == '+')
        operand2 = operand2 + operand;
    if (action == '-')
        operand2 = operand2 - operand;
    if (action == '*')
        operand2 = operand2 * operand;
    if (action == '/' && operand != 0)
        operand2 = operand2 / operand;
    if (action == '/' && operand == 0){
        str = "Error: division by zero!";
        operand = 0;
        return;
    }
    str = QString::number(operand2);
    operand = 0;
}

void MainWindow::performAction(char act)
{
    if (!str.isEmpty()){
        if (action == '*' && operand2 != 0)
            operand = 1;
        calc();
        action = act;
        str = QString::number(operand2) + action;
    }
    else{
        action = act;
        str = QString::number(operand) + action;
        operand2 = operand;
        operand = 0;
    }
    updateLineResult();
    updateLcdOperand();
}
