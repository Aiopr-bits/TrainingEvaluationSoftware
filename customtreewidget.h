#ifndef CUSTOMTREEWIDGET_H
#define CUSTOMTREEWIDGET_H

#include <QTreeWidget>
#include <QDragEnterEvent>
#include <QDropEvent>
#include <QMimeData>
#include <QDrag>

class CustomTreeWidget : public QTreeWidget {
    Q_OBJECT

public:
    explicit CustomTreeWidget(QWidget* parent = nullptr);

signals:
    void fileDropped(const QString& filePath);

protected:
    void startDrag(Qt::DropActions supportedActions) override;
};

#endif // CUSTOMTREEWIDGET_H
