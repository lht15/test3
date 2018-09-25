#include "dep_item.h"


dep_item::dep_item(QWidget *parent) :
	QWidget(parent)
{
	initUi();
}

//初始化Ui
void dep_item::initUi()
{
	//初始化
	dep_name = new QPushButton(this);
	num_zhuyuan1 = new QLabel(this);
	num_zhuyuan= new QLabel(this);
	num_yanjiu = new QLabel(this);
	num_guipei = new QLabel(this);
	num_changqi = new QLabel(this);
	num_duanqi = new QLabel(this);
	
	//设置头像大小
	dep_name->setFixedSize(150, 30);
	num_zhuyuan1->setFixedSize(50, 30);
	num_zhuyuan->setFixedSize(50, 30);
	num_yanjiu->setFixedSize(50, 30);
	num_guipei->setFixedSize(50, 30);
	num_changqi->setFixedSize(50, 30);
	num_duanqi->setFixedSize(50, 30);
	
	//设置个性签名字体为灰色
	QPalette color;
	color.setColor(QPalette::Text, Qt::red);
	dep_name->setPalette(color);
	//布局
	dep_name->move(7, 7);
	num_zhuyuan1->move(50, 50);
	num_zhuyuan->move(100, 50);
	num_yanjiu->move(150, 50);
	num_guipei->move(200, 50);
	num_changqi->move(250, 50);
	num_duanqi->move(300, 50);

	//connect(this->head, SIGNAL(clicked(bool)), this, SLOT(jie()));
}


void dep_item::mouseDoubleClickEvent(QMouseEvent* event) {

	dialog_changenum*dc;
	dc = new dialog_changenum(this);

	dc->ui.lineEdit->setText(num_zhuyuan1->text());
	dc->ui.lineEdit_2->setText(num_zhuyuan->text());
	dc->ui.lineEdit_3->setText(num_yanjiu->text());
	dc->ui.lineEdit_4->setText(num_guipei->text());
	dc->ui.lineEdit_5->setText(num_changqi->text());
	dc->ui.lineEdit_6->setText(num_duanqi->text());
	 
	dc->show();

}