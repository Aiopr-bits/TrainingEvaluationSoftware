#ifndef MEDIADROPWIDGET_H
#define MEDIADROPWIDGET_H

#include <QWidget>
#include <QMediaPlayer>
#include <QVideoWidget>
#include <QDragEnterEvent>
#include <QDropEvent>
#include <QMimeData>
#include <QLabel>
#include <QFileInfo>
#include <QVBoxLayout>

class MediaDropWidget : public QWidget {
    Q_OBJECT

public:
    explicit MediaDropWidget(QWidget* parent = nullptr);

protected:
    void dragEnterEvent(QDragEnterEvent* event) override;
    void dropEvent(QDropEvent* event) override;

private:
    void playVideo(const QString& filePath);
    void showImage(const QString& filePath);
    void playAudio(const QString& filePath);

    QMediaPlayer* videoPlayer;
    QMediaPlayer* audioPlayer;
    QVideoWidget* videoWidget;
    QLabel* imageLabel;
};

#endif // MEDIADROPWIDGET_H
