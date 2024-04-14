#pragma once

#include <QWidget>
#include <QDoubleSpinBox>

class NumberBox : public QDoubleSpinBox {

public:
	NumberBox(QWidget& parent) :QDoubleSpinBox(&parent) {

	}

};