#ifndef SEARCHDIALOG_H
#define SEARCHDIALOG_H

#include <QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QGridLayout>
#include <QValidator>

class SearchDialog : public QDialog {
    Q_OBJECT
private:
    QWidget* mainWindow;
    QHash<QString,QString>* hash;
    QLabel* comuneLabel;
    QLabel* foglioLabel;
    QLabel* partiLabel;
    QLineEdit* comuneEdit;
    QLineEdit* foglioEdit;
    QLineEdit* partiEdit;
    QPushButton* search;
    QPushButton* cancel;
    void connectSignalSlot();
public:
    explicit SearchDialog(QWidget* =0);
    QHash<QString,QString>* sendDataSearch();
};

#endif // SEARCHDIALOG_H
