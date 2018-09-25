#include "dialog_dep.h"

dialog_dep::dialog_dep(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
}

dialog_dep::~dialog_dep()
{
}

void dialog_dep::on_pushButton_clicked() {


	this->close();


}