#pragma once

#include <QWidget>
#include <QSlider>

class Slider : public QSlider
{
public:

	Slider(QWidget& parent, int min, int max):QSlider(Qt::Horizontal, &parent){
		setRange(min, max);
		setSingleStep(1);
	}

};

