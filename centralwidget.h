#ifndef CENTRALWIDGET_H
#define CENTRALWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QRadioButton>
#include <QGridLayout>
#include <QGroupBox>
#include <QVBoxLayout>
#include <QHash>

class CentralWidget : public QWidget {
    Q_OBJECT
private:
    QHash<QString,QString>* hash;
    QLabel* comuneLabel;
    QLabel* foglioLabel;
    QLabel* partiLabel;
    QLabel* propLabel;
    QLabel* renditaLabel;
    QLabel* classeLabel;
    QLineEdit* comuneEdit;
    QLineEdit* foglioEdit;
    QLineEdit* partiEdit;
    QLineEdit* propEdit;
    QLineEdit* renditaEdit;
    QLineEdit* classeEdit;
    QRadioButton* primaCasa;
    QRadioButton* storico;
    QRadioButton* inagibile;
    void drawWidget();
public:
    explicit CentralWidget(QWidget* =0);
    void readOnly();
    QHash<QString,QString>* getFieldModified();
public slots:
    void newInsert();
    void modify();
};

#endif // CENTRALWIDGET_H
