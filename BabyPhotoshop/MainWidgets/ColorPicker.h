#pragma once

#include <QWidget>
#include <QColorDialog>


class ColorPicker : public QWidget {
public:


    QColor color;
    ColorPicker(QWidget& parent):QWidget(&parent){}

    void openColorDialog() {
        color = QColorDialog::getColor(Qt::white, this, "Select Color");

        if (color.isValid()) {
            qDebug() << "Selected color: " << color.name();
        }
    }
};