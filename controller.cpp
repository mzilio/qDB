#include "controller.h"

Controller::Controller(Container<Record>* m, MainWindow* v): model(m), view(v), actualRecord(0) {
    view->setController(this);
    view->show();
}

Record* Controller::getActualRecord() const {
    return actualRecord;
}

void Controller::resetActualRecord() {
    actualRecord=0;
}

void Controller::searchRecord(QHash<QString,QString>* x) {
    string comune=x->value("comune").toStdString();
    int foglio=x->value("foglio").toInt();
    int parti=x->value("parti").toInt();
    Terreno t(comune,foglio,parti,"",0.0);
    Record r(&t);
    Container<Record>::Iterator it=model->FindItem(r);
    actualRecord=*it;
    view->updateView();
    view->lockField();
    if (!it)
        view->showWarning("La ricerca non ha prodotto risultati");
}

void Controller::insertRecord(QHash<QString,QString>* x) {
    BeneImmobile* newRecord;
    string comune=x->value("comune").toStdString();
    int foglio=x->value("foglio").toInt();
    int parti=x->value("parti").toInt();
    string prop=x->value("prop").toStdString();
    double rendita=x->value("rendita").toDouble();
    if (x->contains("classe")) {
        string classe=x->value("classe").toStdString();
        bool pc, s, i;
        if (x->value("primaCasa")=="true")
            pc=true;
        else
            pc=false;
        if (x->value("storico")=="true")
            s=true;
        else
            s=false;
        if (x->value("inagibile")=="true")
            i=true;
        else
            i=false;
        newRecord=new Fabbricato(comune,foglio,parti,prop,rendita,classe,pc,s,i);
    }
    else {
        newRecord=new Terreno(comune,foglio,parti,prop,rendita);
    }
    Record r(newRecord);
    Container<Record>::Iterator it=model->FindItem(r);
    if (it) {
        view->showWarning("Il bene che si sta tentando di inserire e' gia presente");
        actualRecord=*it;
        view->updateView();
        view->lockField();
    }
    else {
        model->AddItem(r);
        view->showStatus("Bene inserito");
        view->clearField();
        view->lockField();
    }
}

void Controller::modifyRecord(QHash<QString,QString>* x) {
    if (x->contains("prop"))
        (*actualRecord)->setProprietario(x->value("prop").toStdString());
    if (x->contains("rendita"))
        (*actualRecord)->setRenditaCatastale(x->value("rendita").toDouble());
    Fabbricato* f=dynamic_cast<Fabbricato*>(&(**actualRecord));
    if (f) {
        if (x->contains("classe"))
            f->setCategoriaCatastale(x->value("classe").toStdString());
        if (x->value("primaCasa")=="true")
            f->setPrimaCasa(true);
        else
            f->setPrimaCasa(false);
        if (x->value("storico")=="true")
            f->setStorico(true);
        else
            f->setStorico(false);
        if (x->value("inagibile")=="true")
            f->setInagibile(true);
        else
            f->setInagibile(false);
    }
    view->showStatus("Bene modificato");
    view->lockField();
}

void Controller::deleteRecord() {
    if (actualRecord) {
        model->RemoveItem(*actualRecord);
        actualRecord=0;
        view->updateView();
        view->lockField();
        view->showStatus("Bene eliminato");
    }
}
