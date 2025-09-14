#include "../headers/NewBookForm.h"
#include "../headers/Book.h"
#include <QPushButton>
#include <QHBoxLayout>
#include <QFormLayout>
#include <QValidator>


NewBookForm::NewBookForm(QWidget* parent): NewItemForm(parent){
    titleEdit = new QLineEdit();
    descriptionEdit = new QTextEdit();
    yearEdit = new QLineEdit();
    yearEdit->setValidator(new QIntValidator(0, 2500));
    authorEdit = new QLineEdit();
    sizeEdit = new QLineEdit();
    publisherEdit = new QLineEdit();
    genreEdit = new QLineEdit();
    editionEdit = new QLineEdit();

    imageEdit = new QLineEdit();
    QPushButton* browseBtn = new QPushButton("Browse...");
    imagePreview = new QLabel();
    imagePreview->setFixedSize(150, 150);
    imagePreview->setFrameShape(QFrame::Box);
    imagePreview->setAlignment(Qt::AlignCenter);

    connect(browseBtn, &QPushButton::clicked, this, &NewBookForm::onBrowse);

    QHBoxLayout* imageLayout = new QHBoxLayout();
    imageLayout->addWidget(imageEdit);
    imageLayout->addWidget(browseBtn);

    QFormLayout* formLayout = new QFormLayout();
    formLayout->addRow("Title:", titleEdit);
    formLayout->addRow("Description:", descriptionEdit);
    formLayout->addRow("Year:", yearEdit);
    formLayout->addRow("Author:", authorEdit);
    formLayout->addRow("Pages:", sizeEdit);
    formLayout->addRow("Publisher:", publisherEdit);
    formLayout->addRow("Genre:", genreEdit);
    formLayout->addRow("Edition:", editionEdit);
    formLayout->addRow("Image:", imageLayout);
    formLayout->addRow("Preview:", imagePreview);

    QVBoxLayout* mainLayout = new QVBoxLayout(this);
    mainLayout->addLayout(formLayout);
    setLayout(mainLayout);

};

std::shared_ptr<AbstractItem> NewBookForm::createItem() const {
    if(yearEdit->text()=="")yearEdit->setText("0");
    return std::make_shared<Book>(
        titleEdit->text().toStdString(),
        descriptionEdit->toPlainText().toStdString(),
        static_cast<unsigned int>(std::stoi(yearEdit->text().toStdString())),
        imageEdit->text().toStdString(),
        authorEdit->text().toStdString(),
        sizeEdit->text().toStdString(),
        publisherEdit->text().toStdString(),
        genreEdit->text().toStdString(),
        editionEdit->text().toStdString()
        );
}
