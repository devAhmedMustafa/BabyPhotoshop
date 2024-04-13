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
        SetBackgroundColor(*this, "#f0f0f0");

        filterLabel = new Label(filterName, parent);
        filterHeader->AddChild(*filterLabel);

        AddChild(*filterHeader);
        //for (int i = 0; i < options.size(); i++) {
        //    AddChild(options[i]);
        //}

        applyBtn = new Button("Apply", parent);
        filterHeader->AddChild(*applyBtn);

        connect(applyBtn, &QPushButton::clicked, &filter, &Filter::ApplyFilter);

    }

};

