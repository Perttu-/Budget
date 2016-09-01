#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "iostream"
#include "databaseinterface.h"
#include <QInputDialog>
#include <QDebug>
#include <QDir>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    DatabaseInterface dbInterface;
    dbInterface.initializeDatabase();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionExit_triggered()
{
    qApp->quit();
}

void MainWindow::on_actionNew_Category_triggered()
{

    bool ok;
    QString text = QInputDialog::getText(this, tr("New Category"),
                                               tr("Enter category name:"),
                                               QLineEdit::Normal,"", &ok);
    dbInterface.addCategory();
}

void MainWindow::on_addTestProfile_clicked()
{
    dbInterface.addProfile("Tester","PSWRD");
}

void MainWindow::on_pushButton_2_clicked()
{

}

void MainWindow::on_pushButton_3_clicked()
{

}

void MainWindow::on_actionChange_Profile_triggered()
{

}
