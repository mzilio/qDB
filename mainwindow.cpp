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
    connect(searchRecord,SIGNAL(triggered()),searchWindow,SLOT(exec()));
    connect(calcoloImu,SIGNAL(triggered()),this,SLOT(showImu()));
}

void MainWindow::saveToModel() {
    //TODO se è gia presente aggiorno i dati altrimenti faccio un nuovo inserimento
    controller->insertRecord(centralWindow->getFieldModified());
    centralWindow->clear();
    centralWindow->lock();
    //TODO modificare opportunamente statusBar()->showMessage("Pronto",2000);
}

void MainWindow::showImu() {
    Record* x=controller->getActualRecord();
    QMessageBox show;
    if (x) {
        show.setText("L'IMU calcolato per il bene immobile selezionato risulta essere di euro:");
        try {
            show.setInformativeText(QString::number((*x)->calcoloImu()));
            show.setIcon(QMessageBox::Information);
        }
        catch (Error e) {
            show.setText(QString::fromStdString(e.getError()));
            show.setIcon(QMessageBox::Warning);
        }
    }
    else {
        show.setText("Non e' stato selezionato alcun bene immobile!");
        show.setIcon(QMessageBox::Warning);
    }
    show.setStandardButtons(QMessageBox::Ok);
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

void MainWindow::updateView() {
    Record* x=controller->getActualRecord();
    if (x) {
        centralWindow->clear();
        bool primaCasa=false, storico=false, inagibile=false;
        QString comune=QString::fromStdString((*x)->getIdentificativoCatastale().getComune());
        QString foglio=QString::number((*x)->getIdentificativoCatastale().getFoglio());
        QString particella=QString::number((*x)->getIdentificativoCatastale().getParticella());
        QString proprietario=QString::fromStdString((*x)->getProprietario());
        QString rendita=QString::number((*x)->getRenditaCatastale());
        QString classe="";
        Fabbricato* f=dynamic_cast<Fabbricato*>(&(**x));
        if (f) {
            classe=QString::fromStdString(f->getCategoriaCatastale());
            primaCasa=f->isPrimaCasa();
            storico=f->isStorico();
            inagibile=f->isInagibile();
        }
        centralWindow->updateField(f,comune,foglio,particella,proprietario,rendita,classe,primaCasa,storico,inagibile);
    }
    else {
        QMessageBox::warning(this,"qDB","La ricerca non ha prodotto risultati",QMessageBox::Ok);
    }
}

void MainWindow::startSearch() {
    controller->searchRecord(searchWindow->sendDataSearch());
}
