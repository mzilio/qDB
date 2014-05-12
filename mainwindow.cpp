#include "mainwindow.h"

void MainWindow::createActions() {
    newRecord=new QAction("Nuovo",this);
    modifyRecord=new QAction("Modifica",this);
    saveRecord=new QAction("Salva",this);
    deleteRecord=new QAction("Elimina",this);
    searchRecord=new QAction("Cerca",this);
    calcoloImu=new QAction("Calcolo IMU",this);
}

void MainWindow::connectSignalSlot() {
    connect(newRecord,SIGNAL(triggered()),centralWindow,SLOT(newInsert()));
    connect(modifyRecord,SIGNAL(triggered()),centralWindow,SLOT(modify()));
    connect(saveRecord,SIGNAL(triggered()),this,SLOT(saveToModel()));
    //TODO connect(deleteRecord,SIGNAL(triggered()),this,SLOT());
    //TODO connect(searchRecord,SIGNAL(triggered()),searchWindow,SLOT(exec()));
    connect(calcoloImu,SIGNAL(triggered()),this,SLOT(showImu()));
}

void MainWindow::saveToModel() {
    //TODO recuperare i dati dalla central window e inviarli al controller
}

void MainWindow::showImu() {
    QMessageBox show;
    show.setText("L'IMU calcolato per il bene immobile selezionato risulta essere di euro:");
    //TODO show.setInformativeText("125,00"); invocando il metodo calcoloImu() sull'oggetto
    show.setStandardButtons(QMessageBox::Ok);
    show.setIcon(QMessageBox::Information);
    show.exec();
}

MainWindow::MainWindow(QWidget* parent): QMainWindow(parent) {
    searchWindow = new SearchDialog(this);
    createActions();

    //Imposto il central widget
    centralWindow = new CentralWidget(this);
    setCentralWidget(centralWindow);

    //Aggiungo un menu alla menu bar
    fileMenu = menuBar()->addMenu("&File");

    //Al nuovo menu aggiungo delle azioni
    fileMenu->addAction("&New DB");
    fileMenu->addAction("&Open DB");
    fileMenu->addAction("&Save DB");

    //Istruzioni per la tool bar
    toolBar = addToolBar("Record");
    toolBar->addAction(newRecord);
    toolBar->addAction(modifyRecord);
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

void MainWindow::setController(Controller* c) {
    controller=c;
}
