#pragma once

#include <QWidget>
#include <QVBoxLayout>

class VContainer : public QWidget
{

public:

	QVBoxLayout* container;
	QString defaultStyles = "";

	VContainer(QWidget& parent) {
		container = new QVBoxLayout(this);
	}

	void AddChild(QWidget& widget) {
		container->addWidget(&widget);
	}

};

