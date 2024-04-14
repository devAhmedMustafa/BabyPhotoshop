#pragma once
#include <QWidget>
#include <QFileDialog>
#include <QPixmap>
#include <QDebug>
#include "Button.h"
#include "ImageHolder.h"

class ImageSaver : public QWidget
{
private:


public:

    QString savedFilePath;

    ImageSaver(Button* btn, ImageHolder* holder) {
        connect(btn, &QPushButton::clicked, this, [=]() {SelectAndSaveImage(holder); });
    }

    void SelectAndSaveImage(ImageHolder* holder) {

        savedFilePath = QFileDialog::getSaveFileName(nullptr, "Save Image", QDir::homePath(), "Images (*.png *.jpg *.jpeg *.bmp)");

        if (savedFilePath.isEmpty()) {
            qDebug() << "No file selected.";
            return;
        }

        holder->currentImage.saveImage(savedFilePath.toStdString());

    }

};