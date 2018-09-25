#pragma once

#include <QDialog>
#include "ui_dialog_task.h"

class dialog_task : public QDialog
{
	Q_OBJECT

public:
	dialog_task(QWidget *parent = Q_NULLPTR);
	~dialog_task();
	void accept();
private:
	Ui::dialog_task ui;
};
