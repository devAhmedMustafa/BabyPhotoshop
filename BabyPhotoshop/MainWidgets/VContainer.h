#pragma once

#include <QWidget>
#include <QVBoxLayout>

class VContainer : public QWidget
{

public:

	QVBoxLayout* container;
	QString defaultStyles = "";

	VContainer(QWidget&);
	void AddChild(QWidget&);

};

