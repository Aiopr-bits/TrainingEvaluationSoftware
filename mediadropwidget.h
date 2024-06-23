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
    //Q_OBJECT

public:
    explicit MediaDropWidget(QWidget* parent = nullptr);
    void dragEnterEvent(QDragEnterEvent* event) override;
    void dropEvent(QDropEvent* event) override;
    void resizeEvent(QResizeEvent* event) override;
    void playVideo(const QString& filePath);
    void showImage(const QString& filePath);
    void playAudio(const QString& filePath);
    void adjustImageLabelSize();

private:
    QMediaPlayer* videoPlayer;
    QMediaPlayer* audioPlayer;
    QVideoWidget* videoWidget;
    QLabel* imageLabel;
    QPixmap currentPixmap;
    QAudioOutput* videoAudioOutput;
    QAudioOutput* audioAudioOutput;   
};

#endif // MEDIADROPWIDGET_H
