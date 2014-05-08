#include "controller.h"

Controller::Controller(Container<Record>* m, MainWindow* v): model(m), view(v) {
    v->show();
}
