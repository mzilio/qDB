#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTextEdit>
#include <QTableView>
#include <QMenuBar>
#include <QMenu>
#include <QToolBar>
#include <QStatusBar>
#include <QAction>
#include <QMessageBox>
#include "centralwidget.h"
#include "searchdialog.h"

class MainWindow : public QMainWindow {
    Q_OBJECT
private:
    QMenu* fileMenu;
    QToolBar* toolBar;
    QAction* newRecord;
    QAction* saveRecord;
    QAction* deleteRecord;
    QAction* searchRecord;
    QAction* calcoloImu;
    SearchDialog* searchWindow;
    void createActions();
    void connectSignalSlot();
private slots:
    void showImu();
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
};
#endif // MAINWINDOW_H
