#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <string>
#include "container.h"
#include "record.h"
#include "mainwindow.h"
#include "fabbricato.h"
#include "terreno.h"

class MainWindow;

class Controller {
private:
    Container<Record>* model;
    MainWindow* view;
    Record* actualRecord;
public:
    Controller(Container<Record>*, MainWindow*);
    Record* getActualRecord() const;
    void searchRecord(QHash<QString,QString>*);
    void insertRecord(QHash<QString,QString>*);
    void deleteRecord();
};

#endif // CONTROLLER_H
