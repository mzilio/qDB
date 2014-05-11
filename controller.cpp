#include "controller.h"

Controller::Controller(Container<Record>* m, MainWindow* v): model(m), view(v) {
    v->show();
}

void Controller::searchRecord(QStringList x) {
    string comune="";
    int foglio=0, particella=0;
    for (int i=0; i<3; i++) {
        QString tmp=x.front();
        x.pop_front();
        if (i==0)
            comune=tmp.toStdString();
        else if (i==1)
            foglio=tmp.toInt();
        else if (i==2)
            particella=tmp.toInt();
    }
    try {
        Terreno* t=new Terreno(comune,foglio,particella,"",0.0);
        Record* r=new Record(t);
        Container<Record>::Iterator it=model->FindItem(*r);
    }
    catch (Error e) {
        cout << e.getError();
    }
}
