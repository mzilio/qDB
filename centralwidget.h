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
#include <QValidator>

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
    QGroupBox* box1;
    QGroupBox* box2;
    void drawWidget();
    void setValidator();
public:
    explicit CentralWidget(QWidget* =0);
    QHash<QString,QString>* getFieldModified();
    void updateField(bool,QString,QString,QString,QString,QString,QString,bool,bool,bool);
    void clear();
    void lock() const;
    void unlock() const;
    bool haveNewData() const;
    void newInsert();
public slots:
    void modify();
};

#endif // CENTRALWIDGET_H
