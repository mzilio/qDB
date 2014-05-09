#include "centralwidget.h"

CentralWidget::CentralWidget(QWidget *parent) : QWidget(parent) {
    drawWidget();
}

void CentralWidget::drawWidget() {
    comuneLabel=new QLabel("Comune");
    foglioLabel=new QLabel("Foglio");
    partiLabel=new QLabel("Particella");
    propLabel=new QLabel("Proprietario");
    renditaLabel=new QLabel("Rendita catastale");
    comuneEdit=new QLineEdit();
    foglioEdit=new QLineEdit();
    partiEdit=new QLineEdit();
    propEdit=new QLineEdit();
    renditaEdit=new QLineEdit();
    QGroupBox* box1=new QGroupBox();
    box1->setTitle("Dati generali");
    QGridLayout* grid1=new QGridLayout();
    grid1->addWidget(comuneLabel,0,0);
    grid1->addWidget(comuneEdit,1,0);
    grid1->addWidget(foglioLabel,0,1);
    grid1->addWidget(foglioEdit,1,1);
    grid1->addWidget(partiLabel,0,2);
    grid1->addWidget(partiEdit,1,2);
    grid1->addWidget(propLabel,2,0);
    grid1->addWidget(propEdit,2,1,1,2);
    grid1->addWidget(renditaLabel,3,0);
    grid1->addWidget(renditaEdit,3,1,1,2);
    box1->setLayout(grid1);

    QGroupBox* box2=new QGroupBox();
    box2->setTitle("Fabbricato");
    classeLabel=new QLabel("Classe catastale");
    classeEdit=new QLineEdit();
    primaCasa=new QRadioButton("Prima casa",this);
    storico=new QRadioButton("Storico",this);
    inagibile=new QRadioButton("Inagibile",this);
    QGridLayout* grid2=new QGridLayout();
    grid2->addWidget(classeLabel,0,0);
    grid2->addWidget(classeEdit,0,1,1,2);
    //TODO gestire intelligentemente le agevolazioni
    grid2->addWidget(primaCasa,1,0);
    grid2->addWidget(storico,1,1);
    grid2->addWidget(inagibile,1,2);
    box2->setLayout(grid2);

    QVBoxLayout* layout=new QVBoxLayout();
    layout->addWidget(box1);
    layout->addWidget(box2);
    setLayout(layout);
    readOnly();
}

void CentralWidget::readOnly() {
    comuneEdit->setReadOnly(true);
    foglioEdit->setReadOnly(true);
    partiEdit->setReadOnly(true);
    propEdit->setReadOnly(true);
    renditaEdit->setReadOnly(true);
    classeEdit->setReadOnly(true);
    primaCasa->setEnabled(false);
    storico->setEnabled(false);
    inagibile->setEnabled(false);
}

void CentralWidget::newInsert() {
    comuneEdit->clear();
    comuneEdit->setReadOnly(false);
    foglioEdit->clear();
    foglioEdit->setReadOnly(false);
    partiEdit->clear();
    partiEdit->setReadOnly(false);
    propEdit->clear();
    propEdit->setReadOnly(false);
    renditaEdit->clear();
    renditaEdit->setReadOnly(false);
    classeEdit->clear();
    classeEdit->setReadOnly(false);
    primaCasa->setEnabled(true);
    primaCasa->setAutoExclusive(false);
    primaCasa->setChecked(false);
    primaCasa->setAutoExclusive(true);
    storico->setEnabled(true);
    storico->setAutoExclusive(false);
    storico->setChecked(false);
    storico->setAutoExclusive(true);
    inagibile->setEnabled(true);
    inagibile->setAutoExclusive(false);
    inagibile->setChecked(false);
    inagibile->setAutoExclusive(true);
}

void CentralWidget::modify() {
    comuneEdit->setReadOnly(true);
    foglioEdit->setReadOnly(true);
    partiEdit->setReadOnly(true);
}
