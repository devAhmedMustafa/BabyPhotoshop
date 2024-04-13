#pragma once

namespace WidgetStyling {
	void SetBackgroundColor(QWidget&, QString);
	void SetHAlignment(QHBoxLayout&, Qt::AlignmentFlag);
	void SetVAlignment(QVBoxLayout&, Qt::AlignmentFlag);

	void SetBackgroundColor(QWidget& widget, QString color) {
		widget.setStyleSheet(widget.styleSheet() + "background-color:" + color + ";");
	}

	void SetHAlignment(QHBoxLayout& layout, Qt::AlignmentFlag align) {
		layout.setAlignment(align);
	}

	void SetVAlignment(QVBoxLayout& layout, Qt::AlignmentFlag align) {
		layout.setAlignment(align);
	}
}