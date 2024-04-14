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
#include "MainWidgets/ColorPicker.h"
#include "MainWidgets/ScrollableContainers.h"
#include "MainWidgets/ImageSaver.h"
#include "MainWidgets/NumberBox.h"
#include "Filters/Filter.h"
#include <QScrollArea>

using namespace std;
using namespace WidgetStyling;


int main(int argc, char *argv[])
{

    cout << "Launched";

    const QString mainBlue = "#2962f3";
    const QString whiteBlue = "#d2daef";

    QApplication app(argc, argv);

    Window window = Window(1346,728);

#pragma region Construction

    HContainer mainLayout = HContainer(window);

    ScrollableContainer leftContainer = ScrollableContainer(&window);
    SetBackgroundColor(leftContainer, "white");
    SetBorder(leftContainer, "none");

    VContainer rightContainer = VContainer(window);
    QScrollArea* scrollArea = new QScrollArea(&window);

    scrollArea->setWidget(&leftContainer);
    scrollArea->setWidgetResizable(true);

    mainLayout.AddChild(*scrollArea);
    mainLayout.AddChild(rightContainer);

#pragma endregion

#pragma region RightContainer

    // Button Container
    HContainer imageOptionsContainer = HContainer(window);
    SetHAlignment(*imageOptionsContainer.container, Qt::AlignCenter);

    const int btnsWidth = 150, btnsHeight = 50;
    const int btnsBorderRadius = 25;

    ImageHolder* imageHolder = new ImageHolder(window);

#pragma region Load Image
    Button loadImage = Button("Load Image", window);
    SetSize(loadImage, btnsWidth, btnsHeight);
    SetBorder(loadImage, "3px solid #d2daef");
    SetBorderRadius(loadImage, btnsBorderRadius);
    SetFontWeight(loadImage, "bold");

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

    ImageSaver saver = ImageSaver(&saveImage, imageHolder);

#pragma endregion
    
    imageOptionsContainer.AddChild(loadImage);
    imageOptionsContainer.AddChild(saveImage);

    rightContainer.AddChild(imageOptionsContainer);
    rightContainer.AddChild(*imageHolder);

#pragma endregion

    SetVAlignment(*leftContainer.container, Qt::AlignTop);
    SetVAlignment(*rightContainer.container, Qt::AlignHCenter);

#pragma region Header

    Label header = Label("Baby Photoshop", window);
    header.ChangeColor(mainBlue);
    QFont headerFont = QFont("Trebuchet MS", 22);
    header.setFont(headerFont);

    leftContainer.AddChild(header);

#pragma endregion

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

    blf.connect(&radius, &Slider::valueChanged, &blf, [&blf](int value) {blf.SetRadius(value); });

    blur.AddChild(blurOptions);
    leftContainer.AddChild(blur);
#pragma endregion

#pragma region AddFrame

    VContainer frameOptions = VContainer(window);
    HContainer frameTypes = HContainer(window);

    frameOptions.AddChild(frameTypes);

    CheckBox basic = CheckBox("Basic", window);
    CheckBox lined = CheckBox("Lined", window);
    CheckBox fancy = CheckBox("Fancy", window);

    Slider thickness = Slider(window, 1, 500);
    frameOptions.AddChild(thickness);

    Button colorPick = Button("Choose Color", window);
    SetSize(colorPick, 110, colorPick.height());
    SetBackgroundColor(colorPick, whiteBlue);
    SetFontColor(colorPick, "#000000");

    ColorPicker picker = ColorPicker(window);

    frameTypes.AddChild(basic);
    frameTypes.AddChild(lined);
    frameTypes.AddChild(fancy);
    frameTypes.AddChild(colorPick);

    Frame frf = Frame(*imageHolder, picker);
    FilterSection frame = FilterSection(window, "Frame", frf);
    picker.connect(&colorPick, &QPushButton::clicked, &frf, &Frame::SetColor);

    frf.connect(&basic, &QCheckBox::stateChanged, &frf, &Frame::SetBasic);
    frf.connect(&lined, &QCheckBox::stateChanged, &frf, &Frame::SetLined);
    frf.connect(&fancy, &QCheckBox::stateChanged, &frf, &Frame::SetFancy);
    frf.connect(&thickness, &Slider::valueChanged, &frf, [&frf](int value) {frf.SetThickness(value); });

    frame.AddChild(frameOptions);
    leftContainer.AddChild(frame);

#pragma endregion

#pragma region Noise
    HContainer noiseOptions = HContainer(window);

    NumberBox power = NumberBox(window);
    power.setRange(1, 10);
    power.setSingleStep(0.1);

    noiseOptions.AddChild(power);

    Noise nsf = Noise(*imageHolder);
    FilterSection noise = FilterSection(window, "Noise", nsf);

    nsf.connect(&power, &NumberBox::valueChanged, &nsf, [&nsf](double value) {nsf.SetPower((float)value); });

    noise.AddChild(noiseOptions);
    leftContainer.AddChild(noise);
#pragma endregion

#pragma region Bloom
    HContainer bloomOptions = HContainer(window);

    NumberBox intensity =NumberBox(window);
    Slider threshold = Slider(window, 0, 255);

    SubLabel iLabel = SubLabel("Intensity", window);
    SubLabel tLabel = SubLabel("Threshold", window);

    intensity.setRange(0, 5);
    intensity.setSingleStep(0.1);

    bloomOptions.AddChild(iLabel);
    bloomOptions.AddChild(intensity);
    bloomOptions.AddChild(tLabel);
    bloomOptions.AddChild(threshold);

    Bloom blmf = Bloom(*imageHolder);
    FilterSection bloom = FilterSection(window, "Bloom", blmf);

    blmf.connect(&intensity, &NumberBox::valueChanged, &blmf, [&blmf](double value) {blmf.SetIntensity(value); });
    blmf.connect(&threshold, &Slider::valueChanged, &blmf, [&blmf](int value) {blmf.SetThreshold(value); });

    bloom.AddChild(bloomOptions);
    leftContainer.AddChild(bloom);
#pragma endregion

#pragma region Oil
    HContainer oilOptions = HContainer(window);

    Slider oilRadius = Slider(window, 0, 10);
    Slider intLevels = Slider(window, 0, 255);

    SubLabel rLabel = SubLabel("Radius", window);
    SubLabel lLabel = SubLabel("Intensity Levels", window);

    oilOptions.AddChild(rLabel);
    oilOptions.AddChild(oilRadius);
    oilOptions.AddChild(lLabel);
    oilOptions.AddChild(intLevels);

    Oil olf = Oil(*imageHolder);
    FilterSection oil = FilterSection(window, "Oiling", olf);

    olf.connect(&oilRadius, &Slider::valueChanged, &olf, [&olf](int value) {olf.SetRadius(value); });
    olf.connect(&intLevels, &Slider::valueChanged, &olf, [&olf](int value) {olf.SetLevels(value); });

    oil.AddChild(oilOptions);
    leftContainer.AddChild(oil);
#pragma endregion

#pragma region Sunlight
    Sunlight snf = Sunlight(*imageHolder);
    FilterSection sunlight = FilterSection(window, "Sunlight", snf);
    leftContainer.AddChild(sunlight);
#pragma endregion

#pragma region Detect Edges
    DetectEdges def = DetectEdges(*imageHolder);
    FilterSection detectEdges = FilterSection(window, "Detect Edges", def);
    leftContainer.AddChild(detectEdges);
#pragma endregion

#pragma region Infrared
    Infrared irf = Infrared(*imageHolder);
    FilterSection infrared = FilterSection(window, "Infrared", irf);
    leftContainer.AddChild(infrared);
#pragma endregion

#pragma region Purple
    Purple prf = Purple(*imageHolder);
    FilterSection purple = FilterSection(window, "Purple", prf);
    leftContainer.AddChild(purple);
#pragma endregion

#pragma region Brighten
    Brighten brf = Brighten(*imageHolder);
    FilterSection brighten = FilterSection(window, "Brighten", brf);
    leftContainer.AddChild(brighten);
#pragma endregion

#pragma region Darken
    Darken dkf = Darken(*imageHolder);
    FilterSection darken = FilterSection(window, "Darken", dkf);
    leftContainer.AddChild(darken);
#pragma endregion

#pragma region Gamma
    HContainer gammaOptions = HContainer(window);

    NumberBox gammaF = NumberBox(window);
    gammaF.setRange(0, 10);
    gammaF.setSingleStep(0.1);

    gammaOptions.AddChild(gammaF);

    Gamma gmf = Gamma(*imageHolder);
    FilterSection gamma = FilterSection(window, "Gamma", gmf);

    gmf.connect(&gammaF, &NumberBox::valueChanged, &gmf, [&gmf](double value) {gmf.SetGamma(value); });

    gamma.AddChild(gammaOptions);
    leftContainer.AddChild(gamma);
#pragma endregion

#pragma region Resize
    HContainer resizeOptions = HContainer(window);

    NumberBox neww = NumberBox(window);
    NumberBox newh = NumberBox(window);

    neww.setRange(1, 8000);
    newh.setRange(1, 8000);

    resizeOptions.AddChild(neww);
    resizeOptions.AddChild(newh);

    Resize rsf = Resize(*imageHolder);
    FilterSection resize = FilterSection(window, "Resize", rsf);

    rsf.connect(&neww, &NumberBox::valueChanged, &rsf, [&rsf](double value) {rsf.SetW(value); });
    rsf.connect(&newh, &NumberBox::valueChanged, &rsf, [&rsf](double value) {rsf.SetH(value); });

    resize.AddChild(resizeOptions);
    leftContainer.AddChild(resize);
#pragma endregion

#pragma region Crop
    HContainer cropOptions = HContainer(window);

    NumberBox x = NumberBox(window);
    x.setRange(1, 8000);
    x.setSingleStep(1);
    NumberBox y = NumberBox(window);
    y.setRange(1, 8000);
    y.setSingleStep(1);
    NumberBox w = NumberBox(window);
    w.setRange(1, 8000);
    w.setSingleStep(1);
    NumberBox h = NumberBox(window);
    h.setRange(1, 8000);
    h.setSingleStep(1);

    cropOptions.AddChild(x);
    cropOptions.AddChild(y);
    cropOptions.AddChild(w);
    cropOptions.AddChild(h);

    Crop crf = Crop(*imageHolder);
    FilterSection crop = FilterSection(window, "Crop", crf);

    crf.connect(&x, &NumberBox::valueChanged, &crf, [&crf](double value) { crf.SetX((int)value); });
    crf.connect(&y, &NumberBox::valueChanged, &crf, [&crf](double value) { crf.SetY((int)value); });
    crf.connect(&w, &NumberBox::valueChanged, &crf, [&crf](double value) { crf.SetW((int)value); });
    crf.connect(&h, &NumberBox::valueChanged, &crf, [&crf](double value) { crf.SetH((int)value); });

    crop.AddChild(cropOptions);
    leftContainer.AddChild(crop);
#pragma endregion

#pragma region Merge
    HContainer mergeOptions = HContainer(window);
    SetHAlignment(*mergeOptions.container, Qt::AlignCenter);

    ImageHolder* imageMergeHolder = new ImageHolder(window);
    imageMergeHolder->imageMap = imageMergeHolder->imageMap.scaled(100, 100, Qt::KeepAspectRatio);

    Button loadMergeImage = Button("Load Image", window);
    SetSize(loadMergeImage, btnsWidth, btnsHeight);
    SetBorder(loadMergeImage, "3px solid #d2daef");
    SetBorderRadius(loadMergeImage, btnsBorderRadius);
    SetFontWeight(loadMergeImage, "bold");

    Merge mgf = Merge(*imageHolder);
    FilterSection merge = FilterSection(window, "Merge", mgf);

    ImageLoader mergeLoader = ImageLoader(&loadMergeImage, imageMergeHolder, &mgf);

    mergeOptions.AddChild(loadMergeImage);
    mergeOptions.AddChild(*imageMergeHolder);
    merge.AddChild(mergeOptions);
    leftContainer.AddChild(merge);
#pragma endregion

#pragma region Skew
    HContainer skewOptions = HContainer(window);

    Slider angle = Slider(window, 1, 89);

    skewOptions.AddChild(angle);

    Skew skf = Skew(*imageHolder);
    FilterSection skew = FilterSection(window, "Skew", skf);

    skf.connect(&angle, &Slider::valueChanged, &skf, [&skf](int value) {skf.SetAngle(value); });

    skew.AddChild(skewOptions);
    leftContainer.AddChild(skew);
#pragma endregion


#pragma endregion

    window.setLayout(mainLayout.container);

    window.show();

    return app.exec();
}
