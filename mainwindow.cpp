#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->showMaximized();

    ////窗口风格设置
    //QPalette pal = this->palette();
    //pal.setColor(QPalette::Background, QColor(79, 79, 79));
    //this->setPalette(pal);
    //this->setStyleSheet("border: 2px solid rgb(79,79,79);");
    //ui->menubar->setStyleSheet("background-color:rgb(79,79,79);");  
    //ui->menubar->setStyleSheet("QMenuBar { color: white; }");
 
    // View 1
    QGridLayout* layout1 = new QGridLayout(ui->view1);
    playerView1LeftTop = new QMediaPlayer(this);
    playerView1RightTop = new QMediaPlayer(this);
    playerView1LeftBottom = new QMediaPlayer(this);
    playerView1RightBottom = new QMediaPlayer(this);
    videoWidget1LeftTop = new QVideoWidget(this);
    videoWidget1RightTop = new QVideoWidget(this);
    videoWidget1LeftBottom = new QVideoWidget(this);
    videoWidget1RightBottom = new QVideoWidget(this);
    playerView1LeftTop->setVideoOutput(videoWidget1LeftTop);
    playerView1RightTop->setVideoOutput(videoWidget1RightTop);
    playerView1LeftBottom->setVideoOutput(videoWidget1LeftBottom);
    playerView1RightBottom->setVideoOutput(videoWidget1RightBottom);
    layout1->addWidget(videoWidget1LeftTop, 0, 0);
    layout1->addWidget(videoWidget1RightTop, 0, 1);
    layout1->addWidget(videoWidget1LeftBottom, 1, 0);
    layout1->addWidget(videoWidget1RightBottom, 1, 1);
    videoWidget1LeftTop->setStyleSheet("background-color:black;");
    videoWidget1RightTop->setStyleSheet("background-color:black;");
    videoWidget1LeftBottom->setStyleSheet("background-color:black;");
    videoWidget1RightBottom->setStyleSheet("background-color:black;");


    //view 2
    QGridLayout* layout2 = new QGridLayout(ui->view2);
    playerView2LeftTop = new QMediaPlayer(this);
    playerView2RightTop = new QMediaPlayer(this);
    playerView2LeftBottom = new QMediaPlayer(this);
    playerView2RightBottom = new QMediaPlayer(this);
    videoWidget2LeftTop = new QVideoWidget(this);
    videoWidget2RightTop = new QVideoWidget(this);
    videoWidget2LeftBottom = new QVideoWidget(this);
    videoWidget2RightBottom = new QVideoWidget(this);
    playerView2LeftTop->setVideoOutput(videoWidget2LeftTop);
    playerView2RightTop->setVideoOutput(videoWidget2RightTop);
    playerView2LeftBottom->setVideoOutput(videoWidget2LeftBottom);
    playerView2RightBottom->setVideoOutput(videoWidget2RightBottom);
    layout2->addWidget(videoWidget2LeftTop, 0, 0);
    layout2->addWidget(videoWidget2RightTop, 0, 1);
    layout2->addWidget(videoWidget2LeftBottom, 1, 0);
    layout2->addWidget(videoWidget2RightBottom, 1, 1);
    videoWidget2LeftTop->setStyleSheet("background-color:black;");
    videoWidget2RightTop->setStyleSheet("background-color:black;");
    videoWidget2LeftBottom->setStyleSheet("background-color:black;");
    videoWidget2RightBottom->setStyleSheet("background-color:black;");

    //view 3
    QGridLayout* layout3 = new QGridLayout(ui->view3);
    playerView3LeftTop = new QMediaPlayer(this);
    playerView3RightTop = new QMediaPlayer(this);
    playerView3LeftBottom = new QMediaPlayer(this);
    playerView3RightBottom = new QMediaPlayer(this);
    videoWidget3LeftTop = new QVideoWidget(this);
    videoWidget3RightTop = new QVideoWidget(this);
    videoWidget3LeftBottom = new QVideoWidget(this);
    videoWidget3RightBottom = new QVideoWidget(this);
    playerView3LeftTop->setVideoOutput(videoWidget3LeftTop);
    playerView3RightTop->setVideoOutput(videoWidget3RightTop);
    playerView3LeftBottom->setVideoOutput(videoWidget3LeftBottom);
    playerView3RightBottom->setVideoOutput(videoWidget3RightBottom);
    layout3->addWidget(videoWidget3LeftTop, 0, 0);
    layout3->addWidget(videoWidget3RightTop, 0, 1);
    layout3->addWidget(videoWidget3LeftBottom, 1, 0);
    layout3->addWidget(videoWidget3RightBottom, 1, 1);
    videoWidget3LeftTop->setStyleSheet("background-color:black;");
    videoWidget3RightTop->setStyleSheet("background-color:black;");
    videoWidget3LeftBottom->setStyleSheet("background-color:black;");
    videoWidget3RightBottom->setStyleSheet("background-color:black;");




}

MainWindow::~MainWindow()
{
    delete ui;
}



