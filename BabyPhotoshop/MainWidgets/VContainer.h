#pragma once

#include <QWidget>
#include <QVBoxLayout>
#include "../Utilities/WidgetsStyling.h"

using namespace WidgetStyling;

class VContainer : public QWidget
{

public:

	QVBoxLayout* container;
	QString defaultStyles = "";

	VContainer(QWidget& parent) {
		container = new QVBoxLayout(this);
		SetBackgroundColor(*this, "rgba(228, 228, 228, 0)");
	}

	void AddChild(QWidget& widget) {
		container->addWidget(&widget);
	}

};

