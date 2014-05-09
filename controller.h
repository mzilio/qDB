#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QStringList>
#include "container.h"
#include "record.h"
#include "mainwindow.h"
#include <iostream>
using std::cout;

class MainWindow;

class Controller {
private:
    Container<Record>* model;
    MainWindow* view;
public:
    Controller(Container<Record>*, MainWindow*);
    void stampa();
};

#endif // CONTROLLER_H
