#ifndef HARD_CONSTRAINT_H
#define HARD_CONSTRAINT_H

#include<dialog.h>
#include <QWidget>
#include <QLabel>
#include <QEvent>
#include <QPushButton>
//自定义信息Item类
class hard_constraint : public QWidget
{
    Q_OBJECT
public:
   hard_constraint();

   void initUi();//初始化Ui
    QPushButton *department;  //科室
    QPushButton *doctor;  //医生
    QLabel* txt;

	int idx_dep;
	int idx_doc;

   // void mouseDoubleClickEvent(QMouseEvent*);


signals:

public slots:


};


#endif // HARD_CONSTRAINT_H
