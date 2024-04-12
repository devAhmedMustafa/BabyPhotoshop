#pragma once
#include <QLabel>
#include <QFont>

class SubLabel : public QLabel
{
protected:
	QString defaultStyle = "\
		color: #616161;\
		font-size: 22px\
	";
	
	QFont defaultFont = QFont("Arial", 22);
	
public:
	SubLabel(QString name, QWidget& parent);
};

