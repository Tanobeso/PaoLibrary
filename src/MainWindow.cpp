#include "../headers/MainWindow.h"
#include <QAction>
#include <QDebug>
#include <QLayout>
#include <QLineEdit>
#include <QMenuBar>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent){
    setWindowTitle("Libreria Multimediale");
    setupMenu();
};

MainWindow::MainWindow(LibraryModel* libraryModel, QWidget* parent)
    : QMainWindow(parent),
    model(libraryModel),
    proxy(new LibraryFilterModel(this)),
    view(new QListView(this)),
    searchEdit(new QLineEdit(this))
{
    proxy->setSourceModel(model);

    view->setModel(proxy);
    view->setViewMode(QListView::IconMode);
    view->setIconSize(QSize(120, 160));
    view->setGridSize(QSize(160, 200));
    view->setResizeMode(QListView::Adjust);

    setupMenu();
    auto central = new QWidget(this);
    auto layout = new QVBoxLayout(central);
    layout->addWidget(searchEdit);
    layout->addWidget(view);
    setCentralWidget(central);

    connect(searchEdit, &QLineEdit::textChanged, this, [this](const QString &text){
        proxy->setTitleFilter(text);
    });
}

void MainWindow::setupMenu(){
    QMenu* fileMenu = menuBar()->addMenu("File");
    QAction* saveJsonAction = fileMenu->addAction("Salva come Json");
    QAction* saveXMLAction = fileMenu->addAction("Salva come XML");
    QAction* loadJsonAction = fileMenu->addAction("Carica da Json");
    QAction* loadXMLAction = fileMenu->addAction("Carica da XML");
}

void MainWindow::onAddItem(){
    qDebug()<<"Aggiungi";
}
void MainWindow::onRemoveItem(){
    qDebug()<<"Rimuovi";
}
