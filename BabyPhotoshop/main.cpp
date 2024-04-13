#include <QApplication>
#include "MainWidgets/Label.h"
#include "MainWidgets/Window.h"
#include "MainWidgets/ImageLoader.h"
#include "MainWidgets/Button.h"
#include "MainWidgets/SubLabel.h"
#include "MainWidgets/VContainer.h"
#include "MainWidgets/HContainer.h"
#include "Utilities/WidgetsStyling.h"

using namespace std;
using namespace WidgetStyling;


int main(int argc, char *argv[])
{

    const QString mainBlue = "#2962f3";

    QApplication app(argc, argv);

    Window window = Window(1440, 900);

    // Main Container

    HContainer mainLayout = HContainer(window);
    
    // Side Containers

    VContainer leftContainer = VContainer(window);
    VContainer rightContainer = VContainer(window);

    mainLayout.AddChild(leftContainer);
    mainLayout.AddChild(rightContainer);

    SetVAlignment(*leftContainer.container, Qt::AlignTop);

    Label header = Label("Baby Photoshop", window);
    header.ChangeColor(mainBlue);

    leftContainer.AddChild(header);

    // End Header

    // Grayscale

    HContainer grayScale = HContainer(window);
    SetHAlignment(*grayScale.container, Qt::AlignHCenter);
    SetHAlignment(*grayScale.container, Qt::AlignLeft);
    SetBackgroundColor(grayScale, "#f0f0f0");

    Label grayScaleLabel = Label("Grayscale", window);
    grayScale.AddChild(grayScaleLabel);

    leftContainer.AddChild(grayScale);

    // Invert


    window.setLayout(mainLayout.container);

    window.show();

    return app.exec();
}
