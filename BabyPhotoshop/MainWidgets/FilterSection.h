#pragma once
#include "../Filters/Filter.h"

using namespace WidgetStyling;

class FilterSection : public VContainer
{

private:

    HContainer* filterHeader;
    Label* filterLabel;
    Button* applyBtn;

public:

    FilterSection(QWidget& parent, QString filterName, Filter& filter) : VContainer(parent) {

        filterHeader = new HContainer(parent);
        SetHAlignment(*filterHeader->container, Qt::AlignVCenter);

        SetBackgroundColor(*this, "rgba(228, 228, 228, 0.5)");
        SetBorderRadius(*this, 5);
        
        filterLabel = new Label(filterName, parent);
        filterHeader->AddChild(*filterLabel);

        AddChild(*filterHeader);

        applyBtn = new Button("Apply", parent);
        filterHeader->AddChild(*applyBtn);

        connect(applyBtn, &QPushButton::clicked, &filter, &Filter::ApplyFilter);

    }

};

