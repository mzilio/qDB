#include <QApplication>
#include "mainwindow.h"
#include "container.h"
#include "record.h"
#include "controller.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    MainWindow view;
    Container<Record> model;
    Controller controller(&model,&view);
    return app.exec();
}
