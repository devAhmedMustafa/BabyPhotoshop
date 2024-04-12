#include <QApplication>
#include "MainWidgets/Label.h"
#include "MainWidgets/Window.h"
#include "MainWidgets/ImageLoader.h"
#include "MainWidgets/Button.h"
#include "MainWidgets/SubLabel.h"

using namespace std;


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    Window window = Window(1440, 900);

    Label label = Label("Hello", window);
    Label label2 = Label("Grayscale", window);

    label2.move(100, 100);
    Button loadImage = Button("Load Image", window);
    ImageLoader il = ImageLoader(&loadImage);

    SubLabel sub = SubLabel("Hello", window);
    sub.move(200, 200);

    window.show();

    return app.exec();
}
