#include "CustomTreeWidget.h"
#include <QMouseEvent>
#include <QMimeData>
#include <QDrag>
#include <QApplication>

CustomTreeWidget::CustomTreeWidget(QWidget* parent) : QTreeWidget(parent)
{
    // 可以在这里进行额外的初始化
}

void CustomTreeWidget::mousePressEvent(QMouseEvent* event)
{
    if (event->button() == Qt::LeftButton) {
        startPos = event->pos();
    }
    // 调用基类的mousePressEvent以保持其他默认行为
    QTreeWidget::mousePressEvent(event);
}

void CustomTreeWidget::mouseMoveEvent(QMouseEvent* event)
{
    if (!(event->buttons() & Qt::LeftButton)) {
        return;
    }
    if ((event->pos() - startPos).manhattanLength() < QApplication::startDragDistance()) {
        return;
    }

    QTreeWidgetItem* item = itemAt(startPos);
    if (item && item->parent() && item->parent()->parent() && !item->parent()->parent()->parent()) {
        performDrag(item);
    }
}

void CustomTreeWidget::performDrag(QTreeWidgetItem* item)
{
    if (!item) {
        return;
    }

    QMimeData* mimeData = new QMimeData;
    // 这里设置mimeData的内容，例如使用item的文本
    mimeData->setText(item->text(0));

    QDrag* drag = new QDrag(this);
    drag->setMimeData(mimeData);
    drag->exec(Qt::CopyAction | Qt::MoveAction);
}
