#pragma once

#include <QWidget>
#include <QLabel>
#include "../Utilities/Image_Class.h"

class ImageHolder : public QWidget {

public:
	
	QPixmap imageMap;
	QLabel image = QLabel(this);
	Image currentImage;

	int scale;

	ImageHolder(QWidget& parent, int scale = 500) : QWidget(&parent) {
		this->scale = scale;
	}

	void SetImageMap(QString path) {
		imageMap = QPixmap(path);
		currentImage.loadNewImage(path.toStdString());
		imageMap = imageMap.scaled(scale, scale, Qt::KeepAspectRatio);
		image.setPixmap(imageMap);
		setFixedSize(imageMap.width(), imageMap.height() );
		image.setGeometry(0, 0, width(), height());
	}

};