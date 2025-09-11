#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "LibraryModel.h"
#include <QMainWindow>
#include <QSortFilterProxyModel>
#include <QListView>
#include "LibraryFilterModel.h"
#include <QVBoxLayout>
#include <QStackedWidget>
#include "ItemInfoVisitor.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    LibraryModel* model = nullptr;
    LibraryTypeFilterModel* typeFilter=nullptr;
    LibrarySearchFilterModel* searchFilter=nullptr;
    QListView* view = nullptr;
    QLineEdit* searchEdit;
    QStackedWidget* stackedWidget;
    ItemInfoVisitor* infoVisitor;
    QVBoxLayout* layout;
    QVBoxLayout* filterLayout;
    void setupMenu();
    void setupFilters();
public:
    explicit MainWindow(QWidget *parent = nullptr);

private slots:
    void loadFromJson();
    void loadFromXml();
    void saveAsJson();
    void saveAsXml();
    void saveShortcut();
    void itemClicked(const QModelIndex&);
    void setType(const string&);
    void onBackHome();
};

#endif // MAINWINDOW_H
