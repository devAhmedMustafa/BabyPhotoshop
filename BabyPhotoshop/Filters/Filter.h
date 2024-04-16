#pragma once

#include "../MainWidgets/ImageHolder.h"
#include "../Utilities/Utilities.h"
#include "../MainWidgets/ColorPicker.h"
#include "Filters.h"

class Filter : public QObject {

public:

	ImageHolder* ih;
	std::string namer;

	Filter(ImageHolder& ih) {
		namer = "~temp";
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

class Resize : public Filter {
public:
	
	int w = 0, h = 0;

	void SetW(int w) {
		this->w = w;
	}

	void SetH(int h) {
		this->h = h;
	}

	Resize(ImageHolder& ih) :Filter(ih){}

	void ApplyFilter() {
		Filters::Resize(ih->currentImage, w, h);
		SaveFilter();
	}
};

class Frame : public Filter {

public:

	ColorPicker* colorPicker;
	bool basic = false, lined = false, fancy = false;
	int thickness = 1;
	int color[3] = {255,255,255};

	void SetBasic() {
		basic = true;
	}

	void SetLined() {
		lined = true;
	}

	void SetFancy() {
		fancy = true;
	}

	void SetThickness(int t) {
		thickness = t;
	}

	void SetColor() {

		colorPicker->openColorDialog();

		QColor colorPicked = colorPicker->color;
		color[0] = colorPicked.red();
		color[1] = colorPicked.green();
		color[2] = colorPicked.blue();
	}

	Frame(ImageHolder& ih, ColorPicker& picker) : Filter(ih) {
		colorPicker = &picker;
	}
	void ApplyFilter() {
		if (basic)
			Filters::AddBasicFrame(ih->currentImage, thickness, color);
		else if (lined)
			Filters::AddLinedFrame(ih->currentImage, thickness, color, new int[3]{255,255,255});
		if (fancy)
			Filters::AddFancyFrame(ih->currentImage, thickness, color, new int[3]{255,255,255});

		SaveFilter();
	}

};

class Noise : public Filter {
public:

	int power = 1;

	void SetPower(float p) {
		power = p;
	}

	Noise(ImageHolder& ih):Filter(ih){}

	void ApplyFilter() {
		Filters::Noise(ih->currentImage, power);
		SaveFilter();
	}
};

class Bloom : public Filter {
public:

	double intensity = 1;
	int threshold = 0;

	void SetIntensity(double i) {
		intensity = i;
	}
	void SetThreshold(int t) {
		threshold = t;
	}

	Bloom(ImageHolder& ih):Filter(ih){}

	void ApplyFilter() {
		Filters::Bloom(ih->currentImage, intensity, threshold);
		SaveFilter();
	}
};

class Oil : public Filter {
public:
	
	int radius = 1;
	int intLevels = 1;

	void SetRadius(int r) {
		radius = r;
	}
	void SetLevels(int l) {
		intLevels = l;
	}

	Oil(ImageHolder& ih):Filter(ih){}

	void ApplyFilter() {
		Filters::Oil(ih->currentImage, radius, intLevels);
		SaveFilter();
	}
};

class Sunlight : public Filter {
public:
	Sunlight(ImageHolder& ih) :Filter(ih) {}

	void ApplyFilter() {
		Filters::sunlight_filter(ih->currentImage);
		SaveFilter();
	}
};

class DetectEdges : public Filter {
public:
	DetectEdges(ImageHolder& ih) :Filter(ih) {}

	void ApplyFilter() {
		Filters::detect_edge(ih->currentImage);
		SaveFilter();
	}
};

class Infrared : public Filter {
public:
	Infrared(ImageHolder& ih) :Filter(ih) {}

	void ApplyFilter() {
		Filters::infrared_filter(ih->currentImage);
		SaveFilter();
	}
};

class Purple : public Filter {
public:
	Purple(ImageHolder& ih) :Filter(ih) {}

	void ApplyFilter() {
		Filters::purple_filter(ih->currentImage);
		SaveFilter();
	}
};

class Brighten : public Filter {
public:
	Brighten(ImageHolder& ih) :Filter(ih) {}

	void ApplyFilter() {
		Filters::brighten_filter(ih->currentImage);
		SaveFilter();
	}
};

class Darken : public Filter {
public:
	Darken(ImageHolder& ih) :Filter(ih) {}

	void ApplyFilter() {
		Filters::darken_filter(ih->currentImage);
		SaveFilter();
	}
};

class Gamma : public Filter {
public:

	double gamma = 0;

	void SetGamma(double gamma) {
		this->gamma = gamma;
	}

	Gamma(ImageHolder& ih) :Filter(ih) {}

	void ApplyFilter() {
		Filters::GammaFilter(ih->currentImage, gamma);
		SaveFilter();
	}
};

class Crop : public Filter {
public:

	int x = 0, y = 0, w = 0, h = 0;

	void SetX(int x) {
		this->x = x;
	}
	void SetY(int y) {
		this->y = y;
	}
	void SetW(int w) {
		this->w = w;
	}
	void SetH(int h) {
		this->h = h;
	}

	Crop(ImageHolder& ih) :Filter(ih) {}

	void ApplyFilter() {
		Filters::cropImage(ih->currentImage, x, y, w, h);
		SaveFilter();
	}
};

class Merge : public Filter {
public:

	Image* image;

	bool resized = false;

	void SetModeResized() {
		resized = !resized;
	}

	void SetImage(Image* image) {
		this->image = image;
	}

	Merge(ImageHolder& ih) :Filter(ih) {}

	void ApplyFilter() {
		if (resized)
			Filters::merge_resize(ih->currentImage, *image);
		else
			Filters::merge_intersection(ih->currentImage, *image);

		SaveFilter();
	}
};

class Skew : public Filter {
public:

	float angle;

	void SetAngle(float a) {
		angle = a;
	}

	Skew(ImageHolder& ih) :Filter(ih) {}

	void ApplyFilter() {
		Filters::Skew(ih->currentImage, angle);
		SaveFilter();
	}
};