#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class QToolBar;
class QAction;

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    void setupToolBar();

public:
    explicit MainWindow(QWidget *parent = nullptr);

private slots:
    void onAddItem();
    void onRemoveItem();
};

#endif // MAINWINDOW_H
