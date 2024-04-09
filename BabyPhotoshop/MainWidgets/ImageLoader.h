#pragma once
#include <QWidget>
#include <QFileDialog>
#include <QPixmap>
#include <QDebug>
#include "Button.h"

class ImageLoader : public QWidget
{
private:

	QString filePath;

public:

	ImageLoader(Button*);
	void SelectAndLoadImage();

};

