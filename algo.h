#ifndef ALGO_H
#define ALGO_H

#include "chooseimage.h"//;
#include "choosefile.h"//;

class algo
{
private:
   QImage imageOutput;
   QString messageAfterAnalyse;
   QFile fileOutput;
public:
   void encode(QImage image, QFile file);
   void decode(QImage image);
   void analyse(QImage image);
   QImage getImageOutput();
   QFile getFileOutput();
   QString getMessage();
   algo();

};

#endif // ALGO_H
