#include "../headers/NewVideogameForm.h"
#include "../headers/Videogame.h"
#include <QPushButton>
#include <QHBoxLayout>
#include <QFormLayout>
#include <QValidator>


NewVideogameForm::NewVideogameForm(QWidget* parent): NewItemForm(parent){
    titleEdit = new QLineEdit();
    descriptionEdit = new QTextEdit();
    yearEdit = new QLineEdit();
    yearEdit->setValidator(new QIntValidator(0, 2500));
    publisherEdit = new QLineEdit();
    genreEdit = new QLineEdit();
    developerEdit = new QLineEdit();

    imageEdit = new QLineEdit();
    QPushButton* browseBtn = new QPushButton("Browse...");
    imagePreview = new QLabel();
    imagePreview->setFixedSize(150, 150);
    imagePreview->setFrameShape(QFrame::Box);
    imagePreview->setAlignment(Qt::AlignCenter);

    connect(browseBtn, &QPushButton::clicked, this, &NewVideogameForm::onBrowse);

    QHBoxLayout* imageLayout = new QHBoxLayout();
    imageLayout->addWidget(imageEdit);
    imageLayout->addWidget(browseBtn);

    QFormLayout* formLayout = new QFormLayout();
    formLayout->addRow("Title:", titleEdit);
    formLayout->addRow("Description:", descriptionEdit);
    formLayout->addRow("Year:", yearEdit);
    formLayout->addRow("Publisher:", publisherEdit);
    formLayout->addRow("Genre:", genreEdit);
    formLayout->addRow("Developer:", developerEdit);;
    formLayout->addRow("Image:", imageLayout);
    formLayout->addRow("Preview:", imagePreview);

    QVBoxLayout* mainLayout = new QVBoxLayout(this);
    mainLayout->addLayout(formLayout);
    setLayout(mainLayout);

};

std::shared_ptr<AbstractItem> NewVideogameForm::createItem() const {
    if(yearEdit->text()=="")yearEdit->setText("0");
    return std::make_shared<Videogame>(
        titleEdit->text().toStdString(),
        descriptionEdit->toPlainText().toStdString(),
        static_cast<unsigned int>(std::stoi(yearEdit->text().toStdString())),
        imageEdit->text().toStdString(),
        publisherEdit->text().toStdString(),
        genreEdit->text().toStdString(),
        developerEdit->text().toStdString()
        );
}
