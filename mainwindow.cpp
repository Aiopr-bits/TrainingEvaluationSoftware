#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QFileDialog>
#include <QDir>
#include <QMessageBox>
#include "mediadropwidget.h"

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



     //view窗口设置与排列
    QGridLayout* layout1 = new QGridLayout(ui->view1);
    mediaDropWidgetView1LeftTop = new MediaDropWidget(this);
    mediaDropWidgetView1RightTop = new MediaDropWidget(this);
    mediaDropWidgetView1LeftBottom = new MediaDropWidget(this);
    mediaDropWidgetView1RightBottom = new MediaDropWidget(this);
    layout1->addWidget(mediaDropWidgetView1LeftTop, 0, 0);
    layout1->addWidget(mediaDropWidgetView1RightTop, 0, 1);
    layout1->addWidget(mediaDropWidgetView1LeftBottom, 1, 0);
    layout1->addWidget(mediaDropWidgetView1RightBottom, 1, 1);

    QGridLayout* layout2 = new QGridLayout(ui->view2);
    mediaDropWidgetView2LeftTop = new MediaDropWidget(this);
    mediaDropWidgetView2RightTop = new MediaDropWidget(this);
    mediaDropWidgetView2LeftBottom = new MediaDropWidget(this);
    mediaDropWidgetView2RightBottom = new MediaDropWidget(this);
    layout2->addWidget(mediaDropWidgetView2LeftTop, 0, 0);
    layout2->addWidget(mediaDropWidgetView2RightTop, 0, 1);
    layout2->addWidget(mediaDropWidgetView2LeftBottom, 1, 0);
    layout2->addWidget(mediaDropWidgetView2RightBottom, 1, 1);

    QGridLayout* layout3 = new QGridLayout(ui->view3);
    mediaDropWidgetView3LeftTop = new MediaDropWidget(this);
    mediaDropWidgetView3RightTop = new MediaDropWidget(this);
    mediaDropWidgetView3LeftBottom = new MediaDropWidget(this);
    mediaDropWidgetView3RightBottom = new MediaDropWidget(this);
    layout3->addWidget(mediaDropWidgetView3LeftTop, 0, 0);
    layout3->addWidget(mediaDropWidgetView3RightTop, 0, 1);
    layout3->addWidget(mediaDropWidgetView3LeftBottom, 1, 0);
    layout3->addWidget(mediaDropWidgetView3RightBottom, 1, 1);



    //工作区配置
    QMenu* workSpaceMenu = new QMenu("WorkSpace", this);
    projectAction = new QAction(QString::fromLocal8Bit("工程项目"), this);
    projectAction->setCheckable(true);
    configAction = new QAction(QString::fromLocal8Bit("工程配置"), this);
    configAction->setCheckable(true);
    dataAction = new QAction(QString::fromLocal8Bit("训练数据"), this);
    dataAction->setCheckable(true);
    evaluationAction = new QAction(QString::fromLocal8Bit("训练评价"), this);
    evaluationAction->setCheckable(true);
    displayAction = new QAction(QString::fromLocal8Bit("数据展示"), this);
    displayAction->setCheckable(true);
    workSpaceMenu->addAction(projectAction);
    workSpaceMenu->addAction(configAction);
    workSpaceMenu->addAction(dataAction);
    workSpaceMenu->addAction(evaluationAction);
    workSpaceMenu->addAction(displayAction);
    ui->actionWorkSpace->setMenu(workSpaceMenu);
    projectAction->setChecked(true);
    configAction->setChecked(true);
    dataAction->setChecked(true);
    evaluationAction->setChecked(true);
    displayAction->setChecked(true);

    connect(projectAction, &QAction::triggered, this, &MainWindow::onProjectActionTriggered);
    connect(configAction, &QAction::triggered, this, &MainWindow::onConfigActionTriggered);
    connect(dataAction, &QAction::triggered, this, &MainWindow::onDataActionTriggered);
    connect(evaluationAction, &QAction::triggered, this, &MainWindow::onEvaluationActionTriggered);
    connect(displayAction, &QAction::triggered, this, &MainWindow::onDisplayActionTriggered);



    //视图配置
    QMenu* viewArrangementMenu = new QMenu("View Arrangement", this);
    QActionGroup* viewArrangementGroup = new QActionGroup(this);
    viewArrangementGroup->setExclusive(true);
    fourSplitAction = new QAction(QString::fromLocal8Bit("四分排列"), this);
    fourSplitAction->setCheckable(true);
    fourSplitAction->setChecked(true); 
    twoSplitAction = new QAction(QString::fromLocal8Bit("二分排列"), this);
    twoSplitAction->setCheckable(true);
    oneSplitAction = new QAction(QString::fromLocal8Bit("一分排列"), this);
    oneSplitAction->setCheckable(true);
    viewArrangementGroup->addAction(fourSplitAction);
    viewArrangementGroup->addAction(twoSplitAction);
    viewArrangementGroup->addAction(oneSplitAction);
    viewArrangementMenu->addAction(fourSplitAction);
    viewArrangementMenu->addAction(twoSplitAction);
    viewArrangementMenu->addAction(oneSplitAction);
    ui->actionViewArrangement->setMenu(viewArrangementMenu);

    connect(fourSplitAction, &QAction::triggered, this, &MainWindow::onFourSplitActionTriggered);
    connect(twoSplitAction, &QAction::triggered, this, &MainWindow::onTwoSplitActionTriggered);
    connect(oneSplitAction, &QAction::triggered, this, &MainWindow::onOneSplitActionTriggered);
    connect(ui->tabWidget, &QTabWidget::currentChanged, this, &MainWindow::onTabWidgetCurrentChanged);

    ////拖动项目播放视频
    //ui->treeWidgetProjectDirectory->setDragEnabled(true); // 允许拖动
    //ui->treeWidgetProjectDirectory->setDragDropMode(QAbstractItemView::DragOnly); // 设置为仅拖动模式

    //videoWidget1LeftTop->setAcceptDrops(true); // 允许放置


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionNew_triggered()
{

}

void MainWindow::on_actionOpen_triggered()
{
    //QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"), "", tr("Files (*.xljp)"));
    //if (fileName.isEmpty())
    //{
    //    return;
    //}
    QString fileName = QString::fromLocal8Bit("C:/Users/Aiopr/Desktop/工程/1213.xljp");

    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly))
    {
        qDebug() << "Open file failed!";
        return;
    }

    QString path = fileName.left(fileName.lastIndexOf("/"));
    QDir dir(path + QString::fromLocal8Bit("/训练数据"));
    if (!dir.exists()) {
        QMessageBox::warning(this, QString::fromLocal8Bit("警告"), QString::fromLocal8Bit("训练数据文件夹不存在！"));
        return;
    }

    // 在工程项目树中添加项目
    QFileInfo fileInfo(fileName);
    QString baseName = fileInfo.baseName(); 
    QTreeWidgetItem* projectItem = new QTreeWidgetItem(ui->treeWidgetProjectDirectory);
    projectItem->setText(0, baseName);
    ui->treeWidgetProjectDirectory->addTopLevelItem(projectItem);

   // 添加视频文件
    QStringList filters;
    filters << "*.mp4" << "*.avi" << "*.flv" << "*.mkv" << "*.rmvb" << "*.wmv";
    QDir videoDir(path + QString::fromLocal8Bit("/训练数据/视频"));
    QStringList videoFiles = videoDir.entryList(filters, QDir::Files | QDir::Readable, QDir::Name);
    if (videoFiles.size() > 0) {
		QTreeWidgetItem* videoItem = new QTreeWidgetItem(projectItem);
		videoItem->setText(0, QString::fromLocal8Bit("训练视频"));
		projectItem->addChild(videoItem);
        for (int i = 0; i < videoFiles.size(); i++) {
			QTreeWidgetItem* videoFileItem = new QTreeWidgetItem(videoItem);
			videoFileItem->setText(0, videoFiles[i]);
			videoItem->addChild(videoFileItem);
		}
	}

    //添加音频文件
    filters.clear();
    filters << "*.mp3" << "*.wav" << "*.flac" << "*.ape" << "*.wma" << "*.ogg";
    QDir audioDir(path + QString::fromLocal8Bit("/训练数据/音频"));
    QStringList audioFiles = audioDir.entryList(filters, QDir::Files | QDir::Readable, QDir::Name);
    if (audioFiles.size() > 0) {
        QTreeWidgetItem* audioItem = new QTreeWidgetItem(projectItem);
        audioItem->setText(0, QString::fromLocal8Bit("训练音频"));
        projectItem->addChild(audioItem);
        for (int i = 0; i < audioFiles.size(); i++) {
			QTreeWidgetItem* audioFileItem = new QTreeWidgetItem(audioItem);
			audioFileItem->setText(0, audioFiles[i]);
			audioItem->addChild(audioFileItem);
		}
    }

    //添加图片文件
    filters.clear();
    filters << "*.jpg" << "*.png" << "*.bmp" << "*.jpeg" << "*.gif" << "*.tiff";
    QDir imageDir(path + QString::fromLocal8Bit("/训练数据/图片"));
    QStringList imageFiles = imageDir.entryList(filters, QDir::Files | QDir::Readable, QDir::Name);
    if (imageFiles.size() > 0) {
		QTreeWidgetItem* imageItem = new QTreeWidgetItem(projectItem);
		imageItem->setText(0, QString::fromLocal8Bit("训练曲线"));
		projectItem->addChild(imageItem);
        for (int i = 0; i < imageFiles.size(); i++) {
            QTreeWidgetItem* imageFileItem = new QTreeWidgetItem(imageItem);
            imageFileItem->setText(0, imageFiles[i]);
            imageItem->addChild(imageFileItem);
        }
    }

   
}

void MainWindow::on_actionClose_triggered()
{

}

void MainWindow::onProjectActionTriggered(bool checked)
{
    if (checked) {
        ui->treeWidgetProjectDirectory->show();
    }
    else {
        ui->treeWidgetProjectDirectory->hide();
    }
}

void MainWindow::onConfigActionTriggered(bool checked)
{
    if (checked) {
		ui->treeWidgetProjectConfiguration->show();
	}
    else {
		ui->treeWidgetProjectConfiguration->hide();
	}
}

void MainWindow::onDataActionTriggered(bool checked)
{
    if (checked) {
		ui->treeWidgetTainData->show();
	}
    else {
		ui->treeWidgetTainData->hide();
	}
}

void MainWindow::onEvaluationActionTriggered(bool checked)
{
    if (checked) {
		ui->treeWidgetTrainEvaluation->show();
	}
    else {
		ui->treeWidgetTrainEvaluation->hide();
	}
}

void MainWindow::onDisplayActionTriggered(bool checked)
{
    if (checked) {
		ui->treeWidgetDataDisplay->show();
	}
    else {
		ui->treeWidgetDataDisplay->hide();
	}
}

void MainWindow::onFourSplitActionTriggered()
{
    int currentIndex = ui->tabWidget->currentIndex();
    if (currentIndex == 0) {
        mediaDropWidgetView1LeftTop->show();
        mediaDropWidgetView1RightTop->show();
        mediaDropWidgetView1LeftBottom->show();
        mediaDropWidgetView1RightBottom->show();
    }
    else if (currentIndex == 1) {
        mediaDropWidgetView2LeftTop->show();
        mediaDropWidgetView2RightTop->show();
        mediaDropWidgetView2LeftBottom->show();
        mediaDropWidgetView2RightBottom->show();
    }
    else if (currentIndex == 2) {
        mediaDropWidgetView3LeftTop->show();
        mediaDropWidgetView3RightTop->show();
        mediaDropWidgetView3LeftBottom->show();
        mediaDropWidgetView3RightBottom->show();
    }

}

void MainWindow::onTwoSplitActionTriggered()
{
    int currentIndex = ui->tabWidget->currentIndex();
    if (currentIndex == 0) {
        mediaDropWidgetView1LeftTop->show();
        mediaDropWidgetView1RightTop->show();
        mediaDropWidgetView1LeftBottom->hide();
        mediaDropWidgetView1RightBottom->hide();
    }
    else if (currentIndex == 1) {
        mediaDropWidgetView2LeftTop->show();
        mediaDropWidgetView2RightTop->show();
        mediaDropWidgetView2LeftBottom->hide();
        mediaDropWidgetView2RightBottom->hide();
    }
    else if (currentIndex == 2) {
        mediaDropWidgetView3LeftTop->show();
        mediaDropWidgetView3RightTop->show();
        mediaDropWidgetView3LeftBottom->hide();
        mediaDropWidgetView3RightBottom->hide();
    }
}

void MainWindow::onOneSplitActionTriggered()
{
    int currentIndex = ui->tabWidget->currentIndex();
    if (currentIndex == 0) {
        mediaDropWidgetView1LeftTop->show();
        mediaDropWidgetView1RightTop->hide();
        mediaDropWidgetView1LeftBottom->hide();
        mediaDropWidgetView1RightBottom->hide();
    }
    else if (currentIndex == 1) {
        mediaDropWidgetView2LeftTop->show();
        mediaDropWidgetView2RightTop->hide();
        mediaDropWidgetView2LeftBottom->hide();
        mediaDropWidgetView2RightBottom->hide();
    }
    else if (currentIndex == 2) {
        mediaDropWidgetView3LeftTop->show();
        mediaDropWidgetView3RightTop->hide();
        mediaDropWidgetView3LeftBottom->hide();
        mediaDropWidgetView3RightBottom->hide();
    }
}

void MainWindow::onTabWidgetCurrentChanged(int index)
{
    if (index == 0) {
        int count = 0;
        if (mediaDropWidgetView1LeftTop->isVisible()) {
			count++;
		}
        if (mediaDropWidgetView1RightTop->isVisible()) {
            count++;
        }
        if (mediaDropWidgetView1LeftBottom->isVisible()) {
			count++;
		}
        if (mediaDropWidgetView1RightBottom->isVisible()) {
            count++;
        }

        if (count == 4) {
            fourSplitAction->setChecked(true);
        }
        if(count == 2) {
			twoSplitAction->setChecked(true);
		}
        if (count == 1) {
			oneSplitAction->setChecked(true);
        }
	}
    else if (index == 1) {
		int count = 0;
        if (mediaDropWidgetView2LeftTop->isVisible()) {
			count++;
		}
        if (mediaDropWidgetView2RightTop->isVisible()) {
            count++;
        }
        if (mediaDropWidgetView2LeftBottom->isVisible()) {
            count++;
        }
        if (mediaDropWidgetView2RightBottom->isVisible()) {
			count++;
		}

        if (count == 4) {
			fourSplitAction->setChecked(true);
		}
        if (count == 2) {
			twoSplitAction->setChecked(true);
		}
        if (count == 1) {
			oneSplitAction->setChecked(true);
		}
	}
    else if (index == 2) {
		int count = 0;
        if (mediaDropWidgetView3LeftTop->isVisible()) {
			count++;
		}
        if (mediaDropWidgetView3RightTop->isVisible()) {
			count++;
		}
        if (mediaDropWidgetView3LeftBottom->isVisible()) {
            count++;
        }
        if (mediaDropWidgetView3RightBottom->isVisible()) {
            count++;
        }

        if (count == 4) {
			fourSplitAction->setChecked(true);
		}
        if (count == 2) {
			twoSplitAction->setChecked(true);
		}
        if (count == 1) {
			oneSplitAction->setChecked(true);
		}
	}
}


