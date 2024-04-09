#include <QApplication>
#include "MainWidgets/Label.h"
#include "MainWidgets/Window.h"
#include "MainWidgets/ImageLoader.h"
#include "MainWidgets/Button.h"

using namespace std;


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    Window window = Window(1000, 800);

    Label label = Label("Hello", window);
    Label label2 = Label("Boom Action!", window);

    label2.move(100, 100);
    Button loadImage = Button("Load Image", window);
    ImageLoader il = ImageLoader(&loadImage);

    window.show();

    return app.exec();
}
