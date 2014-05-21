#include "centralwidget.h"

CentralWidget::CentralWidget(QWidget* parent): QWidget(parent) {
    drawWidget();
    setValidator();
    lock();
}

void CentralWidget::drawWidget() {
    box1=new QGroupBox(this);
    box1->setTitle("Dati generali");
    comuneLabel=new QLabel("Comune",this);
    foglioLabel=new QLabel("Foglio",this);
    partiLabel=new QLabel("Particella",this);
    propLabel=new QLabel("Proprietario",this);
    renditaLabel=new QLabel("Rendita catastale",this);
    comuneEdit=new QLineEdit(this);
    //TODO trovare una soluzione al contrasto placeholder & focus per comuneEdit
    comuneEdit->setPlaceholderText("A001 - Z999");
    foglioEdit=new QLineEdit(this);
    foglioEdit->setPlaceholderText("1 - 9999");
    partiEdit=new QLineEdit(this);
    partiEdit->setPlaceholderText("1 - 9999");
    propEdit=new QLineEdit(this);
    propEdit->hasFocus();
    renditaEdit=new QLineEdit(this);
    QGridLayout* grid1=new QGridLayout(this);
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

    box2=new QGroupBox(this);
    box2->setTitle("Fabbricato");
    classeLabel=new QLabel("Classe catastale",this);
    classeEdit=new QLineEdit(this);
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

    QVBoxLayout* layout=new QVBoxLayout(this);
    layout->addWidget(box1);
    layout->addWidget(box2);
    setLayout(layout);

    QFont upperCase;
    upperCase.setCapitalization(QFont::AllUppercase);
    propEdit->setFont(upperCase);
}

void CentralWidget::setValidator() {
    QRegExp comuneExp("^[A-Z]{1}[0-9]{3}$");
    QRegExp renditaExp("^\\d*\\W?\\d?\\d?$");
    QRegExp classeExp("^[A-D]{1}[1-9]{1}[0-1]?$");
    QRegExp intExp("^[1-9]{1}[0-9]{0,3}$");
    QValidator* v1=new QRegExpValidator(intExp,this);
    QValidator* v2=new QRegExpValidator(renditaExp,this);
    QValidator* v3=new QRegExpValidator(comuneExp,this);
    QValidator* v4=new QRegExpValidator(classeExp,this);
    comuneEdit->setValidator(v3);
    foglioEdit->setValidator(v1);
    partiEdit->setValidator(v1);
    renditaEdit->setValidator(v2);
    classeEdit->setValidator(v4);
}

QHash<QString,QString>* CentralWidget::getFieldModified() {
    hash=new QHash<QString,QString>();
    if (comuneEdit->isModified())
        hash->insert("comune",comuneEdit->text());
    if (foglioEdit->isModified())
        hash->insert("foglio",foglioEdit->text());
    if (partiEdit->isModified())
        hash->insert("parti",partiEdit->text());
    if (propEdit->isModified())
        hash->insert("prop",propEdit->text());
    if (renditaEdit->isModified())
        hash->insert("rendita",renditaEdit->text());
    if (classeEdit->isModified())
        hash->insert("classe",classeEdit->text());
    if (primaCasa->isChecked())
        hash->insert("primaCasa","true");
    else
        hash->insert("primaCasa","false");
    if (storico->isChecked())
        hash->insert("storico","true");
    else
        hash->insert("storico","false");
    if (inagibile->isChecked())
        hash->insert("inagibile","true");
    else
        hash->insert("inagibile","false");
    return hash;
}

void CentralWidget::updateField(bool f, QString co, QString fo, QString pa, QString pr, QString re, QString cl, bool pc, bool st, bool in) {
    comuneEdit->setText(co);
    foglioEdit->setText(fo);
    partiEdit->setText(pa);
    propEdit->setText(pr);
    renditaEdit->setText(re);
    if (f) {
        box2->setEnabled(true);
        classeEdit->setText(cl);
        primaCasa->setChecked(pc);
        storico->setChecked(st);
        inagibile->setChecked(in);
    }
    else {
        box2->setDisabled(true);
    }
}

void CentralWidget::clear() {
    comuneEdit->setText("");
    foglioEdit->setText("");
    partiEdit->setText("");
    propEdit->setText("");
    renditaEdit->setText("");
    classeEdit->setText("");
    primaCasa->setAutoExclusive(false);
    primaCasa->setChecked(false);
    primaCasa->setAutoExclusive(true);
    storico->setAutoExclusive(false);
    storico->setChecked(false);
    storico->setAutoExclusive(true);
    inagibile->setAutoExclusive(false);
    inagibile->setChecked(false);
    inagibile->setAutoExclusive(true);
}

void CentralWidget::lock() const {
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

void CentralWidget::unlock() const {
    comuneEdit->setReadOnly(false);
    foglioEdit->setReadOnly(false);
    partiEdit->setReadOnly(false);
    propEdit->setReadOnly(false);
    renditaEdit->setReadOnly(false);
    classeEdit->setReadOnly(false);
    primaCasa->setEnabled(true);
    storico->setEnabled(true);
    inagibile->setEnabled(true);
}

bool CentralWidget::haveNewData() const {
    return comuneEdit->isModified() && foglioEdit->isModified() && partiEdit->isModified() && propEdit->isModified() && renditaEdit->isModified();
}

void CentralWidget::newInsert() {
    clear();
    box2->setEnabled(true);
    unlock();
}

void CentralWidget::modify() {
    unlock();
    comuneEdit->setReadOnly(true);
    foglioEdit->setReadOnly(true);
    partiEdit->setReadOnly(true);
}
