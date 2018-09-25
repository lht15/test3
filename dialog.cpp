#include "dialog.h"
#include "ui_dialog.h"
#include "doc_longterm.h"
#include<dialog.h>
#include"ui_dialog.h"

#include "mainwindow.h"
#include "ui_mainwindow.h"
Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}


QString depart = QString::fromLocal8Bit("青光眼东;外伤东;眼底东;白内障东;东一日综;东一日白;整形东;眼肌东;青光眼西;外伤西;角膜西;门诊手术室西;一日病房西;眼肌西;眼肌检查;眼肌弱视专台;白内障南;外伤南;角膜南;眼底南;葡萄膜炎南;一日病房南;肿瘤南;整形南;西区FFA;东区FFA;南区FFA;门诊轮换人员;门诊普通号;东西区住院总;南区住院总;屈光中心;视光学;门诊专家;二线;门诊组长;其它;其他;神内;内分泌;门诊;南区急诊;脱产;中心申报;治疗室");


void Dialog::insert_task(QVector<QString> tsk){
    int len=tsk.size();
    QStringList listdep = depart.split(";");
    for(int i =0;i<len;i++){
        QStringList listtsk = tsk[i].split(";");
        //if(listtsk[1]!= QString::fromLocal8Bit("0") && listtsk[0]==listtsk[1])
		if (listtsk[0] >= listtsk[1])
        {
            taskitem*ti=new taskitem(listdep[i],tsk[i]);
			task_group.append(ti);
            QListWidgetItem *newItem = new QListWidgetItem();       //创建一个newItem
            newItem->setSizeHint(QSize(100,100));
            ui->listWidget->insertItem(ui->listWidget->count() + 1,newItem); //将该newItem插入到后面
            ui->listWidget->setItemWidget(newItem, ti); //将buddy赋给该newItem
        }
        //else if(listtsk[1]!= QString::fromLocal8Bit("0"))
		else
        {
            taskitem*ti=new taskitem(listdep[i],tsk[i]);
			task_group.append(ti);
            QListWidgetItem *newItem = new QListWidgetItem();       //创建一个newItem
            newItem->setSizeHint(QSize(100,100));
            ui->listWidget_2->insertItem(ui->listWidget->count() + 1,newItem); //将该newItem插入到后面
            ui->listWidget_2->setItemWidget(newItem, ti); //将buddy赋给该newItem
        }
    }
}

void Dialog::accept(){
  doc_longterm*p=(doc_longterm*)parentWidget();
  p->head->setText(ui->lineEdit->text());
  p->tel=ui->lineEdit_8->text();
  p->name->setText(p->tel);
  p->sign->setText(ui->lineEdit_2->text());
  p->task.clear();
  for (int i = 0; i < task_group.size(); i++) {
	  p->task.append(task_group[i]->mon_done->text()+";"+ task_group[i]->mon_order->text());
  }
  p->choice.clear();
  p->choice.append(ui->lineEdit_3->text());
  p->choice.append(ui->lineEdit_4->text());
  p->choice.append(ui->lineEdit_5->text());
  p->choice.append(ui->lineEdit_6->text());
  p->choice.append(ui->lineEdit_7->text());

  //for (int i = 0; i < task_group.size(); i++) {
	 // delete task_group[i];
  //}
    QDialog::accept();
}
