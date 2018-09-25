#ifndef TASKITEM_H
#define TASKITEM_H
//#include<dialog.h>
#include <QWidget>
#include <QLabel>
#include <QEvent>
#include <QPushButton>
#include"dialog_task.h"
class taskitem:public QWidget
{
     Q_OBJECT
public:
    taskitem();
    taskitem(QString dep1,QString mon);
    void initUi(QString dep1, QString mon);//初始化Ui
    QPushButton *dep;  //部门
    QLabel *mon_done;  //用户名
    QLabel *mon_order;  //个性签

    void mouseDoubleClickEvent(QMouseEvent*);
};

#endif // TASKITEM_H
