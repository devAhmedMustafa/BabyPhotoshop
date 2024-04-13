#include "FilterSection.h"

using namespace WidgetStyling;

FilterSection::FilterSection(QWidget& parent) : VContainer(parent) {
    HContainer filterHeader = HContainer(parent);
    SetHAlignment(*filterHeader.container, Qt::AlignHCenter);
    SetHAlignment(*filterHeader.container, Qt::AlignLeft);
    SetBackgroundColor(*this, "#f0f0f0");

    Label grayScaleLabel = Label("Grayscale", parent);
    filterHeader.AddChild(grayScaleLabel);
}