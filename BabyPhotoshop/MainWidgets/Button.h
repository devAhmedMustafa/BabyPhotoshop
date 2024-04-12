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

	QFont defaultFont = QFont("Arial", 17);

	int defaultWidth = 80, defaultHeight = 30;

public:
	
	Button(QString title, QWidget& parent);
};

