#ifndef ASKDATABASE_H
#define ASKDATABASE_H

#include <QMainWindow>
#include <QString>
#include <QtGui>

namespace Ui {
    class AskDataBase;
}

class AskDataBase : public QMainWindow
{
    Q_OBJECT

public:
    explicit AskDataBase(QWidget *parent = 0);
    ~AskDataBase();

private:
    Ui::AskDataBase *ui;
    void CreationCarte();
    QString filename;
private slots:
    void SelectFile(void);
    void CreateFile(void);
    void ValidateFile(void);


};

#endif // ASKDATABASE_H
