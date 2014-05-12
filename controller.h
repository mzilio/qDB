#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QStringList>
#include <string>
#include "container.h"
#include "record.h"
#include "mainwindow.h"
#include "terreno.h"
#include <iostream>
using std::cout;
using std::endl;

class MainWindow;

class Controller {
private:
    Container<Record>* model;
    MainWindow* view;
public:
    Controller(Container<Record>*, MainWindow*);
    void searchRecord(QStringList);
};

#endif // CONTROLLER_H
