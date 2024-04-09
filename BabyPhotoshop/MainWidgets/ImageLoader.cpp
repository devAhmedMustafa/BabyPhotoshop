#include "ImageLoader.h"

ImageLoader::ImageLoader(Button* btn) {
    connect(btn, &QPushButton::clicked, this, &ImageLoader::SelectAndLoadImage);
}

void ImageLoader::SelectAndLoadImage() {

    filePath = QFileDialog::getOpenFileName(nullptr, "Select Image", QDir::homePath(), "Images (*.png *.jpg *.jpeg *.bmp)");

    if (filePath.isEmpty()) {
        qDebug() << "No file selected.";
        return;
    }

    // Load the selected image file
    QPixmap pixmap(filePath);

    if (pixmap.isNull()) {
        qDebug() << "Failed to load image";
        return;
    }
}