#include "dialog_changenum.h"
#include"dep_item.h"
dialog_changenum::dialog_changenum(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
}

dialog_changenum::~dialog_changenum()
{
}
void dialog_changenum::accept() {
	dep_item*p = (dep_item*)parentWidget();
	p->num_zhuyuan1->setText(ui.lineEdit->text());
	p->num_zhuyuan->setText(ui.lineEdit_2->text());
	p->num_yanjiu->setText(ui.lineEdit_3->text());
	p->num_guipei->setText(ui.lineEdit_4->text());
	p->num_changqi->setText(ui.lineEdit_5->text());
	p->num_duanqi->setText(ui.lineEdit_6->text());

	QDialog::accept();
}
