#pragma once

#include <QWidget>
#include <QLabel>
#include "../Utilities/Image_Class.h"

class ImageHolder : public QWidget {

public:
	
	QPixmap imageMap;
	QLabel image = QLabel(this);
	Image currentImage;

	ImageHolder(QWidget& parent) : QWidget(&parent) {

	}

	void SetImageMap(QString path) {
		imageMap = QPixmap(path);
		currentImage.loadNewImage(path.toStdString());
		imageMap = imageMap.scaled(500, 500, Qt::KeepAspectRatio);
		image.setPixmap(imageMap);
		setFixedSize(imageMap.width(), imageMap.height() );
		image.setGeometry(0, 0, width(), height());
	}

};