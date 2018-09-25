#pragma once

#include <QDialog>
#include "ui_dialog_changenum.h"

class dialog_changenum : public QDialog
{
	Q_OBJECT

public:
	dialog_changenum(QWidget *parent = Q_NULLPTR);
	~dialog_changenum();

public:
	Ui::dialog_changenum ui;

	void accept();
};
