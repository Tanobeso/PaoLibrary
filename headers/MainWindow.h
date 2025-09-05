#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "LibraryModel.h"
#include <QMainWindow>
#include <QSortFilterProxyModel>
#include <QListView>
#include "LibraryFilterModel.h"
#include "QVBoxLayout"
#include <QStackedWidget>

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
    QStackedWidget* stackedWidget;
    QWidget* visitorWidget;
public:
    explicit MainWindow(QWidget *parent = nullptr);

private slots:
    void loadFromJson();
    void loadFromXml();
    void saveAsJson();
    void saveAsXml();
    void saveShortcut();
    void itemClicked(const QModelIndex&);
};

#endif // MAINWINDOW_H
