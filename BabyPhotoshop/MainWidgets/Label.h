#include <QWidget>
#include <QLabel>
#include <QLinearGradient>
#include <QPointF>
#include <Qt>
#include <QRect>
#include <QPainter>
#include <QPaintEvent>
#include <QFontMetrics>
#include <QPainterPath>

using std::string;

class Label : public QLabel
{
private:
	QString defaultStyle = "\
		color: black;\
		border-radius: 10px;\
		padding: 10px;\
	";

	Qt::GlobalColor defaultFontColor = Qt::white;
	int padding = 5;

public:
	Label(QString name, QWidget& parent);
	void paintEvent(QPaintEvent* e);
};

