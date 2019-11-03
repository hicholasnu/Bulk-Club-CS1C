#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
#include <QMessageBox>
#include "menu.h"
#include <QMessageBox>
#include <QPixmap>
#include <QDesktopServices>
#include <QUrl>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    if (!connOpen())
        ui->Status->setText("Failed to open the database");
    else
        ui->Status->setText("Database Connected...");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    Menu * m1 = new Menu;

    const QString ADMIN_USERNAME = "A";
    const QString ADMIN_PASSWORD = "A";

    if (ui->lineEditUsername->text() != ADMIN_USERNAME || ui->lineEditPassword->text() != ADMIN_PASSWORD)
    {
        QMessageBox::warning(this, "Invalid", "Invalid credentials. Try again bitch.");
    }
    else
    {
        m1->show();
        this->close();
    }
}
