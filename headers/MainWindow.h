#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "LibraryModel.h"
#include <QMainWindow>
#include <QSortFilterProxyModel>
#include <QListView>
#include "LibraryFilterModel.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    void setupMenu();
    LibraryModel* model = nullptr;
    LibraryTypeFilterModel* typeFilter=nullptr;
    LibrarySearchFilterModel* searchFilter=nullptr;
    QListView* view = nullptr;
    QLineEdit* searchEdit;
public:
    explicit MainWindow(QWidget *parent = nullptr);
    explicit MainWindow(LibraryModel* libModel, QWidget *parent = nullptr);

private slots:
    void onAddItem();
    void onRemoveItem();
};

#endif // MAINWINDOW_H
