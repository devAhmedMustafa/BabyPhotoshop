#pragma once

#include <QWidget>
#include <QHBoxLayout>

class HContainer : public QWidget
{

private:
	
public:
	
	QHBoxLayout* container;

	HContainer(QWidget& );
	void AddChild(QWidget& );

};

