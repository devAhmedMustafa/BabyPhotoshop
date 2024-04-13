#include "Label.h"

Label::Label(QString name, QWidget& parent) : QLabel(name, &parent) {
	setText(name);
	setStyleSheet(defaultStyle);
	setFont(defaultFont);
}

void Label::ChangeColor(QString color) {
	setStyleSheet(defaultStyle+"color:" + color + ";");
}
