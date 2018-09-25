#include "dialog_task.h"
#include"taskitem.h"

dialog_task::dialog_task(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	
}

dialog_task::~dialog_task()
{

}

void dialog_task::accept() {
	taskitem*p = (taskitem*)parentWidget();
	if (ui.lineEdit->text() != "") { p->mon_done->setText(ui.lineEdit->text()); }
	if (ui.lineEdit_2->text() != "") { p->mon_order->setText(ui.lineEdit_2->text()); }
	
	QDialog::accept();
}
