#include "Label.h"

Label::Label(QString name, QWidget& parent) : QLabel(name, &parent) {
	setText(name);
	setStyleSheet(defaultStyle);
}

void Label::paintEvent(QPaintEvent* e) {
	QPainter painter(this);

	QRect rect = this->rect();
	QPainterPath path;
	path.addRoundedRect(rect, padding, padding);

	QLinearGradient linearGrad(QPointF(rect.topLeft()), QPointF(rect.bottomRight()));
	linearGrad.setColorAt(0, Qt::red);
	linearGrad.setColorAt(1, Qt::black);

	QRect rec(rect);

	painter.setClipPath(path);
	painter.fillRect(rec, linearGrad);
	painter.setClipping(false);
	painter.setPen(defaultFontColor);

	QFontMetrics metrics(font());
	QRect textRect = metrics.boundingRect(text());
	int x = rect.x() + (rect.width() - textRect.width()) / 2;
	int y = rect.y() + (rect.height() - textRect.height()) / 2 + metrics.ascent();
	painter.drawText(x, y, text());
}