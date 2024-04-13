#pragma once

#include "../MainWidgets/ImageHolder.h"
#include "../Utilities/Utilities.h"
#include "Filters.h"

class Filter : public QObject {

public:

	ImageHolder* ih;
	std::string namer;

	Filter(ImageHolder& ih) {
		namer = "a";
		this->ih = &ih;
	}

	virtual void ApplyFilter() = 0;

	void SaveFilter() {
		std::string newPath = "cache/" + namer + ".png";
		ih->currentImage.saveImage(newPath);
		ih->SetImageMap(QString::fromStdString(newPath));
	}

};

class Grayscale : public Filter {
public:
	Grayscale(ImageHolder& ih):Filter(ih){}

	void ApplyFilter() {
		Filters::grayScale_filter(ih->currentImage);
		SaveFilter();
	}
};

class InvertFilter : public Filter {

public:

	InvertFilter(ImageHolder& ih):Filter(ih){}

	void ApplyFilter() {
		Filters::InvertFilter(ih->currentImage);
		SaveFilter();
	}
};

class BlackAndWhite : public Filter {

public:
	BlackAndWhite(ImageHolder& ih):Filter(ih){}

	void ApplyFilter() {
		Filters::Black_and_White(ih->currentImage);
		SaveFilter();
	}
};

class Flip : public Filter {
public:

	bool vertical = false, horizontal = false;

	Flip(ImageHolder& ih):Filter(ih){}

	void ApplyFilter() {
		if (vertical)
			Filters::verticalFlip(ih->currentImage);
		if (horizontal)
			Filters::horizontalFlip(ih->currentImage);

		SaveFilter();
	}

	void SetVertical() {
		vertical = !vertical;
	}
	void SetHorizontal() {
		horizontal = !horizontal;
	}
};

class Rotate : public Filter {
public:

	bool angle90 = false, angle180 = false, angle270 = false;

	Rotate(ImageHolder& ih):Filter(ih){}

	void Set90() {
		angle90 = !angle90;
	}
	void Set180() {
		angle180 = !angle180;
	}void Set270() {
		angle270 = !angle270;
	}

	void ApplyFilter() {
		if (angle90)
			Filters::Rotate(ih->currentImage, 90);
		else if (angle180)
			Filters::Rotate(ih->currentImage, 180);
		else if (angle270)
			Filters::Rotate(ih->currentImage, 270);

		SaveFilter();
	}
};

class Blur : public Filter {
public:
	Blur(ImageHolder& ih) :Filter(ih) {}
	int blurRadius = 1;

	void SetRadius(int r) {
		blurRadius = r;
	}

	void ApplyFilter() {
		Filters::BlurFilter(ih->currentImage, blurRadius);

		SaveFilter();
	}
};

class Frame : public Filter {

public:
	Frame(ImageHolder& ih) : Filter(ih) {}
	void ApplyFilter() {

	}

};