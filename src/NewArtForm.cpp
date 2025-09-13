#include "../headers/NewArtForm.h"
#include "../headers/Art.h"
#include <QPushButton>
#include <QHBoxLayout>
#include <QFormLayout>
#include <QValidator>
#include <QFileDialog>


NewArtForm::NewArtForm(QWidget* parent): NewItemForm(parent){
    titleEdit = new QLineEdit();
    descriptionEdit = new QTextEdit();
    yearEdit = new QLineEdit();
    yearEdit->setValidator(new QIntValidator(0, 2500));
    authorEdit = new QLineEdit();
    sizeEdit = new QLineEdit();
    styleEdit = new QLineEdit();

    imageEdit = new QLineEdit();
    QPushButton* browseBtn = new QPushButton("Browse...");
    imagePreview = new QLabel();
    imagePreview->setFixedSize(150, 150);
    imagePreview->setFrameShape(QFrame::Box);
    imagePreview->setAlignment(Qt::AlignCenter);

    connect(browseBtn, &QPushButton::clicked, this, &NewArtForm::onBrowse);

    QHBoxLayout* imageLayout = new QHBoxLayout();
    imageLayout->addWidget(imageEdit);
    imageLayout->addWidget(browseBtn);

    QFormLayout* formLayout = new QFormLayout();
    formLayout->addRow("Title:", titleEdit);
    formLayout->addRow("Description:", descriptionEdit);
    formLayout->addRow("Year:", yearEdit);
    formLayout->addRow("Author:", authorEdit);
    formLayout->addRow("Size:", sizeEdit);
    formLayout->addRow("Style:", styleEdit);
    formLayout->addRow("Image:", imageLayout);
    formLayout->addRow("Preview:", imagePreview);

    QVBoxLayout* mainLayout = new QVBoxLayout(this);
    mainLayout->addLayout(formLayout);
    setLayout(mainLayout);

};

std::shared_ptr<AbstractItem> NewArtForm::createItem() const {
    return std::make_shared<Art>(
        titleEdit->text().toStdString(),
        descriptionEdit->toPlainText().toStdString(),
        static_cast<unsigned int>(std::stoi(yearEdit->text().toStdString())),
        imageEdit->text().toStdString(),
        authorEdit->text().toStdString(),
        sizeEdit->text().toStdString(),
        styleEdit->text().toStdString()
        );
}

void NewArtForm::onBrowse() {
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
