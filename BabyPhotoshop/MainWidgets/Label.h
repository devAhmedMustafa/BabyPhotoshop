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

using std::string;

class Label : public QLabel
{
protected:
	QString defaultStyle = "\
		color: black;\
		font-weight: bold;\
		font-size: 26px\
	";

	QFont defaultFont = QFont("Arial", 20);

public:
	Label(QString name, QWidget& parent);
};

