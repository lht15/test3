#include "taskitem.h"

taskitem::taskitem(QString dep1,QString mon)
{
 initUi(dep1,mon);
}


//初始化Ui
void taskitem::initUi(QString dep1,QString mon)
{
    //初始化
    dep=new QPushButton(this);

    mon_done=new QLabel(this);
    mon_order=new QLabel(this);
    //设置部门大小
   dep->setFixedSize(150,30);
   dep->setText(dep1);
    //设置task
    QStringList list1 = mon.split(";");
    QPalette color;
    color.setColor(QPalette::Text,Qt::red);
    mon_done->setPalette(color);
    mon_done->setText(list1[0]);
    mon_order->setText(list1[1]);
    //布局
   dep->move(7,7);
   mon_done->move(154,30);
    mon_order->move(254,27);

}

void taskitem::mouseDoubleClickEvent(QMouseEvent* event) {
	dialog_task*dt;
	dt = new dialog_task(this);
	dt->show();

}