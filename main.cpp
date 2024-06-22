#include "mainwindow.h"
#include <QApplication>
#include <iostream>
#include <Windows.h>

int main(int argc, char *argv[]){

    // 终端输出编码为UTF-8
    SetConsoleOutputCP(CP_UTF8);

    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
