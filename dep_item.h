#pragma once
#include <QWidget>
#include <QLabel>
#include"dialog_changenum.h"
#include <QPushButton>
#include <QObject>

class dep_item : public QWidget
{
	Q_OBJECT
public:
	explicit dep_item(QWidget *parent = 0);
	
	void initUi();//初始化Ui
	QPushButton *dep_name;  //病房名字
	QLabel *num_zhuyuan1;  
	QLabel *num_zhuyuan;  
	QLabel *num_yanjiu;
	QLabel *num_guipei;
	QLabel *num_duanqi;
	QLabel *num_changqi;
    

	//总人数限制***************************
	int num_dep_max;
	int num_dep_min;



	void mouseDoubleClickEvent(QMouseEvent*);
	//void head->mouseDoubleClickEvent(QMouseEvent*);


signals:

public slots:
	//void jie();
};
