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
#include "controller.h"
#include "centralwidget.h"
#include "searchdialog.h"

class Controller;

class MainWindow : public QMainWindow {
    Q_OBJECT
private:
    Controller* controller;
    CentralWidget* centralWindow;
    SearchDialog* searchWindow;
    QMenu* fileMenu;
    QToolBar* toolBar;
    QAction* newRecord;
    QAction* modifyRecord;
    QAction* saveRecord;
    QAction* deleteRecord;
    QAction* searchRecord;
    QAction* calcoloImu;
    void createActions();
    void connectSignalSlot();
private slots:
    void saveToModel();
    void deleteFromModel();
    void showImu();
    void newInsert();
public:
    MainWindow(QWidget* = 0);
    ~MainWindow();
    void setController(Controller*);
    void updateView();
    void showWarning(const QString&);
    void showStatus(const QString&,int =2000);
    void clearField() const;
    void lockField() const;
public slots:
    void startSearch();
};
#endif // MAINWINDOW_H
