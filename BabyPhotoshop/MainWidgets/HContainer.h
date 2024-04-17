#pragma once

#include <QWidget>
#include <QHBoxLayout>
#include "../Utilities/WidgetsStyling.h"

using namespace WidgetStyling;

class HContainer : public QWidget
{	
public:
	
	QHBoxLayout* container;

	HContainer(QWidget& parent) {
		container = new QHBoxLayout(this);
		SetBackgroundColor(*this, "rgba(228, 228, 228, 0)");

	}

	void AddChild(QWidget& widget) {
		container->addWidget(&widget);
	}

};

