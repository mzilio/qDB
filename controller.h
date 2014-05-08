#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include "container.h"
#include "record.h"
#include "mainwindow.h"

class MainWindow;

class Controller {
private:
    Container<Record>* model;
    MainWindow* view;
public:
    Controller(Container<Record>*, MainWindow*);
};

#endif // CONTROLLER_H
