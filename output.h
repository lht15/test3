#pragma once

#include <QWidget>
#include "ui_output.h"

class output : public QWidget
{
	Q_OBJECT

public:
	output(QWidget *parent = Q_NULLPTR);
	~output();

public:
	Ui::output ui;
};
