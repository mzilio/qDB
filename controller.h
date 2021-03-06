#ifndef CONTROLLER_H
#define CONTROLLER_H
#include "mainwindow.h"
#include "container.h"
#include "record.h"
#include "fabbricato.h"
#include "terreno.h"
#include <QXmlStreamReader>
#include <QXmlStreamWriter>
#include <string>
using std::string;

class MainWindow;

class Controller {
private:
    Container<Record>* model;
    MainWindow* view;
    Record* actualRecord;
    void emptyModel();
public:
    Controller(Container<Record>*, MainWindow*);
    Record* getActualRecord() const;
    void resetActualRecord();
    void newFile();
    void openFile(const QString&);
    void saveFile(const QString&);
    void searchRecord(QHash<QString,QString>*);
    void insertRecord(QHash<QString,QString>*);
    void modifyRecord(QHash<QString,QString>*);
    void deleteRecord();
};

#endif // CONTROLLER_H