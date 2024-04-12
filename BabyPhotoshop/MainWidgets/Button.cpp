#include "Button.h"

Button::Button(QString title, QWidget& parent) : QPushButton(title, &parent) {
	setFont(defaultFont);
	setStyleSheet(defaultStyle);
	setFixedSize(defaultWidth, defaultHeight);
}