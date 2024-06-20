#include "customtreewidget.h"
#include <QMimeData>
#include <QUrl>
#include <QFileInfo>

CustomTreeWidget::CustomTreeWidget(QWidget* parent) : QTreeWidget(parent) {
    setDragEnabled(true);
}

void CustomTreeWidget::startDrag(Qt::DropActions supportedActions) {
    QTreeWidgetItem* item = currentItem();
    if (item && item->flags() & Qt::ItemIsDragEnabled) {
        QMimeData* mimeData = new QMimeData;
        QList<QUrl> urls;
        urls.append(QUrl::fromLocalFile(item->data(0, Qt::UserRole).toString()));  // Use stored full path
        mimeData->setUrls(urls);

        QDrag* drag = new QDrag(this);
        drag->setMimeData(mimeData);
        drag->exec(supportedActions);
    }
}
