#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFile>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    void chooseFile();
    void chooseImage();
    void chooseImageForDecode();
    void decode();
    void encode();
    void analyse();
    void downloadFile();
    void chooseImageForAnalyse();
    ~MainWindow();

private slots:
    void on_chooseFileButton_clicked();

    void on_ChooseImageButton_clicked();

    void on_uploadButtonForDecode_clicked();

    void on_decodeButton_clicked();

    void on_uploadButtonForAnalyse_clicked();

    void on_encodeButton_clicked();

    void on_dowloadEncodeImage_clicked();

private:
    Ui::MainWindow *ui;
    QFile fileInput, fileOutput;
    QImage imageInput, imageOutput;
    QString filename, imageName;
};
#endif // MAINWINDOW_H
