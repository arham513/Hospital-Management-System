#include "mainwindow.h"
//#include<iostream>
#include <QApplication>
#include<QLabel>
//using namespace std;

int main(int argc, char *argv[])
{
   // cout<<"Hello world"<<endl;
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
