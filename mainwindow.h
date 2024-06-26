#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMediaPlayer>
#include <QVideoWidget>
#include "mediadropwidget.h"
#include <QTreeWidgetItem>
#include "projectdatamanager.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

namespace fs = std::filesystem;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void updatePanel();

private slots:
    //工程action
    void on_actionNew_triggered();
    void on_actionOpen_triggered();
    void on_actionClose_triggered();
    void on_actionDelete_triggered();
    void on_actionSave_triggered();
    void on_actionSaveAs_triggered();
    void on_actionImport_triggered();
    void on_actionExport_triggered();
    void on_actionExit_triggered();
    
	//配置action
    void onProjectActionTriggered(bool checked);
    void onConfigActionTriggered(bool checked);
    void onDataActionTriggered(bool checked);
    void onEvaluationActionTriggered(bool checked);
    void onDisplayActionTriggered(bool checked);
    void onFourSplitActionTriggered();
    void onTwoSplitActionTriggered();
    void onOneSplitActionTriggered();
    void onTabWidgetCurrentChanged(int index);

    void on_treeWidgetProjectDirectory_currentItemChanged(QTreeWidgetItem *current, QTreeWidgetItem *previous);
    bool isProjectTreeFilesExist(const QString& base_path, const json& structure);
private:
    Ui::MainWindow *ui;
    ProjectDataManager * projectDataManager;

    MediaDropWidget* mediaDropWidgetView1LeftTop;
    MediaDropWidget* mediaDropWidgetView1RightTop;
    MediaDropWidget* mediaDropWidgetView1LeftBottom;
    MediaDropWidget* mediaDropWidgetView1RightBottom;
    MediaDropWidget* mediaDropWidgetView2LeftTop;
    MediaDropWidget* mediaDropWidgetView2RightTop;
    MediaDropWidget* mediaDropWidgetView2LeftBottom;
    MediaDropWidget* mediaDropWidgetView2RightBottom;
    MediaDropWidget* mediaDropWidgetView3LeftTop;
    MediaDropWidget* mediaDropWidgetView3RightTop;
    MediaDropWidget* mediaDropWidgetView3LeftBottom;
    MediaDropWidget* mediaDropWidgetView3RightBottom;

    QAction* projectAction;
    QAction* configAction;
    QAction* dataAction;
    QAction* evaluationAction;
    QAction* displayAction;
    QAction* fourSplitAction;
    QAction* twoSplitAction;
    QAction* oneSplitAction;
};
#endif // MAINWINDOW_H
