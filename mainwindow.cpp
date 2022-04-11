#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFileDialog>
#include <QLabel>
#include <QPixmap>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

void MainWindow::chooseFile()
{
    QString filename = QFileDialog::getOpenFileName(this, "Selectionnez le fichier à cacher", "", "All Files (*)");
    QFile file(filename);
    ui->showFileName->setText(filename);
}

void MainWindow::chooseImage()
{
    QString filename = QFileDialog::getOpenFileName(this, "Selectionnez l'image porteuse", "", "files (*.png)");
    QPixmap image(filename, "PNG");
    ui->imageShow->setPixmap(image);
}

void MainWindow::chooseImageForDecode()
{
    QString filename = QFileDialog::getOpenFileName(this, "Selectionnez l'image porteuse", "", "files (*.png)");
    QPixmap image(filename, "PNG");
    ui->showImageDecode->setPixmap(image);
}

void MainWindow::downloadFile()
{
    QString filename = QFileDialog::getSaveFileName(this, "Selectionnez le fichier à cacher", "", "All Files (*)");
    QFile file(filename);
}

void MainWindow::chooseImageForAnalyse()
{
    QString filename = QFileDialog::getOpenFileName(this, "Selectionnez l'image porteuse", "", "files (*.png)");
    QPixmap image(filename, "PNG");
    ui->showImageAnalyse->setPixmap(image);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_chooseFileButton_clicked()
{
    chooseFile();
}


void MainWindow::on_ChooseImageButton_clicked()
{
   chooseImage();
}


void MainWindow::on_uploadButtonForDecode_clicked()
{
    chooseImageForDecode();
}


void MainWindow::on_decodeButton_clicked()
{

}


void MainWindow::on_downloadButton_clicked()
{

}


void MainWindow::on_uploadButtonForAnalyse_clicked()
{
    chooseImageForAnalyse();
}

