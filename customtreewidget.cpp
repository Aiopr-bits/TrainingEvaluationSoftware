#include "customtreewidget.h"
#include <QMimeData>
#include <QUrl>
#include <QFileInfo>
#include <iostream>
#include "projectdatamanager.h"
#include <QDir>
#include <QDirIterator>

CustomTreeWidget::CustomTreeWidget(QWidget* parent) : QTreeWidget(parent) {
	setDragEnabled(true);
}

void CustomTreeWidget::startDrag(Qt::DropActions supportedActions) {
	QTreeWidgetItem* item = currentItem();
	if (item && item->flags() & Qt::ItemIsDragEnabled) {
		QString itemName = item->text(0);

		QString projectPath = QString::fromStdString(ProjectDataManager::getProject(ProjectDataManager::projectCurrentIndex).projectPath);
		QDirIterator dirIt(projectPath, QStringList() << itemName, QDir::Files, QDirIterator::Subdirectories);
		QString filePath;
		if (dirIt.hasNext()) {
			filePath = dirIt.next();
		}

		if (!filePath.isEmpty()) {
			QFileInfo fileInfo(filePath);
			QString absoluteFilePath = fileInfo.absoluteFilePath();
			//std::cout << "文件的绝对路径: " << absoluteFilePath.toStdString() << std::endl;
			QMimeData* mimeData = new QMimeData;
			QList<QUrl> urls;
			urls.append(QUrl::fromLocalFile(absoluteFilePath));
			mimeData->setUrls(urls);

			QDrag* drag = new QDrag(this);
			drag->setMimeData(mimeData);
			drag->exec(supportedActions);
		}
		else {
			std::cout << "在项目目录中未找到文件: " << itemName.toStdString() << std::endl;
		}

		//QMimeData* mimeData = new QMimeData;
		//QList<QUrl> urls;
		//urls.append(QUrl::fromLocalFile(item->data(0, Qt::UserRole).toString()));  // Use stored full path
		////std::cout<< urls.at(0).toLocalFile().toStdString() << std::endl;
		//mimeData->setUrls(urls);

		//QDrag* drag = new QDrag(this);
		//drag->setMimeData(mimeData);
		//drag->exec(supportedActions);
	}
}
