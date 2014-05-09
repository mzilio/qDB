#include <QApplication>
#include "container.h"
#include "record.h"
#include "mainwindow.h"
#include "controller.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    Container<Record> model;
    MainWindow view;
    Controller controller(&model,&view);
    view.setController(&controller);
    return a.exec();
}
