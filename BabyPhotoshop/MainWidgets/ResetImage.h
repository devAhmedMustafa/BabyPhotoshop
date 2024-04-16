#pragma once

#include <QWidget>
#include "Button.h"
#include "ImageHolder.h"
#include "ImageLoader.h"

class ResetImage : public QWidget{

public:
	Button* resetBtn;
	ImageHolder* ih;
	ImageLoader* il;

	ResetImage(QWidget& parent, ImageLoader& path, ImageHolder& ih) :QWidget(&parent){
		resetBtn = new Button("Reset", parent);
		il = &path;
		this->ih = &ih;

		connect(resetBtn, &QPushButton::clicked, this, &ResetImage::ResetToOriginal);
	}

	void ResetToOriginal() {
		ih->SetImageMap(il->filePath);
	}

};