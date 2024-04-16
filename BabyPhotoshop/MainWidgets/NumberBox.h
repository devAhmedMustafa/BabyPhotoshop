#pragma once

#include <QWidget>
#include <QDoubleSpinBox>

class NumberBox : public QDoubleSpinBox {

	const QString defaultStyles = "QDoubleSpinBox {"
                                "   border: 2px solid #3498db;"
                                "   border-radius: 5px;"
                                "   padding: 3px;"
                                "   background-color: #ecf0f1;"
                                "   selection-background-color: #2980b9;"
                                "}"
                                "QDoubleSpinBox::up-button, QDoubleSpinBox::down-button {"
                                "   width: 0px;"  
                                "   height: 0px;" 
                                "   border: none;"
                                "}";

	const int w = 80, h = 30;

public:

	NumberBox(QWidget& parent) :QDoubleSpinBox(&parent) {
		setStyleSheet(defaultStyles);
		setFixedSize(w, h);
	}

};