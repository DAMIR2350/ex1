#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include "QFile"
#include "QIntValidator"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->lineEdit_4->setValidator( new QIntValidator(0, 100, this) );;

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    if (ui ->lineEdit->text() =="" or ui ->lineEdit_2->text()=="" or ui ->lineEdit_3->text()=="" or ui ->lineEdit_4->text()=="" or ui ->lineEdit_5->text()=="" ){
        QMessageBox::critical(this,"Ошибка","Заполните все поля!");
    }else{
        if (ui ->lineEdit_5->text()!=ui ->lineEdit_6->text()){
            QMessageBox::critical(this,"Ошибка","Пароли не совпадают!");
        }else{
            QString text1 = ui ->lineEdit->text();
            QString text2 = ui ->lineEdit_2->text();
            QString text3 = ui ->lineEdit_4->text();
            QString text4 = ui ->lineEdit_3->text();
            QString text5 = ui ->lineEdit_5->text();
            QFile file("C:\\test.txt");
            file.open(QIODevice::Append);
            file.write(text1.toUtf8() + " " + text2.toUtf8() + " " + text4.toUtf8() + " " + text3.toUtf8() + " " + text5.toUtf8()+"\n") ;

            file.close();
            close();
        }

    }


}


void MainWindow::on_pushButton_2_clicked()
{
    ui ->lineEdit->clear();
    ui ->lineEdit_2->clear();
    ui ->lineEdit_3->clear();
    ui ->lineEdit_4->clear();
    ui ->lineEdit_5->clear();
    ui ->lineEdit_6->clear();
    //lineEdit.clear();
}

