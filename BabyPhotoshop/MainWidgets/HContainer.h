#pragma once

#include <QWidget>
#include <QHBoxLayout>

class HContainer : public QWidget
{	
public:
	
	QHBoxLayout* container;

	HContainer(QWidget& parent) {
		container = new QHBoxLayout(this);
	}

	void AddChild(QWidget& widget) {
		container->addWidget(&widget);
	}

};

