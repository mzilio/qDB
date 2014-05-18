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
    connect(deleteRecord,SIGNAL(triggered()),this,SLOT(deleteFromModel()));
    connect(searchRecord,SIGNAL(triggered()),searchWindow,SLOT(exec()));
    connect(calcoloImu,SIGNAL(triggered()),this,SLOT(showImu()));
}

void MainWindow::saveToModel() {
    //TODO non posso poter aggiungere oggetti senza campi dati
    //TODO se è gia presente aggiorno i dati altrimenti faccio un nuovo inserimento
    controller->insertRecord(centralWindow->getFieldModified());
    centralWindow->clear();
    centralWindow->lock();
}

void MainWindow::deleteFromModel() {
    if (controller->getActualRecord()) {
        controller->deleteRecord();
    }
    else
        showWarning("Non e' stato selezionato alcun bene immobile!");
}

void MainWindow::showImu() {
    Record* x=controller->getActualRecord();
    if (x) {
        try {
            QMessageBox show;
            show.setText("L'IMU calcolato per il bene immobile selezionato risulta essere di euro:");
            show.setInformativeText(QString::number((*x)->calcoloImu()));
            show.setIcon(QMessageBox::Information);
            show.setStandardButtons(QMessageBox::Ok);
            show.exec();
        }
        catch (Error e) {
            showWarning(QString::fromStdString(e.getError()));
        }
    }
    else
        showWarning("Non e' stato selezionato alcun bene immobile!");
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

    showStatus("Pronto");
    connectSignalSlot();
}

MainWindow::~MainWindow() {}

void MainWindow::setController(Controller* c) {
    controller=c;
}

void MainWindow::updateView() {
    Record* x=controller->getActualRecord();
    centralWindow->clear();
    if (x) {
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
    centralWindow->lock();
}

void MainWindow::showWarning(const QString& x) {
    QMessageBox::warning(this,"qDB",x,QMessageBox::Ok);
}

void MainWindow::showStatus(const QString& x, int y) {
    statusBar()->showMessage(x,y);
}

void MainWindow::startSearch() {
    controller->searchRecord(searchWindow->sendDataSearch());
}
