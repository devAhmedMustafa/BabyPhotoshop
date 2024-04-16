#pragma once

#include <QWidget>
#include <QSlider>

class Slider : public QSlider
{

	const QString defaultStyle = "QSlider::groove:horizontal {"
        "   border: 1px solid #5190ff;"
        "   background: #5190ff;"
        "   height: 3px;"
        "   margin: 0px;"
        "}"
        "QSlider::handle:horizontal {"
        "   background: #2962f4;"
        "   border: 1px solid #2962f4;"
        "   width: 12px;"
        "   margin: -3px 0px;"
        "   border-radius: 4px;"
        "}";

public:

	Slider(QWidget& parent, int min, int max):QSlider(Qt::Horizontal, &parent){
		setRange(min, max);
		setSingleStep(1);
        setStyleSheet(defaultStyle);
	}

};

