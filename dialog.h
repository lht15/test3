#ifndef DIALOG_H
#define DIALOG_H
#include<taskitem.h>
#include <QDialog>

//#include"doc_longterm.h"
//#include"doc.h"
//#include "var.h"
namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();
	
    void insert_task(QVector<QString>);
	QList<taskitem*> task_group;
public:
    Ui::Dialog *ui;
    void accept();
};

#endif // DIALOG_H
