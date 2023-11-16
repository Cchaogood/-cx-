#include "mainwindow.h"
#include "Mycompiler.h"
#include <QApplication>
#include <QLatin1String>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}



//remain to do:: renew table    getsym()    break;      continue;
