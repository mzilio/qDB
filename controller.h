#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <string>
#include "container.h"
#include "record.h"
#include "mainwindow.h"
#include "fabbricato.h"
#include "terreno.h"
#include <iostream>
using std::cout;
using std::endl;

class MainWindow;

class Controller {
private:
    Container<Record>* model;
    MainWindow* view;
    Record* actualRecord;
public:
    Controller(Container<Record>*, MainWindow*);
    void searchRecord(QHash<QString,QString>*);
    void insertRecord(QHash<QString,QString>*);
    Record* getActualRecord();
};

#endif // CONTROLLER_H
