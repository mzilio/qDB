#include "searchdialog.h"

void SearchDialog::connectSignalSlot() {
    connect(cancel,SIGNAL(clicked()),this,SLOT(reject()));
}

SearchDialog::SearchDialog(QWidget *parent): QDialog(parent) {
    comuneLabel=new QLabel("Comune");
    foglioLabel=new QLabel("Foglio");
    partiLabel=new QLabel("Particella");
    comuneEdit=new QLineEdit();
    foglioEdit=new QLineEdit();
    partiEdit=new QLineEdit();
    search=new QPushButton("Cerca");
    cancel=new QPushButton("Cancella");
    QGridLayout* grid=new QGridLayout();
    grid->addWidget(comuneLabel,0,0);
    grid->addWidget(comuneEdit,0,1);
    grid->addWidget(foglioLabel,1,0);
    grid->addWidget(foglioEdit,1,1);
    grid->addWidget(partiLabel,2,0);
    grid->addWidget(partiEdit,2,1);
    grid->addWidget(search,3,0);
    grid->addWidget(cancel,3,1);
    setLayout(grid);
    setMaximumSize(minimumSize());
    connectSignalSlot();
}
