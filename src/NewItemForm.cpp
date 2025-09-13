#include "../headers/NewItemForm.h"
#include <QFileDialog>

void NewItemForm::onBrowse() {
    QString fileName = QFileDialog::getOpenFileName(this, "Select image",
                                                    QString(), "Images (*.png *.jpg *.jpeg *.bmp)");
    if (!fileName.isEmpty()) {
        imageEdit->setText(fileName);
        QPixmap pix(fileName);
        if (!pix.isNull()) {
            imagePreview->setPixmap(pix.scaled(imagePreview->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
        }
    }
}
