#include "searchdialog.h"

void SearchDialog::connectSignalSlot() {
    connect(search,SIGNAL(clicked()),mainWindow,SLOT(startSearch()));
    connect(cancel,SIGNAL(clicked()),this,SLOT(reject()));
}

QHash<QString,QString>* SearchDialog::sendDataSearch() {
    hash=new QHash<QString,QString>();
    hash->insert("comune",comuneEdit->text());
    hash->insert("foglio",foglioEdit->text());
    hash->insert("parti",partiEdit->text());
    done(0);
    return hash;
}

SearchDialog::SearchDialog(QWidget* parent): QDialog(parent), mainWindow(parent) {
    comuneLabel=new QLabel("Comune");
    foglioLabel=new QLabel("Foglio");
    partiLabel=new QLabel("Particella");
    comuneEdit=new QLineEdit();
    foglioEdit=new QLineEdit();
    partiEdit=new QLineEdit();
    search=new QPushButton("Cerca");
    cancel=new QPushButton("Cancella");

    QRegExp comuneExp("^[A-Z]{1}[0-9]{3}$");
    //TODO chiedere a papà il range per l'int validator
    QValidator* v1=new QIntValidator(0,1000,this);
    QValidator* v2=new QRegExpValidator(comuneExp,this);
    comuneEdit->setValidator(v2);
    foglioEdit->setValidator(v1);
    partiEdit->setValidator(v1);

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
