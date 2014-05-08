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
    comuneEdit->setReadOnly(true);
    foglioEdit=new QLineEdit();
    foglioEdit->setReadOnly(true);
    partiEdit=new QLineEdit();
    partiEdit->setReadOnly(true);
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
    //box2->setEnabled(false);
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
}
