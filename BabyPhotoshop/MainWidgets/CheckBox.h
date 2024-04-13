#pragma once
#include <QWidget>
#include <QCheckBox>

class CheckBox : public QCheckBox {
public:
	CheckBox(QString title, QWidget& parent) :QCheckBox(title, &parent){

	}
};