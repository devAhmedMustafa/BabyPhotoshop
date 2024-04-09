#include "Window.h"

Window::Window(int x, int y) : QWidget(nullptr) {
	setFixedSize(x, y);
	setWindowTitle(programName);
	setStyleSheet(defaultStyle);
}