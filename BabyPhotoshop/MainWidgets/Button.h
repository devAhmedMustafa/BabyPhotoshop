#pragma once
#include <QWidget>
#include <QPushButton>

class Button : public QPushButton
{
private:

	QString defaultStyle = "\
		background-color: #2962f4;\
		border-radius: 15px;\
		color: white;\
	";

	QFont defaultFont = QFont("Arial", 12);

	int defaultWidth = 80, defaultHeight = 30;

public:

	Button(QString title, QWidget& parent) : QPushButton(title, &parent) {
		setFont(defaultFont);
		setStyleSheet(defaultStyle);
		setFixedSize(defaultWidth, defaultHeight);
		setCursor(Qt::PointingHandCursor);
	}
};

