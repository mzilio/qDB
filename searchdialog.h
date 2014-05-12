#ifndef SEARCHDIALOG_H
#define SEARCHDIALOG_H

#include <QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QGridLayout>

class SearchDialog : public QDialog {
    Q_OBJECT
private:
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
};

#endif // SEARCHDIALOG_H
