#include "../headers/ItemInfoVisitor.h"
#include "../headers/Art.h"
#include "../headers/Book.h"
#include "../headers/Movie.h"
#include "../headers/Series.h"
#include "../headers/Videogame.h"
#include "../headers/ItemEditVisitor.h"
#include <QLineEdit>
#include <QValidator>
#include <QShortcut>
#include <QTextEdit>
#include <QPushButton>
#include <QMessageBox>
#include <QFileDialog>

ItemInfoVisitor::ItemInfoVisitor(QObject* parent) : QObject(parent) {
    infoWidget = new QWidget();
    layout = new QVBoxLayout(infoWidget);
    infoWidget->setLayout(layout);
    itemLayout = new QHBoxLayout();
    layout->addLayout(itemLayout);
    infoLayout = new QVBoxLayout();
    QShortcut* escShortcut = new QShortcut(QKeySequence(Qt::Key_Escape), infoWidget);
    connect(escShortcut, &QShortcut::activated, this, &ItemInfoVisitor::home);
}
ItemInfoVisitor::~ItemInfoVisitor() {
    delete infoWidget;
}
QWidget* ItemInfoVisitor::getWidget() const{
    return infoWidget;
}

void ItemInfoVisitor::infoSetup(AbstractItem& item) {
    editItem=&item;
    imageLabel = new QLabel();
    currentImage = QString::fromStdString(item.getImage());
    if (currentImage.isEmpty()) {
        imagePixmap.load("resources/default.jpg");
    }
    else {
        imagePixmap.load(currentImage);
    }
    QPixmap scaledPixmap = imagePixmap.scaled(400, 400,Qt::KeepAspectRatio,Qt::SmoothTransformation);
    imageLabel->setPixmap(scaledPixmap);
    imageLabel->setAlignment(Qt::AlignCenter);
    imageLabel->setFixedSize(scaledPixmap.size());
    imageLabel->setStyleSheet("border: 1px solid gray;");
    QVBoxLayout* imageLayout = new QVBoxLayout;
    imageLayout->addWidget(imageLabel);
    btnBrowse = new QPushButton("Browse...");
    imageLayout->addWidget(btnBrowse);
    btnBrowse->hide();
    connect(btnBrowse, &QPushButton::clicked, this, &ItemInfoVisitor::onBrowse);

    itemLayout->addLayout(imageLayout);
    QFrame* vLine = new QFrame();
    vLine->setFrameShape(QFrame::VLine);
    vLine->setFrameShadow(QFrame::Sunken);
    itemLayout->addWidget(vLine);
    itemLayout->addLayout(infoLayout);

    QLabel* titleLabel = new QLabel("Title:");
    infoLayout->addWidget(titleLabel);
    QLineEdit* titleEdit = new QLineEdit(QString::fromStdString(item.getTitle()));
    infoLayout->addWidget(titleEdit);
    titleEdit->setReadOnly(true);
    editList.append(titleEdit);

    QLabel* descriptionLabel = new QLabel("Description:");
    infoLayout->addWidget(descriptionLabel);
    QTextEdit* descriptionEdit = new QTextEdit(QString::fromStdString(item.getDescription()));
    infoLayout->addWidget(descriptionEdit);
    descriptionEdit->setReadOnly(true);
    editList.append(descriptionEdit);

    QLabel* yearLabel = new QLabel("Year:");
    infoLayout->addWidget(yearLabel);
    QLineEdit* yearEdit = new QLineEdit(QString::number(item.getYear()));       //VOLENDO QSPINBOX
    infoLayout->addWidget(yearEdit);
    yearEdit->setReadOnly(true);
    yearEdit->setValidator(new QIntValidator(0, 2500));
    editList.append(yearEdit);
}

void ItemInfoVisitor::visitArt(Art& art) {
    infoSetup(art);
    buttonSetup();
    QLabel* authorLabel = new QLabel("Author:");
    infoLayout->addWidget(authorLabel);
    QLineEdit* authorEdit = new QLineEdit(QString::fromStdString(art.getAuthor()));
    infoLayout->addWidget(authorEdit);
    authorEdit->setReadOnly(true);
    editList.append(authorEdit);

    QLabel* sizeLabel = new QLabel("Size:");
    infoLayout->addWidget(sizeLabel);
    QLineEdit* sizeEdit = new QLineEdit(QString::fromStdString(art.getSize()));
    infoLayout->addWidget(sizeEdit);
    sizeEdit->setReadOnly(true);
    editList.append(sizeEdit);

    QLabel* styleLabel = new QLabel("Style:");
    infoLayout->addWidget(styleLabel);
    QLineEdit* styleEdit = new QLineEdit(QString::fromStdString(art.getStyle()));
    infoLayout->addWidget(styleEdit);
    styleEdit->setReadOnly(true);
    editList.append(styleEdit);
}

void ItemInfoVisitor::visitBook(Book& book) {
    infoSetup(book);
    buttonSetup();
    QLabel* authorLabel = new QLabel("Author:");
    infoLayout->addWidget(authorLabel);
    QLineEdit* authorEdit = new QLineEdit(QString::fromStdString(book.getAuthor()));
    infoLayout->addWidget(authorEdit);
    authorEdit->setReadOnly(true);
    editList.append(authorEdit);

    QLabel* sizeLabel = new QLabel("Size:");
    infoLayout->addWidget(sizeLabel);
    QLineEdit* sizeEdit = new QLineEdit(QString::fromStdString(book.getSize()));
    infoLayout->addWidget(sizeEdit);
    sizeEdit->setReadOnly(true);
    editList.append(sizeEdit);


    QLabel* publisherLabel = new QLabel("Publisher:");
    infoLayout->addWidget(publisherLabel);
    QLineEdit* publisherEdit = new QLineEdit(QString::fromStdString(book.getPublisher()));
    infoLayout->addWidget(publisherEdit);
    publisherEdit->setReadOnly(true);
    editList.append(publisherEdit);

    QLabel* genreLabel = new QLabel("Genre:");
    infoLayout->addWidget(genreLabel);
    QLineEdit* genreEdit = new QLineEdit(QString::fromStdString(book.getGenre()));
    infoLayout->addWidget(genreEdit);
    genreEdit->setReadOnly(true);
    editList.append(genreEdit);

    QLabel* editionLabel = new QLabel("Edition:");
    infoLayout->addWidget(editionLabel);
    QLineEdit* editionEdit = new QLineEdit(QString::fromStdString(book.getEdition()));
    infoLayout->addWidget(editionEdit);
    editionEdit->setReadOnly(true);
    editList.append(editionEdit);
}

void ItemInfoVisitor::visitMovie(Movie& movie) {
    infoSetup(movie);
    buttonSetup();

    QLabel* publisherLabel = new QLabel("Publisher:");
    infoLayout->addWidget(publisherLabel);
    QLineEdit* publisherEdit = new QLineEdit(QString::fromStdString(movie.getPublisher()));
    infoLayout->addWidget(publisherEdit);
    publisherEdit->setReadOnly(true);
    editList.append(publisherEdit);

    QLabel* directorLabel = new QLabel("Director:");
    infoLayout->addWidget(directorLabel);
    QLineEdit* directorEdit = new QLineEdit(QString::fromStdString(movie.getDirector()));
    infoLayout->addWidget(directorEdit);
    directorEdit->setReadOnly(true);
    editList.append(directorEdit);

    QLabel* castLabel = new QLabel("Cast:");
    infoLayout->addWidget(castLabel);
    QLineEdit* castEdit = new QLineEdit(QString::fromStdString(movie.getCast()));
    infoLayout->addWidget(castEdit);
    castEdit->setReadOnly(true);
    editList.append(castEdit);

    QLabel* genreLabel = new QLabel("Genre:");
    infoLayout->addWidget(genreLabel);
    QLineEdit* genreEdit = new QLineEdit(QString::fromStdString(movie.getGenre()));
    infoLayout->addWidget(genreEdit);
    genreEdit->setReadOnly(true);
    editList.append(genreEdit);

    QLabel* minutesLabel = new QLabel("Length:");
    infoLayout->addWidget(minutesLabel);
    QLineEdit* minutesEdit = new QLineEdit(QString::number(movie.getLength()));
    infoLayout->addWidget(minutesEdit);
    minutesEdit->setReadOnly(true);
    minutesEdit->setValidator(new QIntValidator(0, 600));
    editList.append(minutesEdit);
}

void ItemInfoVisitor::visitSeries(Series& series) {
    infoSetup(series);
    buttonSetup();

    QLabel* publisherLabel = new QLabel("Publisher:");
    infoLayout->addWidget(publisherLabel);
    QLineEdit* publisherEdit = new QLineEdit(QString::fromStdString(series.getPublisher()));
    infoLayout->addWidget(publisherEdit);
    publisherEdit->setReadOnly(true);
    editList.append(publisherEdit);

    QLabel* directorLabel = new QLabel("Director:");
    infoLayout->addWidget(directorLabel);
    QLineEdit* directorEdit = new QLineEdit(QString::fromStdString(series.getDirector()));
    infoLayout->addWidget(directorEdit);
    directorEdit->setReadOnly(true);
    editList.append(directorEdit);

    QLabel* castLabel = new QLabel("Cast:");
    infoLayout->addWidget(castLabel);
    QLineEdit* castEdit = new QLineEdit(QString::fromStdString(series.getCast()));
    infoLayout->addWidget(castEdit);
    castEdit->setReadOnly(true);
    editList.append(castEdit);

    QLabel* genreLabel = new QLabel("Genre:");
    infoLayout->addWidget(genreLabel);
    QLineEdit* genreEdit = new QLineEdit(QString::fromStdString(series.getGenre()));
    infoLayout->addWidget(genreEdit);
    genreEdit->setReadOnly(true);
    editList.append(genreEdit);

    QLabel* seasonsLabel = new QLabel("Seasons:");
    infoLayout->addWidget(seasonsLabel);
    QLineEdit* seasonsEdit = new QLineEdit(QString::number(series.getSeasons()));
    infoLayout->addWidget(seasonsEdit);
    seasonsEdit->setReadOnly(true);
    seasonsEdit->setValidator(new QIntValidator(0, 100));
    editList.append(seasonsEdit);

    QLabel* episodesLabel = new QLabel("Episodes:");
    infoLayout->addWidget(episodesLabel);
    QLineEdit* episodesEdit = new QLineEdit(QString::number(series.getEpisodes()));
    infoLayout->addWidget(episodesEdit);
    episodesEdit->setReadOnly(true);
    episodesEdit->setValidator(new QIntValidator(0, 10000));
    editList.append(episodesEdit);

}

void ItemInfoVisitor::visitVideogame(Videogame& videogame) {
    infoSetup(videogame);
    buttonSetup();

    QLabel* publisherLabel = new QLabel("Publisher:");
    infoLayout->addWidget(publisherLabel);
    QLineEdit* publisherEdit = new QLineEdit(QString::fromStdString(videogame.getPublisher()));
    infoLayout->addWidget(publisherEdit);
    publisherEdit->setReadOnly(true);
    editList.append(publisherEdit);

    QLabel* genreLabel = new QLabel("Genre:");
    infoLayout->addWidget(genreLabel);
    QLineEdit* genreEdit = new QLineEdit(QString::fromStdString(videogame.getGenre()));
    infoLayout->addWidget(genreEdit);
    genreEdit->setReadOnly(true);
    editList.append(genreEdit);

    QLabel* developerLabel = new QLabel("Developer:");
    infoLayout->addWidget(developerLabel);
    QLineEdit* developerEdit = new QLineEdit(QString::fromStdString(videogame.getDeveloper()));
    infoLayout->addWidget(developerEdit);
    developerEdit->setReadOnly(true);
    editList.append(developerEdit);
}

void ItemInfoVisitor::buttonSetup(){
    QHBoxLayout* buttonLayout = new QHBoxLayout();
    QPushButton* btnDelete = new QPushButton("Remove from library");
    QPushButton* btnEdit = new QPushButton("Edit");
    QPushButton* btnCancel = new QPushButton("Cancel");
    btnCancel->hide();
    QPushButton* btnSave = new QPushButton("Save");
    btnSave->hide();
    QPushButton* btnBack = new QPushButton("Back");

    buttonLayout->addWidget(btnDelete);
    buttonLayout->addStretch();
    layout->addLayout(buttonLayout);
    buttonLayout->addWidget(btnSave);
    buttonLayout->addWidget(btnCancel);
    buttonLayout->addWidget(btnEdit);
    buttonLayout->addWidget(btnBack);

    connect(btnDelete, &QPushButton::clicked, this, [this]() {
        auto result = QMessageBox::question(
            nullptr,
            "Removing from library",
            "Are you sure you want to remove this item?",
            QMessageBox::Yes | QMessageBox::No
            );

        if (result == QMessageBox::Yes) {
            emit deleteRequest();
            emit home();
        }
    });
    connect(btnBack, &QPushButton::clicked, this, &ItemInfoVisitor::onBackHome);
    connect(btnEdit, &QPushButton::clicked, this, [btnSave, btnCancel, btnEdit]() {
        btnSave->show();
        btnCancel->show();
        btnEdit->setEnabled(false);
    });
    connect(btnEdit, &QPushButton::clicked, this, &ItemInfoVisitor::onEdit);
    connect(btnSave, &QPushButton::clicked, this, [btnEdit, btnCancel, btnSave]() {
        btnEdit->setEnabled(true);
        btnCancel->hide();
        btnSave->hide();
    });
    connect(btnSave, &QPushButton::clicked, this, &ItemInfoVisitor::onSave);
    connect(btnCancel, &QPushButton::clicked, this, [btnSave, btnEdit, btnCancel]() {
        btnSave->hide();
        btnEdit->setEnabled(true);
        btnCancel->hide();
    });
    connect(btnCancel, &QPushButton::clicked, this, &ItemInfoVisitor::onCancel);
}

void ItemInfoVisitor::onBackHome() {
    if (QLayout* layout = infoWidget->layout()) {
        QLayoutItem* item;
        while ((item = layout->takeAt(0)) != nullptr) {
            if (item->widget())
                delete item->widget();
            delete item;
        }
        delete layout;
    }
    emit home();
}

void ItemInfoVisitor::onEdit(){
    valoriOriginali.clear();
    btnBrowse->show();
    for (auto it = editList.constBegin(); it != editList.constEnd(); ++it) {
        if (auto lEdit = qobject_cast<QLineEdit*>(*it)) {
            lEdit->setReadOnly(false);
            valoriOriginali[lEdit] = lEdit->text();
        } else if (auto tEdit = qobject_cast<QTextEdit*>(*it)) {
            tEdit->setReadOnly(false);
            valoriOriginali[tEdit] = tEdit->toPlainText();
        }
    }
    valoriOriginali[imageLabel] = currentImage;
}

void ItemInfoVisitor::onBrowse(){
    QString filePath = QFileDialog::getOpenFileName(nullptr, "Select image", "", "Immages (*.png *.jpg *.jpeg *.bmp)");
    if (!filePath.isEmpty()) {
        QPixmap newPixmap;
        if (newPixmap.load(filePath)) {
            QPixmap scaledPixmap = newPixmap.scaled(400, 400, Qt::KeepAspectRatio, Qt::SmoothTransformation);
            imageLabel->setPixmap(scaledPixmap);
            imageLabel->setFixedSize(scaledPixmap.size());
            currentImage = filePath;
        }
    }
}

void ItemInfoVisitor::onCancel(){
    for (auto it = valoriOriginali.constBegin(); it != valoriOriginali.constEnd(); ++it) {
        QWidget* w = it.key();
        const QString& valore = it.value();
        if (auto lEdit = qobject_cast<QLineEdit*>(w)) {
            lEdit->setText(valore);
            lEdit->setReadOnly(true);
        } else if (auto tEdit = qobject_cast<QTextEdit*>(w)) {
            tEdit->setPlainText(valore);
            tEdit->setReadOnly(true);
        } else if (w == imageLabel){
            QPixmap originalPixmap;
            QPixmap scaledPixmap;
            if (originalPixmap.load(valore)) {
                scaledPixmap = originalPixmap.scaled(400, 400, Qt::KeepAspectRatio, Qt::SmoothTransformation);
                currentImage = valore;
                }
            else{
                originalPixmap.load("resources/default.jpg");
                scaledPixmap = originalPixmap.scaled(400, 400, Qt::KeepAspectRatio, Qt::SmoothTransformation);
                currentImage = "resources/default.jpg";
                }
            imageLabel->setPixmap(scaledPixmap);
            imageLabel->setFixedSize(scaledPixmap.size());
            btnBrowse->hide();
        }
    }
}

void ItemInfoVisitor::onSave(){
    QList<QString> saveList;
    for (auto it = editList.constBegin(); it != editList.constEnd(); ++it) {
        if (auto lEdit = qobject_cast<QLineEdit*>(*it)) {
            lEdit->setReadOnly(true);
            saveList.append(lEdit->text());
        } else if (auto tEdit = qobject_cast<QTextEdit*>(*it)) {
            tEdit->setReadOnly(true);
            saveList.append(tEdit->toPlainText());
        }
    }
    saveList.append(currentImage);
    ItemEditVisitor editVisitor(saveList);
    editItem->accept(editVisitor);
}
//aggiungere signal per segnalare modifica
