#include "Window.h"

Window::Window(int x, int y) : QWidget(nullptr) {
	setFixedSize(x, y);
	setWindowTitle(programName);
	
	background.setPixmap(backImage);
	// Set the label to cover the entire widget
	background.setGeometry(0, 0, width(), height());
}