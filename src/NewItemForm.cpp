#include "../headers/NewItemForm.h"
#include <QFileDialog>

void NewItemForm::onBrowse() {
    QString fileName = QFileDialog::getOpenFileName(this, "Select image",
                                                    QString(), "Images (*.png *.jpg *.jpeg *.bmp)");
    if (!fileName.isEmpty()) {
        QDir currentDir = QDir::current();    //trasformo in path relativo per evitare di aver problemi con trasferimento libreria fra dispositivi
        QString relativePath = currentDir.relativeFilePath(fileName);
        imageEdit->setText(relativePath);
        QPixmap pix(fileName);
        if (!pix.isNull()) {
            imagePreview->setPixmap(pix.scaled(imagePreview->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
        }
    }
}
