#pragma once
#include <QLabel>
#include <QFont>

class SubLabel : public QLabel
{
protected:
	QString defaultStyle = "\
		color: #616161;\
	";
	
	QFont defaultFont = QFont("Arial", 10);
	
public:

	SubLabel(QString name, QWidget& parent) : QLabel(name, &parent) {
		setText(name);
		setStyleSheet(defaultStyle);
		setFont(defaultFont);
	}
};

