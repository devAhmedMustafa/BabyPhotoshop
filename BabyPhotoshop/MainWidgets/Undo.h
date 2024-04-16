#pragma once

#include "Button.h"
#include "ImageHolder.h"
#include <QWidget>
#include "../Filters/Filter.h"

class Undo : public QWidget {

public:
	Button* undoBtn;
	ImageHolder* ih;
	std::string namer = "~temp";

	Undo(QWidget& parent, ImageHolder& ih) : QWidget(&parent){
		undoBtn = new Button("Undo", parent);

		this->ih = &ih;

		connect(undoBtn, &QPushButton::clicked, this, &Undo::UndoFilter);
	}

	void UndoFilter() {

		if (Filter::Counter() <= 'A')
			return;

		std::string newPath = "cache/" + namer + --Filter::Counter() + ".png";
		ih->SetImageMap(QString::fromStdString(newPath));
	}
};