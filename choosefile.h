#ifndef CHOOSEFILE_H
#define CHOOSEFILE_H

#include <QFile>

class chooseFile
{
private:
    QFile file;
    QString filename;

public:
    chooseFile();
    void loadFile();
    QFile getFile();
    void setFile(QFile file);
};

#endif // CHOOSEFILE_H
