#pragma once
#include <QWidget>
#include <QFileDialog>
#include <QDialog>
#include <QPixmap>
#include <QDebug>
#include "Button.h"
#include "ImageHolder.h"
#include "../Filters/Filter.h"

class ImageLoader : public QWidget
{

private:

    Merge* merge = nullptr;

public:

    QString filePath;


    ImageLoader(Button* btn, ImageHolder* holder, Merge* merge = nullptr) {
        connect(btn, &QPushButton::clicked, this, [=]() {SelectAndLoadImage(holder); });
        this->merge = merge;
    }

    void SelectAndLoadImage(ImageHolder* holder) {

        filePath = QFileDialog::getOpenFileName(nullptr, "Select Image", QDir::homePath(), "Images (*.png *.jpg *.jpeg *.bmp)");

        if (filePath.isEmpty()) {
            qDebug() << "No file selected.";
            return;
        }


        holder->SetImageMap(filePath);

        std::string namer = "~tempA";

        if (merge != nullptr) {
            merge->SetImage(&holder->currentImage);
            namer = "~merge";
        }

        std::string newPath = "cache/" + namer + ".png";
        holder->currentImage.saveImage(newPath) ;

        holder->SetImageMap(QString::fromStdString(newPath));
        filePath = QString::fromStdString(newPath);

    }

};

