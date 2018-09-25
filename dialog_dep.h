#pragma once

#include <QWidget>
#include "ui_dialog_dep.h"
#include"dep_item.h"
class dialog_dep : public QWidget
{
	Q_OBJECT

public:
	dialog_dep(QWidget *parent = Q_NULLPTR);
	~dialog_dep();
	QList<dep_item*>department_group;
public:
	Ui::dialog_dep ui;

private slots:
	void on_pushButton_clicked();
};
