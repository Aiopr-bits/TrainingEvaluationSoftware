#include "mediadropwidget.h"

MediaDropWidget::MediaDropWidget(QWidget* parent)
    : QWidget(parent),
    videoPlayer(new QMediaPlayer(this)),
    audioPlayer(new QMediaPlayer(this)),
    videoWidget(new QVideoWidget(this)),
    imageLabel(new QLabel(this))
{
    setAcceptDrops(true);

    QVBoxLayout* layout = new QVBoxLayout(this);
    videoWidget->setVisible(false);
    imageLabel->setVisible(false);
    imageLabel->setAlignment(Qt::AlignCenter);

    layout->addWidget(videoWidget);
    layout->addWidget(imageLabel);

    videoPlayer->setVideoOutput(videoWidget);

    setLayout(layout);

    // 设置背景颜色为黑色
    QPalette palette = this->palette();
    palette.setColor(QPalette::Window, Qt::black);
    this->setAutoFillBackground(true);
    this->setPalette(palette);
    videoWidget->setStyleSheet("background-color: black;");
    imageLabel->setStyleSheet("background-color: black; color: white;");
}

void MediaDropWidget::dragEnterEvent(QDragEnterEvent* event) {
    if (event->mimeData()->hasUrls()) {
        event->acceptProposedAction();
    }
}

void MediaDropWidget::dropEvent(QDropEvent* event) {
    const QMimeData* mimeData = event->mimeData();
    if (mimeData->hasUrls()) {
        QList<QUrl> urlList = mimeData->urls();
        QString filePath = urlList.at(0).toLocalFile();
        QFileInfo fileInfo(filePath);
        QString extension = fileInfo.suffix().toLower();

        if (extension == "mp4" || extension == "avi" || extension == "mkv") {
            playVideo(filePath);
        }
        else if (extension == "jpg" || extension == "jpeg" || extension == "png" || extension == "bmp") {
            showImage(filePath);
        }
        else if (extension == "mp3" || extension == "wav" || extension == "aac") {
            playAudio(filePath);
        }
        else {
            // Handle unsupported file types
        }
    }
}

void MediaDropWidget::playVideo(const QString& filePath) {
    videoWidget->setVisible(true);
    imageLabel->setVisible(false);
    videoPlayer->setMedia(QUrl::fromLocalFile(filePath));
    videoPlayer->play();
}

void MediaDropWidget::showImage(const QString& filePath) {
    videoWidget->setVisible(false);
    imageLabel->setVisible(true);
    QPixmap pixmap(filePath);
    imageLabel->setPixmap(pixmap.scaled(imageLabel->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
}

void MediaDropWidget::playAudio(const QString& filePath) {
    videoWidget->setVisible(false);
    imageLabel->setVisible(true);
    imageLabel->setText("Playing audio: " + filePath);
    audioPlayer->setMedia(QUrl::fromLocalFile(filePath));
    audioPlayer->play();
}
