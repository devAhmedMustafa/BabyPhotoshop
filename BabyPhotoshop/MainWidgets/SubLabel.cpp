#include "SubLabel.h"

SubLabel::SubLabel(QString name, QWidget& parent) : QLabel(name, &parent) {
	setText(name);
	setStyleSheet(defaultStyle);
	setFont(defaultFont);
}