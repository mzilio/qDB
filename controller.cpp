#include "controller.h"

Controller::Controller(Container<Record>* m, MainWindow* v): model(m), view(v) {
    view->setController(this);
    view->show();
}

void Controller::searchRecord(QHash<QString,QString>* x) {
    string comune=x->value("comune").toStdString();
    int foglio=x->value("foglio").toInt();
    int parti=x->value("parti").toInt();
    Terreno t(comune,foglio,parti,"",0.0);
    Record r(&t);
    Container<Record>::Iterator it=model->FindItem(r);
    view->updateView(model,it);
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
    model->AddItem(r);
    cout << "Inserimento riuscito! Ora nel container sono presenti " << model->Size() << " record" << endl;
}
