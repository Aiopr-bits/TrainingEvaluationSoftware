#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMediaPlayer>
#include <QVideoWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:


private:
    Ui::MainWindow *ui;

    // View 1
    QVideoWidget* videoWidget1LeftTop;
    QVideoWidget* videoWidget1RightTop;
    QVideoWidget* videoWidget1LeftBottom;
    QVideoWidget* videoWidget1RightBottom;
    QMediaPlayer *playerView1LeftTop;
    QMediaPlayer *playerView1RightTop;
    QMediaPlayer *playerView1LeftBottom;
    QMediaPlayer *playerView1RightBottom;

    // View 2
    QVideoWidget* videoWidget2LeftTop;
    QVideoWidget* videoWidget2RightTop;
    QVideoWidget* videoWidget2LeftBottom;
    QVideoWidget* videoWidget2RightBottom;
    QMediaPlayer *playerView2LeftTop;
    QMediaPlayer *playerView2RightTop;
    QMediaPlayer *playerView2LeftBottom;
    QMediaPlayer *playerView2RightBottom;

    // View 3
    QVideoWidget* videoWidget3LeftTop;
    QVideoWidget* videoWidget3RightTop;
    QVideoWidget* videoWidget3LeftBottom;
    QVideoWidget* videoWidget3RightBottom;
    QMediaPlayer *playerView3LeftTop;
    QMediaPlayer *playerView3RightTop;
    QMediaPlayer *playerView3LeftBottom;
    QMediaPlayer *playerView3RightBottom;

};
#endif // MAINWINDOW_H
