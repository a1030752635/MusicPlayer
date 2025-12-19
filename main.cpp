#include "mueplayer.h"

#include <QApplication>
#include <QMessageBox>
#include <QSharedMemory>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QSharedMemory sharedMem("MuePlayer");
    if(sharedMem.attach())
    {
        QMessageBox::information(nullptr,"MuePlayer","MuePlayer已经在运行中");
        return 0;
    }
    sharedMem.create(1);
    MuePlayer w;
    w.show();
    return a.exec();
}
