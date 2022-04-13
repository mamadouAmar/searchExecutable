#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFileDialog>
#include <QLabel>
#include <QPixmap>
#include "image.h"
#include "algo.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

void MainWindow::chooseFile()
{
    QString filename = QFileDialog::getOpenFileName(this, "Selectionnez le fichier à cacher", "", "All Files (*)");
    fileInput.setFileName(filename);
    ui->showFileName->setText(filename);
}

void MainWindow::chooseImage()
{
    QString filename = QFileDialog::getOpenFileName(this, "Selectionnez l'image porteuse", "", "files (*.bmp)");
    QPixmap image(filename, "BMP");
    imageInput = image.toImage();
    ui->imageShow->setPixmap(QPixmap::fromImage(imageInput));
}

void MainWindow::chooseImageForDecode()
{
    QString filename = QFileDialog::getOpenFileName(this, "Selectionnez l'image porteuse", "", "files (*.bmp)");
    QPixmap image(filename, "BMP");
    imageInput = image.toImage();
    ui->showImageDecode->setPixmap(image);
}

void MainWindow::decode()
{
    Image image = Image(imageInput, "bmp");
    QByteArray byteimage = image.toByteArray();
    QBitArray bitimage = bytesToBits(byteimage);
    QBitArray bitFile = image.destego(image.getExtension(), byteimage, bitimage);
    QByteArray byteFile = bitsToBytes(bitFile);
    QString filename = QFileDialog::getSaveFileName(this, "Enregistrer le fichier à cacher", "", "All Files (*)");
    QFile file(filename);
    file.open(QIODevice::WriteOnly);
    file.write(byteFile);
    file.close();

}

void MainWindow::encode()
{
    Image image = Image(imageInput, "bmp");
    QByteArray byteimage = image.toByteArray();
    QBitArray bitimage = bytesToBits(byteimage);
    fileInput.open(QIODevice::ReadOnly);
    QByteArray byteFile = fileInput.readAll();
    fileInput.close();
    QBitArray bitfile = bytesToBits(byteFile);
    if(bitfile.size()>(bitimage.size())/4){
        QMessageBox::warning(this,"echec", "Taille du fichier trop grand");
        return;
    }
    QBitArray bitresult = image.stego(image.getExtension(), byteimage, bitimage, bitfile);
    QByteArray byteresult = bitsToBytes(bitresult);
    imageOutput = QImage::fromData(byteresult);
    ui->showEncodedImage->setPixmap(QPixmap::fromImage(imageOutput));
}

void MainWindow::downloadFile()
{
    QString filename = QFileDialog::getSaveFileName(this, "Enregistrer le fichier à cacher", "", "files (*.bmp)");
    QFile file(filename);
    imageOutput.save(filename);
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
    decode();
}

void MainWindow::on_uploadButtonForAnalyse_clicked()
{
    chooseImageForAnalyse();
}


void MainWindow::on_encodeButton_clicked()
{
   encode();
}


void MainWindow::on_dowloadEncodeImage_clicked()
{
    downloadFile();
}

