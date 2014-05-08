#include <QApplication>
#include "container.h"
#include "record.h"
#include "controller.h"
#include "centralwidget.h"
#include "mainwindow.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    Container<Record> model;
    MainWindow view;
    Controller controller(&model,&view);
    return a.exec();
}
