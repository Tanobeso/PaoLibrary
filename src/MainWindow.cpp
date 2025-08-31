#include "../headers/MainWindow.h"
#include <QToolBar>
#include <QAction>
#include <QDebug>
#include <QLayout>
#include <QLineEdit>
MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent){
    setWindowTitle("Libreria Multimediale");
    setupToolBar();
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

    auto central = new QWidget(this);
    auto layout = new QVBoxLayout(central);
    layout->addWidget(searchEdit);
    layout->addWidget(view);
    setCentralWidget(central);

    connect(searchEdit, &QLineEdit::textChanged, this, [this](const QString &text){
        proxy->setTitleFilter(text);
    });
}

void MainWindow::setupToolBar(){
    QToolBar *toolBar = new QToolBar("Barra strumenti", this);
    toolBar->setToolButtonStyle(Qt::ToolButtonTextOnly); // Solo testo
    addToolBar(toolBar);

    // Aggiungi
    QAction *addAction = new QAction("Aggiungi", this);
    connect(addAction, &QAction::triggered, this, &MainWindow::onAddItem);
    toolBar->addAction(addAction);

    toolBar->addSeparator();
    // Rimuovi
    QAction *removeAction = new QAction("Rimuovi", this);
    connect(removeAction, &QAction::triggered, this, &MainWindow::onRemoveItem);
    toolBar->addAction(removeAction);
}

void MainWindow::onAddItem(){
    qDebug()<<"Aggiungi";
}
void MainWindow::onRemoveItem(){
    qDebug()<<"Rimuovi";
}
