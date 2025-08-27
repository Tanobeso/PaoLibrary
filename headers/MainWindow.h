#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "Library.h"
#include <QMainWindow>
#include <QSortFilterProxyModel>
#include <QListView>
#include "LibraryFilterModel.h"

class QToolBar;
class QAction;

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    void setupToolBar();
    Library* model = nullptr;
    LibraryFilterModel* proxy=nullptr;
    QListView* view = nullptr;
    QLineEdit* searchEdit;
public:
    explicit MainWindow(QWidget *parent = nullptr);
    explicit MainWindow(Library* libModel, QWidget *parent = nullptr);

private slots:
    void onAddItem();
    void onRemoveItem();
};

#endif // MAINWINDOW_H
