#ifndef SEARCHDIALOG_H
#define SEARCHDIALOG_H

#include <QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QGridLayout>
#include "controller.h"

class Controller;

class SearchDialog : public QDialog {
    Q_OBJECT
private:
    Controller* controller;
    QLabel* comuneLabel;
    QLabel* foglioLabel;
    QLabel* partiLabel;
    QLineEdit* comuneEdit;
    QLineEdit* foglioEdit;
    QLineEdit* partiEdit;
    QPushButton* search;
    QPushButton* cancel;
    void connectSignalSlot();
private slots:
    void startSearch();
public:
    explicit SearchDialog(Controller*, QWidget* = 0);
};

#endif // SEARCHDIALOG_H
