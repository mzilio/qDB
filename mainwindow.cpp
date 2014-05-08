#include "mainwindow.h"

void MainWindow::createActions() {
    newRecord=new QAction("Nuovo",this);
    saveRecord=new QAction("Salva",this);
    deleteRecord=new QAction("Elimina",this);
    searchRecord=new QAction("Cerca",this);
    calcoloImu=new QAction("Calcolo IMU",this);
}

void MainWindow::connectSignalSlot() {
    connect(searchRecord,SIGNAL(triggered()),searchWindow,SLOT(exec()));
    connect(calcoloImu,SIGNAL(triggered()),this,SLOT(showImu()));
}

void MainWindow::showImu() {
    QMessageBox show;
    show.setText("L'IMU calcolato per il bene immobile selezionato risulta essere di euro:");
    //show.setInformativeText("125,00");
    show.setStandardButtons(QMessageBox::Ok);
    show.setIcon(QMessageBox::Information);
    show.exec();
}

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    searchWindow = new SearchDialog();
    createActions();

    //Imposto il central widget
    CentralWidget* t = new CentralWidget();
    setCentralWidget(t);

    //Aggiungo un menu alla menu bar
    fileMenu = menuBar()->addMenu("&File");

    //Al nuovo menu aggiungo delle azioni
    fileMenu->addAction("&New DB");
    fileMenu->addAction("&Open DB");
    fileMenu->addAction("&Save DB");

    //Istruzioni per la tool bar
    toolBar = addToolBar("Record");
    toolBar->addAction(newRecord);
    toolBar->addAction(saveRecord);
    toolBar->addAction(deleteRecord);
    toolBar->addAction(searchRecord);
    toolBar->addSeparator();
    toolBar->addAction(calcoloImu);
    toolBar->setMovable(false);

    statusBar()->showMessage("Pronto",2000);
    connectSignalSlot();
}

MainWindow::~MainWindow() {}
