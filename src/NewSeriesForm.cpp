#include "../headers/NewSeriesForm.h"
#include "../headers/Series.h"
#include <QPushButton>
#include <QHBoxLayout>
#include <QFormLayout>
#include <QValidator>


NewSeriesForm::NewSeriesForm(QWidget* parent): NewItemForm(parent){
    titleEdit = new QLineEdit();
    descriptionEdit = new QTextEdit();
    yearEdit = new QLineEdit();
    yearEdit->setValidator(new QIntValidator(0, 2500));
    publisherEdit = new QLineEdit();
    genreEdit = new QLineEdit();
    castEdit = new QLineEdit();
    directorEdit = new QLineEdit();
    seasonsEdit = new QLineEdit();
    episodesEdit = new QLineEdit();

    imageEdit = new QLineEdit();
    QPushButton* browseBtn = new QPushButton("Browse...");
    imagePreview = new QLabel();
    imagePreview->setFixedSize(150, 150);
    imagePreview->setFrameShape(QFrame::Box);
    imagePreview->setAlignment(Qt::AlignCenter);

    connect(browseBtn, &QPushButton::clicked, this, &NewSeriesForm::onBrowse);

    QHBoxLayout* imageLayout = new QHBoxLayout();
    imageLayout->addWidget(imageEdit);
    imageLayout->addWidget(browseBtn);

    QFormLayout* formLayout = new QFormLayout();
    formLayout->addRow("Title:", titleEdit);
    formLayout->addRow("Description:", descriptionEdit);
    formLayout->addRow("Year:", yearEdit);
    formLayout->addRow("Publisher:", publisherEdit);
    formLayout->addRow("Genre:", genreEdit);
    formLayout->addRow("Cast:", castEdit);
    formLayout->addRow("Director:", directorEdit);
    formLayout->addRow("Seasons:", seasonsEdit);
    formLayout->addRow("Episodes:", episodesEdit);
    formLayout->addRow("Image:", imageLayout);
    formLayout->addRow("Preview:", imagePreview);

    QVBoxLayout* mainLayout = new QVBoxLayout(this);
    mainLayout->addLayout(formLayout);
    setLayout(mainLayout);

};

std::shared_ptr<AbstractItem> NewSeriesForm::createItem() const {
    if(yearEdit->text()=="")yearEdit->setText("0");
    if(seasonsEdit->text()=="")seasonsEdit->setText("0");
    if(episodesEdit->text()=="")episodesEdit->setText("0");
    return std::make_shared<Series>(
        titleEdit->text().toStdString(),
        descriptionEdit->toPlainText().toStdString(),
        static_cast<unsigned int>(std::stoi(yearEdit->text().toStdString())),
        imageEdit->text().toStdString(),
        publisherEdit->text().toStdString(),
        genreEdit->text().toStdString(),
        castEdit->text().toStdString(),
        directorEdit->text().toStdString(),
        static_cast<unsigned int>(std::stoi(seasonsEdit->text().toStdString())),
        static_cast<unsigned int>(std::stoi(episodesEdit->text().toStdString()))
        );
}
