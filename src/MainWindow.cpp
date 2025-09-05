#include "../headers/MainWindow.h"
#include "../headers/JsonManager.h"
#include "../headers/XmlManager.h"
#include <QAction>
#include <QDebug>
#include <QLayout>
#include <QLineEdit>
#include <QMenuBar>
#include <QFileDialog>
#include <QMessageBox>
#include <QPushButton>
#include <QShortcut>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    model(new LibraryModel(this)),
    typeFilter(new LibraryTypeFilterModel(this)),
    searchFilter(new LibrarySearchFilterModel(this)),
    view(new QListView(this)),
    searchEdit(new QLineEdit(this))
{
    typeFilter->setSourceModel(model);              // Filtri tipo e ricerca a cascata
    searchFilter->setSourceModel(typeFilter);

    searchFilter->sort(0, Qt::AscendingOrder);      // Ordinamento alfabetico

    view->setModel(searchFilter);                   // Setup della listview
    view->setViewMode(QListView::IconMode);
    view->setIconSize(QSize(120, 160));
    view->setGridSize(QSize(160, 200));
    view->setResizeMode(QListView::Adjust);


    setWindowTitle("Libreria Multimediale");    // Setup mainwindow
    setupMenu();
    auto central = new QWidget(this);
    auto layout = new QVBoxLayout(central);
    layout->addWidget(searchEdit);
    layout->addWidget(view);
    setCentralWidget(central);

    connect(searchEdit, &QLineEdit::textChanged, this, [this](const QString &text){
        searchFilter->setTitleFilter(text);
    });

    // Shortcut

    QShortcut* saveShortcut = new QShortcut(QKeySequence("Ctrl+S"), this);
    connect(saveShortcut, &QShortcut::activated, this, &MainWindow::saveShortcut);
};

void MainWindow::setupMenu(){
    QMenu* fileMenu = menuBar()->addMenu("File");
    QAction* saveJsonAction = fileMenu->addAction("Salva come Json");
    QAction* saveXmlAction = fileMenu->addAction("Salva come XML");
    QAction* loadJsonAction = fileMenu->addAction("Carica da Json");
    QAction* loadXmlAction = fileMenu->addAction("Carica da XML");
    connect(loadJsonAction, &QAction::triggered, this, &MainWindow::loadFromJson);
    connect(loadXmlAction, &QAction::triggered, this, &MainWindow::loadFromXml);
    connect(saveJsonAction, &QAction::triggered, this, &MainWindow::saveAsJson);
    connect(saveXmlAction, &QAction::triggered, this, &MainWindow::saveAsXml);
}

void MainWindow::loadFromJson(){
    QString fileName = QFileDialog::getOpenFileName(
        this,
        "Seleziona file JSON",
        QDir::homePath(),
        "JSON files (*.json);;All files (*)"
        );

    if (!fileName.isEmpty()) {
        model->loadLib(loadJson(fileName));
    }
};
void MainWindow::loadFromXml(){
    QString fileName = QFileDialog::getOpenFileName(
        this,
        "Seleziona file XML",
        QDir::homePath(),
        "XML files (*.xml);;All files (*)"
        );

    if (!fileName.isEmpty()) {
        model->loadLib(loadXml(fileName));
    }
};


void MainWindow::saveAsJson(){
    QString fileName = QFileDialog::getSaveFileName(
        this,
        "Salva come JSON",
        QDir::homePath(),
        "JSON files (*.json);;All files (*)"
        );

    if (!fileName.isEmpty()) {
        if (!fileName.endsWith(".json", Qt::CaseInsensitive)) {
            fileName += ".json";
        }

#ifdef Q_OS_WIN
        // Su Windows non serve conferma -> evitiamo doppia conferma
#else
        // Su Linux serve conferma sovrascrittura perché non c'è di default
        if (QFile::exists(fileName)) {
            auto reply = QMessageBox::question(
                this,
                "Conferma sovrascrittura",
                QString("Il file \"%1\" esiste già.\nVuoi sovrascriverlo?").arg(fileName),
                QMessageBox::Yes | QMessageBox::No
                );

            if (reply != QMessageBox::Yes)
                return;
        }
#endif

        model->saveAsJson(fileName);
    }
};


void MainWindow::saveAsXml(){
    QString fileName = QFileDialog::getSaveFileName(
        this,
        "Salva come XML",
        QDir::homePath(),
        "XML files (*.xml);;All files (*)"
        );

    if (!fileName.isEmpty()) {
        if (!fileName.endsWith(".xml", Qt::CaseInsensitive)) {
            fileName += ".xml";
        }

#ifdef Q_OS_WIN
        // Su Windows non serve conferma -> evitiamo doppia conferma
#else
        // Su Linux serve conferma sovrascrittura perché non c'è di default
        if (QFile::exists(fileName)) {
            auto reply = QMessageBox::question(
                this,
                "Conferma sovrascrittura",
                QString("Il file \"%1\" esiste già.\nVuoi sovrascriverlo?").arg(fileName),
                QMessageBox::Yes | QMessageBox::No
                );

            if (reply != QMessageBox::Yes)
                return;
        }
#endif

        model->saveAsXml(fileName);
    }
};

void MainWindow::saveShortcut(){
    QDialog dialog(this);
    dialog.setWindowTitle("Scegli il formato di salvataggio");  // Finestra scelta formato con scorciatoia salvataggio

    QPushButton *btnJson = new QPushButton("Salva come JSON");
    QPushButton *btnXml = new QPushButton("Salva come XML");

    QHBoxLayout *layout = new QHBoxLayout;
    layout->addWidget(btnJson);
    layout->addWidget(btnXml);
    dialog.setLayout(layout);

    connect(btnJson, &QPushButton::clicked, &dialog, [&](){
        saveAsJson();
        dialog.accept();
    });

    connect(btnXml, &QPushButton::clicked, &dialog, [&](){
        saveAsXml();
        dialog.accept();
    });

    dialog.exec();
};
