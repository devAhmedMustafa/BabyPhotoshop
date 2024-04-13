#include "HContainer.h"

HContainer::HContainer(QWidget& parent) {
	container = new QHBoxLayout(this);
}

void HContainer::AddChild(QWidget& widget) {
	container->addWidget(&widget);
}