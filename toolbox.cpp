
#include"mainwindow.h"
#include "toolbox.h"
#include "ui_toolbox.h"
#include "doc.h"
#include"doc_longterm.h"
#include <QAction>
#include <QIcon>
#include<qlistwidget.h>
#include<qlist.h>
#include"doc_longterm.h"

#include<QFile>
#include <QAxObject>
#include<qfileinfo.h>
#include<qfiledialog.h>
#include <QException>
#include<qstring.h>
#include"ui_mainwindow.h"
using namespace std;

ToolBox::ToolBox(QWidget *parent):
    QToolBox(parent),
    ui(new Ui::ToolBox)
{
	ui->setupUi(this);

	ui->listWidget->setGridSize(QSize(100, 100));

}

ToolBox::~ToolBox()
{
	delete ui;
}

void ToolBox::on_pushButton_clicked()//添加长期进修医生*******************
{
	
    doc_longterm*d1 = new doc_longterm();  
	number_1++;
    d1->head->setText(QString::fromLocal8Bit("待编辑"));
    d1->name->setText(QString::fromLocal8Bit("待编辑") +QString::number(number_1));
	d1->sign->setText(QString::fromLocal8Bit("长期进修医生"));
	d1->id = 1;
    d1->res=QString("");
    d1->tel = QString("");
    d1->choice.append(QString(""));
    d1->choice.append(QString(""));
    d1->choice.append(QString(""));
    d1->choice.append(QString(""));
    d1->choice.append(QString(""));

	for (int i = 0; i < 45; i++) {
		d1->task.append("0;0");
	}

	doc_group.append(d1);

    QListWidgetItem *newItem = new QListWidgetItem();     
	newItem->setSizeHint(QSize(100, 100));
	ui->listWidget->insertItem(ui->listWidget->count() + 1, newItem);
	ui->listWidget->setItemWidget(newItem, d1);

}

void ToolBox::on_pushButton_2_clicked() //添加短期进修医生*******************
{

	doc_longterm*d1 = new doc_longterm();
	number_1++;
	d1->head->setText(QString::fromLocal8Bit("待编辑"));
	d1->name->setText(QString::fromLocal8Bit("待编辑") + QString::number(number_1));
	d1->sign->setText(QString::fromLocal8Bit("短期进修医生"));
	d1->id = 1;
	d1->res = QString("");
	d1->tel = QString("");
	d1->choice.append(QString(""));
	d1->choice.append(QString(""));
	d1->choice.append(QString(""));
	d1->choice.append(QString(""));
	d1->choice.append(QString(""));

	for (int i = 0; i < 45; i++) {
		d1->task.append("0;0");
	}

	doc_group.append(d1);

    QListWidgetItem *newItem = new QListWidgetItem();
    newItem->setSizeHint(QSize(100, 100));
    ui->listWidget_2->insertItem(ui->listWidget_2->count() + 1, newItem); 
    ui->listWidget_2->setItemWidget(newItem, d1); 

}

void ToolBox::on_pushButton_3_clicked() //添加研究生*******************
{
	doc_longterm*d1 = new doc_longterm();
	number_1++;
	d1->head->setText(QString::fromLocal8Bit("待编辑"));
	d1->name->setText(QString::fromLocal8Bit("待编辑") + QString::number(number_1));
	d1->sign->setText(QString::fromLocal8Bit("研究生"));
	d1->id = 1;
	d1->res = QString("");
	d1->tel = QString("");
	d1->choice.append(QString(""));
	d1->choice.append(QString(""));
	d1->choice.append(QString(""));
	d1->choice.append(QString(""));
	d1->choice.append(QString(""));

	for (int i = 0; i < 45; i++) {
		d1->task.append("0;0");
	}

	doc_group.append(d1);


    QListWidgetItem *newItem = new QListWidgetItem();      
    newItem->setSizeHint(QSize(100, 100));
    ui->listWidget_3->insertItem(ui->listWidget_3->count() + 1, newItem);
    ui->listWidget_3->setItemWidget(newItem, d1);
}

void ToolBox::on_pushButton_4_clicked() //添加规培生*******************
{
	doc_longterm*d1 = new doc_longterm();
	number_1++;
	d1->head->setText(QString::fromLocal8Bit("待编辑"));
	d1->name->setText(QString::fromLocal8Bit("待编辑") + QString::number(number_1));
	d1->sign->setText(QString::fromLocal8Bit("规培生"));
	d1->id = 1;
	d1->res = QString("");
	d1->tel = QString("");
	d1->choice.append(QString(""));
	d1->choice.append(QString(""));
	d1->choice.append(QString(""));
	d1->choice.append(QString(""));
	d1->choice.append(QString(""));

	for (int i = 0; i < 45; i++) {
		d1->task.append("0;0");
	}

	doc_group.append(d1);

    QListWidgetItem *newItem = new QListWidgetItem();       
    newItem->setSizeHint(QSize(100, 100));
    ui->listWidget_4->insertItem(ui->listWidget_4->count() + 1, newItem); 
    ui->listWidget_4->setItemWidget(newItem, d1); 
}

void ToolBox::on_pushButton_5_clicked()//添加住院医*******************
{
	doc_longterm*d1 = new doc_longterm();
	number_1++;
	d1->head->setText(QString::fromLocal8Bit("待编辑"));
	d1->name->setText(QString::fromLocal8Bit("待编辑") + QString::number(number_1));
	d1->sign->setText(QString::fromLocal8Bit("住院医"));
	d1->id = 1;
	d1->res = QString("");
	d1->tel = QString("");
	d1->choice.append(QString(""));
	d1->choice.append(QString(""));
	d1->choice.append(QString(""));
	d1->choice.append(QString(""));
	d1->choice.append(QString(""));

	for (int i = 0; i < 45; i++) {
		d1->task.append("0;0");
	}

	doc_group.append(d1);
    QListWidgetItem *newItem = new QListWidgetItem();     
    newItem->setSizeHint(QSize(100, 100));
    ui->listWidget_5->insertItem(ui->listWidget_5->count() + 1, newItem); 
    ui->listWidget_5->setItemWidget(newItem, d1); 
}

void ToolBox::on_pushButton_12_clicked()//添加住院医一阶段*******************
{
	doc_longterm*d1 = new doc_longterm();
	number_1++;
	d1->head->setText(QString::fromLocal8Bit("待编辑"));
	d1->name->setText(QString::fromLocal8Bit("待编辑") + QString::number(number_1));
	d1->sign->setText(QString::fromLocal8Bit("住院医一阶段"));
	d1->id = 1;
	d1->res = QString("");
	d1->tel = QString("");
	d1->choice.append(QString(""));
	d1->choice.append(QString(""));
	d1->choice.append(QString(""));
	d1->choice.append(QString(""));
	d1->choice.append(QString(""));

	for (int i = 0; i < 45; i++) {
		d1->task.append("0;0");
	}

	doc_group.append(d1);
	QListWidgetItem *newItem = new QListWidgetItem();
	newItem->setSizeHint(QSize(100, 100));
	ui->listWidget_6->insertItem(ui->listWidget_6->count() + 1, newItem);
	ui->listWidget_6->setItemWidget(newItem, d1);
}


void ToolBox::on_pushButton_6_clicked()//删除长期进修医生***********************************
{
	int idex = ui->listWidget->currentRow() + 1;
	ui->listWidget->takeItem(ui->listWidget->currentRow());
	int cou = 0;
	for (int i = 0; i < doc_group.size(); i++) {
		if (doc_group[i]->sign->text() == QString::fromLocal8Bit("长期进修医生")) {
			cou++;
		}
		if (cou == idex) {
			doc_group.remove(i); break;
		}
	}
}

void ToolBox::on_pushButton_7_clicked()//删除短期进修医生***********************************
{
	int idex = ui->listWidget_2->currentRow() + 1;
	ui->listWidget_2->takeItem(ui->listWidget_2->currentRow());
	int cou = 0;
	for (int i = 0; i < doc_group.size(); i++) {
		if (doc_group[i]->sign->text() == QString::fromLocal8Bit("短期进修医生")) {
			cou++;
		}
		if (cou == idex) {
			doc_group.remove(i); break;
		}
	}
}

void ToolBox::on_pushButton_8_clicked()//删除研究生***********************************
{
	int idex = ui->listWidget_3->currentRow() + 1;
	ui->listWidget_3->takeItem(ui->listWidget_3->currentRow());
	int cou = 0;
	for (int i = 0; i < doc_group.size(); i++) {
		if (doc_group[i]->sign->text() == QString::fromLocal8Bit("研究生")) {
			cou++;
		}
		if (cou == idex) {
			doc_group.remove(i); break;
		}
	}
}

void ToolBox::on_pushButton_9_clicked()//删除规培生***********************************
{
	int idex = ui->listWidget_4->currentRow() + 1;
	ui->listWidget_4->takeItem(ui->listWidget_4->currentRow());
	int cou = 0;
	for (int i = 0; i < doc_group.size(); i++) {
		if (doc_group[i]->sign->text() == QString::fromLocal8Bit("规培生")) {
			cou++;
		}
		if (cou == idex) {
			doc_group.remove(i); break;
		}
	}
}

void ToolBox::on_pushButton_10_clicked()//删除住院医***********************************
{
	int idex = ui->listWidget_5->currentRow() + 1;
	ui->listWidget_5->takeItem(ui->listWidget_5->currentRow());
	int cou = 0;
	for (int i = 0; i < doc_group.size(); i++) {
		if (doc_group[i]->sign->text() == QString::fromLocal8Bit("住院医")) {
			cou++;
		}
		if (cou == idex) {
			doc_group.remove(i); break;
		}
	}
}

void ToolBox::on_pushButton_13_clicked()//删除住院医一阶段***********************************
{
	int idex = ui->listWidget_6->currentRow() + 1;
	ui->listWidget_6->takeItem(ui->listWidget_6->currentRow());
	int cou = 0;
	for (int i = 0; i < doc_group.size(); i++) {
		if (doc_group[i]->sign->text() == QString::fromLocal8Bit("住院医一阶段")) {
			cou++;
		}
		if (cou == idex) {
			doc_group.remove(i); break;
		}
	}
}


void ToolBox::on_pushButton_11_clicked()
{

	QAxObject excel("Excel.Application");
	excel.setProperty("Visible", false); 
	QAxObject *workbooks = excel.querySubObject("WorkBooks");

	QString file_full, file_name, file_path;
	QFileInfo fi;

	file_name = QFileDialog::getOpenFileName(this, "", "", "*.xlsx");

	if (file_name.size() > 1) {
		QAxObject *workbook = workbooks->querySubObject("Open(QString, QVariant)", file_name); 
		QAxObject * worksheet = workbook->querySubObject("WorkSheets(int)", 1); 
		QAxObject * usedrange = worksheet->querySubObject("UsedRange");
		QAxObject * rows = usedrange->querySubObject("Rows");
		QAxObject *columns = usedrange->querySubObject("Columns");
		int intRows = rows->property("Count").toInt();
		int intcolumn = columns->property("Count").toInt();

		QVariant allEnvDataQVariant = rows->property("Value");
		QVariantList allEnvDataList = allEnvDataQVariant.toList();

		for (int i = 1; i < intRows; i++)
		{
			QVariantList allEnvDataList_i = allEnvDataList[i].toList();
			int s = allEnvDataList_i.size();

			doc_longterm * d1 = new doc_longterm();

			d1->name->setText(allEnvDataList_i[0].toString());
			d1->sign->setText(allEnvDataList_i[2].toString());
			d1->head->setText(allEnvDataList_i[0].toString());
			d1->res = allEnvDataList_i[3].toString();
			d1->tel = allEnvDataList_i[4].toString();
			d1->choice.append(allEnvDataList_i[5].toString());
			d1->choice.append(allEnvDataList_i[6].toString());
			d1->choice.append(allEnvDataList_i[7].toString());
			d1->choice.append(allEnvDataList_i[8].toString());
			d1->choice.append(allEnvDataList_i[9].toString());
			d1->task.append(allEnvDataList_i[10].toString());
			d1->task.append(allEnvDataList_i[11].toString());
			d1->task.append(allEnvDataList_i[12].toString());
			d1->task.append(allEnvDataList_i[13].toString());
			d1->task.append(allEnvDataList_i[14].toString());
			d1->task.append(allEnvDataList_i[15].toString());
			d1->task.append(allEnvDataList_i[16].toString());
			d1->task.append(allEnvDataList_i[17].toString());
			d1->task.append(allEnvDataList_i[18].toString());
			d1->task.append(allEnvDataList_i[19].toString());


			QListWidgetItem * newItem1 = new QListWidgetItem();
			newItem1->setSizeHint(QSize(100, 100));

            if (d1->sign->text() == QString("长期进修医生")) {
				ui->listWidget->insertItem(ui->listWidget->count() + 1, newItem1);
				ui->listWidget->setItemWidget(newItem1, d1);
			}
			else if (d1->sign->text() == QString("短期进修医生")) {
				ui->listWidget_2->insertItem(ui->listWidget_2->count() + 1, newItem1);
				ui->listWidget_2->setItemWidget(newItem1, d1);
			}
			else if (d1->sign->text() == QString("研究生")) {
				ui->listWidget_3->insertItem(ui->listWidget_3->count() + 1, newItem1);
				ui->listWidget_3->setItemWidget(newItem1, d1);
			}
			else if (d1->sign->text() == QString("规培生")) {
				ui->listWidget_4->insertItem(ui->listWidget_4->count() + 1, newItem1);
				ui->listWidget_4->setItemWidget(newItem1, d1);
			}
			else  {
				ui->listWidget_5->insertItem(ui->listWidget_5->count() + 1, newItem1);
				ui->listWidget_5->setItemWidget(newItem1, d1);
			}
		}

		workbooks->dynamicCall("Close()");
		excel.dynamicCall("Quit()");
	}
	else {

		
	}

}
