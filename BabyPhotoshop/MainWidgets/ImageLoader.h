#pragma once
#include <QWidget>
#include <QFileDialog>
#include <QPixmap>
#include <QDebug>
#include "Button.h"
#include "ImageHolder.h"

class ImageLoader : public QWidget
{
private:


public:

    QString filePath;


    ImageLoader(Button* btn, ImageHolder* holder) {
        connect(btn, &QPushButton::clicked, this, [=]() {SelectAndLoadImage(holder); });
    }

    QString ImageLoaded() {
        return filePath;
    }
    void SelectAndLoadImage(ImageHolder* holder) {

        filePath = QFileDialog::getOpenFileName(nullptr, "Select Image", QDir::homePath(), "Images (*.png *.jpg *.jpeg *.bmp)");

        if (filePath.isEmpty()) {
            qDebug() << "No file selected.";
            return;
        }

        // Load the selected image file
        holder->SetImageMap(filePath);

    }

};

