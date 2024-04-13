#pragma once

namespace WidgetStyling {
	void AddProperty(QWidget&, QString, QString);
	void SetBackgroundColor(QWidget&, QString);
	void SetHAlignment(QHBoxLayout&, Qt::AlignmentFlag);
	void SetVAlignment(QVBoxLayout&, Qt::AlignmentFlag);
	void SetSize(QWidget&, int, int);
	void SetBorder(QWidget&, QString);
	void SetBorderRadius(QWidget&, int);
	void SetFontWeight(QWidget&, QString);
	void SetFontColor(QWidget&, QString);

	void AddProperty(QWidget& widget, QString prop, QString value) {
		widget.setStyleSheet(widget.styleSheet() + prop + ": " + value + ";");
	}

	void SetBackgroundColor(QWidget& widget, QString color) {
		widget.setStyleSheet(widget.styleSheet() + "background-color:" + color + ";");
	}

	void SetHAlignment(QHBoxLayout& layout, Qt::AlignmentFlag align) {
		layout.setAlignment(align);
	}

	void SetVAlignment(QVBoxLayout& layout, Qt::AlignmentFlag align) {
		layout.setAlignment(align);
	}
	
	void SetSize(QWidget& widget, int w, int h) {
		widget.setFixedSize(w, h);
	}

	void SetBorder(QWidget& widget, QString border) {
		widget.setStyleSheet(widget.styleSheet() + "border: " + border + ";");
	}

	void SetBorderRadius(QWidget& widget, int radius) {
		widget.setStyleSheet(widget.styleSheet() + "border-radius: " + QString::number(radius) +"px"+ ";");
	}

	void SetFontWeight(QWidget& widget, QString weight) {
		widget.setStyleSheet(widget.styleSheet() + "font-weight: " + weight + ";");
	}

	void SetFontColor(QWidget& widget, QString color) {
		AddProperty(widget, "color", color);
	}

}