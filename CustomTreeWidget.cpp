#include "CustomTreeWidget.h"
#include <QMouseEvent>
#include <QMimeData>
#include <QDrag>
#include <QApplication>

CustomTreeWidget::CustomTreeWidget(QWidget* parent) : QTreeWidget(parent)
{
    // ������������ж���ĳ�ʼ��
}

void CustomTreeWidget::mousePressEvent(QMouseEvent* event)
{
    if (event->button() == Qt::LeftButton) {
        startPos = event->pos();
    }
    // ���û����mousePressEvent�Ա�������Ĭ����Ϊ
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
    // ��������mimeData�����ݣ�����ʹ��item���ı�
    mimeData->setText(item->text(0));

    QDrag* drag = new QDrag(this);
    drag->setMimeData(mimeData);
    drag->exec(Qt::CopyAction | Qt::MoveAction);
}
