#include <QApplication>
#include "MainWidgets/Label.h"
#include "MainWidgets/Window.h"
#include "MainWidgets/ImageLoader.h"
#include "MainWidgets/Button.h"
#include "MainWidgets/SubLabel.h"
#include "MainWidgets/VContainer.h"
#include "MainWidgets/HContainer.h"
#include "Utilities/WidgetsStyling.h"
#include "MainWidgets/FilterSection.h"
#include "MainWidgets/CheckBox.h"
#include "MainWidgets/Slider.h"
#include "Filters/Filter.h"

using namespace std;
using namespace WidgetStyling;


int main(int argc, char *argv[])
{

    cout << "Launched";

    const QString mainBlue = "#2962f3";

    QApplication app(argc, argv);

    Window window = Window(1440, 900);

#pragma region Construction

    HContainer mainLayout = HContainer(window);

    VContainer leftContainer = VContainer(window);
    VContainer rightContainer = VContainer(window);

    mainLayout.AddChild(leftContainer);
    mainLayout.AddChild(rightContainer);

#pragma endregion

#pragma region RightContainer

    // Button Container
    HContainer imageOptionsContainer = HContainer(window);
    SetHAlignment(*imageOptionsContainer.container, Qt::AlignCenter);

    const int btnsWidth = 150, btnsHeight = 50;
    const int btnsBorderRadius = 25;

#pragma region Load Image
    Button loadImage = Button("Load Image", window);
    SetSize(loadImage, btnsWidth, btnsHeight);
    SetBorder(loadImage, "3px solid #d2daef");
    SetBorderRadius(loadImage, btnsBorderRadius);
    SetFontWeight(loadImage, "bold");

    ImageHolder* imageHolder = new ImageHolder(window);
    ImageLoader loader = ImageLoader(&loadImage, imageHolder);
#pragma endregion

#pragma region Save Image

    Button saveImage = Button("Save Image", window);
    SetSize(saveImage, btnsWidth, btnsHeight);
    SetBackgroundColor(saveImage, "#d2daef");
    SetBorder(saveImage, "3px solid #2962f4");
    SetBorderRadius(saveImage, btnsBorderRadius);
    SetFontWeight(saveImage, "bold");
    SetFontColor(saveImage, "#4d4d4d");

#pragma endregion
    
    imageOptionsContainer.AddChild(loadImage);
    imageOptionsContainer.AddChild(saveImage);

    rightContainer.AddChild(imageOptionsContainer);
    rightContainer.AddChild(*imageHolder);

#pragma endregion

    SetVAlignment(*leftContainer.container, Qt::AlignTop);
    SetVAlignment(*rightContainer.container, Qt::AlignHCenter);

#pragma region LeftContainer

    Label header = Label("Baby Photoshop", window);
    header.ChangeColor(mainBlue);

    leftContainer.AddChild(header);

#pragma region Filters

#pragma region Grayscale
    Grayscale grf = Grayscale(*imageHolder);
    FilterSection grayScale = FilterSection(window, "Grayscale", grf);
    leftContainer.AddChild(grayScale);
#pragma endregion


#pragma region Invert
    InvertFilter ivf = InvertFilter(*imageHolder);
    FilterSection invert = FilterSection(window, "Invert", ivf);
    leftContainer.AddChild(invert);
#pragma endregion


#pragma region Black and White
    BlackAndWhite bwf = BlackAndWhite(*imageHolder);
    FilterSection blackNwhite = FilterSection(window, "Black and white", bwf);
    leftContainer.AddChild(blackNwhite);
#pragma endregion


#pragma region Flip

    HContainer flipOptions = HContainer(window);

    CheckBox verticalFlip = CheckBox("Vertical", window);
    CheckBox horizontalFlip = CheckBox("Horizontal", window);

    flipOptions.AddChild(horizontalFlip);
    flipOptions.AddChild(verticalFlip);

    Flip flf = Flip(*imageHolder);
    FilterSection flip = FilterSection(window, "Flip", flf);

    flf.connect(&verticalFlip, &QCheckBox::stateChanged, &flf, &Flip::SetVertical);
    flf.connect(&horizontalFlip, &QCheckBox::stateChanged, &flf, &Flip::SetHorizontal);

    flip.AddChild(flipOptions);
    leftContainer.AddChild(flip);

#pragma endregion

#pragma region Rotate
    HContainer rotateOptions = HContainer(window);

    CheckBox angle90 = CheckBox("90", window);
    CheckBox angle180 = CheckBox("180", window);
    CheckBox angle270 = CheckBox("270", window);

    rotateOptions.AddChild(angle90);
    rotateOptions.AddChild(angle180);
    rotateOptions.AddChild(angle270);

    Rotate rtf = Rotate(*imageHolder);
    FilterSection rotate = FilterSection(window, "Rotate", rtf);

    rtf.connect(&angle90, &QCheckBox::stateChanged, &rtf, &Rotate::Set90);
    rtf.connect(&angle180, &QCheckBox::stateChanged, &rtf, &Rotate::Set180);
    rtf.connect(&angle270, &QCheckBox::stateChanged, &rtf, &Rotate::Set270);


    rotate.AddChild(rotateOptions);
    leftContainer.AddChild(rotate);
#pragma endregion

#pragma region Blur
    HContainer blurOptions = HContainer(window);

    Slider radius = Slider(window, 1, 20);

    blurOptions.AddChild(radius);

    Blur blf = Blur(*imageHolder);
    FilterSection blur = FilterSection(window, "Blur", blf);

    blf.connect(&radius, SIGNAL(valueChanged(int)), &flf, SLOT(&Blur::SetRadius(int)));

    blur.AddChild(blurOptions);
    leftContainer.AddChild(blur);
#pragma endregion

#pragma region AddFrame

    HContainer frameOptions = HContainer(window);

    Slider radius = Slider(window, 1, 20);

    blurOptions.AddChild(radius);

    Blur blf = Blur(*imageHolder);
    FilterSection blur = FilterSection(window, "Blur", blf);

    blf.connect(&radius, SIGNAL(valueChanged(int)), &flf, SLOT(&Blur::SetRadius(int)));

    blur.AddChild(blurOptions);
    leftContainer.AddChild(blur);

#pragma endregion

#pragma endregion


    window.setLayout(mainLayout.container);

    window.show();

    return app.exec();
}
