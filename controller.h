#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "container.h"
#include "record.h"
#include "mainwindow.h"

class Controller {
private:
    Container<Record>* model;
    MainWindow* view;

public:
    Controller(Container<Record>*, MainWindow*);
};

#endif // CONTROLLER_H
