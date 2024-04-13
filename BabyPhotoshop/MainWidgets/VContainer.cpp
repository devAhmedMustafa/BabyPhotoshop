#include "VContainer.h"

VContainer::VContainer(QWidget& parent) {
	container = new QVBoxLayout(this);
}

void VContainer::AddChild(QWidget& widget) {
	container->addWidget(&widget);
}