#include "doc_longterm.h"
#include<dialog.h>
#include"ui_dialog.h"

doc_longterm::doc_longterm()
{

    QPalette color;
    color.setColor(QPalette::Text,Qt::red);
    sign->setPalette(color);
}


/*
doc_longterm::doc_longterm(QString head1,QString name1,QString sign1,int id1,QList*res1,QString tel1,QList*choice1){

    QPalette color;
    color.setColor(QPalette::Text,Qt::yellow);
    sign->setPalette(color);

    head->setText(head1);
name->setText(name1);
sign->setText(sign1);
id=id1;
res=
}
*/

void doc_longterm::mouseDoubleClickEvent(QMouseEvent* event)
{
    Dialog*dl;
    dl=new Dialog(this);

    dl->ui->lineEdit->setText(head->text());
    dl->ui->lineEdit_2->setText(sign->text());
    dl->ui->lineEdit_3->setText(choice[0]);
    dl->ui->lineEdit_4->setText(choice[1]);
    dl->ui->lineEdit_5->setText(choice[2]);
    dl->ui->lineEdit_6->setText(choice[3]);
    dl->ui->lineEdit_7->setText(choice[4]);
    dl->ui->lineEdit_8->setText(tel);
    dl->ui->lineEdit_9->setText(res);

    dl->insert_task(task);
    dl->setWindowTitle(head->text());

    dl->show();

}
