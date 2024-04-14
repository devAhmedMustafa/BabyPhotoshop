#include <QWidget>
#include <QLabel>
#include <QLinearGradient>
#include <QPointF>
#include <Qt>
#include <QRect>
#include <QFont>
#include <QPainter>
#include <QPaintEvent>
#include <QFontMetrics>
#include <QPainterPath>
#include <QPalette>

class Label : public QLabel
{
protected:
	QString defaultStyle = "\
		color: black;\
		font-weight: bold;\
	";

	QFont defaultFont = QFont("Arial", 16);

public:

	Label(QString name, QWidget& parent) : QLabel(name, &parent) {
		setText(name);
		setStyleSheet(defaultStyle);
		setFont(defaultFont);
	}

	void ChangeColor(QString color) {
		setStyleSheet(defaultStyle + "color:" + color + ";");
	}
};

