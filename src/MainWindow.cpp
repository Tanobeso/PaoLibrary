#include "..\headers\MainWindow.h"
#include <QToolBar>
#include <QAction>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent){
    setWindowTitle("Libreria Multimediale");
    setupToolBar();
};

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
