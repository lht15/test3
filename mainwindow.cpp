#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "toolbox.h"
#include "ui_toolbox.h"
#include "doclist.h"
#include "doc.h"
#include"doc_longterm.h"
#include "doc.h"
#include <QAction>
#include <QIcon>
#include<dialog.h>
#include"hard_constraint.h"

#include<QFile>
#include <QAxObject>
#include<qfileinfo.h>
#include<qfiledialog.h>
#include<QListWidget>
#include<qlist.h>
#include<qstring.h>
#include <ilcplex/ilocplex.h>
#include <iostream>  
#include <string> 

#include <QtGlobal>
#include<QProgressDialog>
#include<QDateTime>
#include<QTime>
#include "ui_output.h"
#include "output.h"
using namespace std;
ILOSTLBEGIN
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    tlb=new ToolBox();
	dlgd = new dialog_dep();
	//IloEnv env;
//	model = IloModel(env);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete tlb;
	delete dlgd;
}

void MainWindow::on_pushButton_clicked()
{
    tlb->show();
    tlb->setCurrentIndex(0);
}

void MainWindow::on_pushButton_3_clicked()
{
    hard_constraint*hc=new hard_constraint();
	hc->doctor->setText(ui->comboBox->currentText());  
	hc->idx_doc = ui->comboBox->currentIndex();
    hc->department->setText(ui->comboBox_2->currentText());
	hc->idx_dep = ui->comboBox_2->currentIndex();
    hc->txt->setText(QString::fromLocal8Bit("避免"));
    QListWidgetItem *newItem = new QListWidgetItem();      
    newItem->setSizeHint(QSize(100, 100));
    ui->listWidget->insertItem(ui->listWidget->count() + 1, newItem);
    ui->listWidget->setItemWidget(newItem, hc); 
	lea_avoid.append(hc);

}

void MainWindow::on_pushButton_4_clicked()
{
    hard_constraint*hc=new hard_constraint();
    hc->doctor->setText(ui->comboBox_3->currentText());
	hc->idx_doc = ui->comboBox_3->currentIndex();
    hc->department->setText(ui->comboBox_4->currentText());
	hc->idx_dep = ui->comboBox_4->currentIndex();
    hc->txt->setText(QString::fromLocal8Bit("指派"));
    QListWidgetItem *newItem = new QListWidgetItem();    
    newItem->setSizeHint(QSize(100, 100));
    ui->listWidget_2->insertItem(ui->listWidget_2->count() + 1, newItem); 
    ui->listWidget_2->setItemWidget(newItem, hc); 
	lea_must.append(hc);
}

void MainWindow::on_pushButton_6_clicked()
{
	lea_avoid.removeAt(ui->listWidget->currentRow());
	ui->listWidget->takeItem(ui->listWidget->currentRow());
}

void MainWindow::on_pushButton_7_clicked()
{
	lea_must.removeAt(ui->listWidget_2->currentRow());
	ui->listWidget_2->takeItem(ui->listWidget_2->currentRow());
}


void MainWindow::addc(QString str)
{
	ui->comboBox->addItem(str);
}

void MainWindow::on_pushButton_5_clicked()
{
	delete tlb;
	tlb = new ToolBox();
	excel_dep.clear();
	excel_doc.clear();
	ui->comboBox->clear();
	ui->comboBox_2->clear();
	ui->comboBox_3->clear();
	ui->comboBox_4->clear();

	QString file_full, file_name, file_path;
	QFileInfo fi;

	file_name = QFileDialog::getOpenFileName(this, "", "", "*.xlsx");


	/*
	output*op4 = new output();
	for (int i = 0; i <sizeof(dep_equ)/ sizeof(dep_equ[0]); i++) {
		for (int j = 1; j <=dep_equ[i][0]; j++) {
			op4->ui.textBrowser->insertPlainText(QString::number(dep_equ[i][j]) + " ");
		}
		op4->ui.textBrowser->insertPlainText("\n");
	}
	op4->show();
	*/

    QAxObject excel("Excel.Application");
	//QAxObject *excel = new QAxObject(this);
	//excel->setControl("Excel.Application");//连接Excel控件
    excel.setProperty("Visible", false);
    QAxObject *workbooks = excel.querySubObject("WorkBooks");
	
    //file_name = QFileDialog::getOpenFileName(this, "", "", "*.xlsx");
	//file_path = QFileDialog::getExistingDirectory(this, "", "");
    if (file_name.size() > 1) {
        QAxObject *workbook = workbooks->querySubObject("Open(QString, QVariant)", file_name);
        QAxObject * worksheet = workbook->querySubObject("WorkSheets(int)", 1);
        QAxObject * usedrange = worksheet->querySubObject("UsedRange");
        QAxObject * rows = usedrange->querySubObject("Rows");
        QAxObject *columns = usedrange->querySubObject("Columns");
        int intRows = rows->property("Count").toInt();
        int intcolumn = columns->property("Count").toInt();
		
		//QAxObject *work_sheets = workbook->querySubObject("Sheets");  //Sheets也可换用WorkSheets
		//int sheet_count = work_sheets->property("Count").toInt();  //获取工作表数目
	
	//新建文件*************************************************************
	/*	workbooks->dynamicCall("Add"); // 新建一个工作簿
	    QAxObject* workbook2 = excel.querySubObject("ActiveWorkBook"); // 获取当前工作簿
		QAxObject *worksheets2 = workbook2->querySubObject("Sheets");//获取工作表集合
		QAxObject *worksheet2 = worksheets2->querySubObject("Item(int)", 1);//获取工作表集合的工作表1，即sheet1

		QAxObject *cell = worksheet2->querySubObject("Cells(int,int)", 2, 2);
		cell->setProperty("Value", "Java C++ C# PHP Perl Python Delphi Ruby");  //设置单元格值
	
		QString fileName = QFileDialog::getSaveFileName(this, QString::fromLocal8Bit("保存文件"), ".",tr("EXCEL(*.xlsx)"));
		workbook2->dynamicCall("SaveAs(const QString&)", QDir::toNativeSeparators(fileName));
		workbook2->dynamicCall("Close()");//关闭工作簿
				
		int i9 = 0;
		*/
	//建立医生矩阵******************************************************
		/*done = IloArray<IloIntArray>(env, intRows - 1);
		req = IloArray<IloIntArray>(env, intRows - 1);
		doc_choice = IloArray<IloIntArray>(env, intRows - 1);

		for (int ii = 0; ii < intRows - 1; ii++) {
			done[ii] = IloIntArray(env, intcolumn-10);
			req[ii] = IloIntArray(env, intcolumn - 10);
			doc_choice[ii] = IloIntArray(env, intcolumn - 10);
		}*/
		var_row = intRows - 1;
		var_col = intcolumn - 10;

		//doc_type= IloIntArray(env, var_row); //医生类型*************
    //***************************************************************
		
        QVariant allEnvDataQVariant = rows->property("Value");
        QVariantList allEnvDataList = allEnvDataQVariant.toList();

        QVariantList allEnvDataList_0 = allEnvDataList[0].toList();
		
        for (int i = 10; i < intcolumn; i++)
        {
            ui->comboBox_2->addItem(allEnvDataList_0[i].toString());
            ui->comboBox_4->addItem(allEnvDataList_0[i].toString());
			excel_dep.append(allEnvDataList_0[i].toString());
        }
        for (int i = 1; i < intRows; i++)
        {
            QVariantList allEnvDataList_i = allEnvDataList[i].toList();
            int s = allEnvDataList_i.size();

            ui->comboBox->addItem(allEnvDataList_i[0].toString());
            ui->comboBox_3->addItem(allEnvDataList_i[0].toString());

            doc_longterm * d1 = new doc_longterm();
			excel_doc.append(allEnvDataList_i[0].toString());
            d1->name->setText(allEnvDataList_i[4].toString());
            d1->sign->setText(allEnvDataList_i[2].toString());//类型

			/*if (allEnvDataList_i[2].toString() == QString::fromLocal8Bit("住院医一阶段")) {
				doc_type[i - 1] = 1;
			}
			else if (allEnvDataList_i[2].toString() == QString::fromLocal8Bit("住院医")) {
				doc_type[i - 1] = 2;
			}
			else if (allEnvDataList_i[2].toString() == QString::fromLocal8Bit("研究生")) {
				doc_type[i - 1] = 3;
			}
			else if (allEnvDataList_i[2].toString() == QString::fromLocal8Bit("规培生")) {
				doc_type[i - 1] = 4;
			}
			else if (allEnvDataList_i[2].toString() == QString::fromLocal8Bit("长期进修医生")) {
				doc_type[i - 1] = 5;
			}
			else {
				doc_type[i - 1] = 6;		
			}*/

            d1->head->setText(allEnvDataList_i[0].toString());//名字
            d1->res = allEnvDataList_i[3].toString();
            d1->tel = allEnvDataList_i[4].toString();
			d1->id = allEnvDataList_i[1].toInt();
            d1->choice.append(allEnvDataList_i[5].toString());
            d1->choice.append(allEnvDataList_i[6].toString());
            d1->choice.append(allEnvDataList_i[7].toString());
            d1->choice.append(allEnvDataList_i[8].toString());
            d1->choice.append(allEnvDataList_i[9].toString());
            
	//填充矩阵********************************************************************************	
			int k;
			for (int j = 10, k=0; j <intcolumn; j++,k++) {
				d1->task.append(allEnvDataList_i[j].toString());
				QStringList dr = allEnvDataList_i[j].toString().split(";");
				//done[i-1][k] = dr[0].toInt();
				//req[i-1][k] = dr[1].toInt();
			}
			//填充志愿矩阵********************
			/*for (int j = 5; j < 10; j++) {
				int ed = excel_dep.indexOf(allEnvDataList_i[j].toString());
				if (ed >= 0) {
					if (j == 5) { doc_choice[i - 1][ed] = -1000000; }
					else if (j == 6) { doc_choice[i - 1][ed] = -8; }
					else if (j == 7) { doc_choice[i - 1][ed] = -5; }
					else if (j == 8) { doc_choice[i - 1][ed] = -3; }
					else { doc_choice[i - 1][ed] = -1; }
				}
			}*/
    //**************************************************************************************

            QListWidgetItem * newItem1 = new QListWidgetItem();
            newItem1->setSizeHint(QSize(100, 100));
			
			tlb->doc_group.append(d1);//插入医生指针表*********

            if (d1->sign->text()== QString::fromLocal8Bit("长期进修医生")) {
                tlb->ui->listWidget->insertItem(tlb->ui->listWidget->count() + 1, newItem1);
                tlb->ui->listWidget->setItemWidget(newItem1, d1);
            }
            else if (d1->sign->text() == QString::fromLocal8Bit("短期进修医生")) {
		
                tlb->ui->listWidget_2->insertItem(tlb->ui->listWidget_2->count() + 1, newItem1);
                tlb->ui->listWidget_2->setItemWidget(newItem1, d1);
            }
            else if (d1->sign->text() == QString::fromLocal8Bit("研究生")) {
                tlb->ui->listWidget_3->insertItem(tlb->ui->listWidget_3->count() + 1, newItem1);
                tlb->ui->listWidget_3->setItemWidget(newItem1, d1);
            }
            else if (d1->sign->text() == QString::fromLocal8Bit("规培生")) {
                tlb->ui->listWidget_4->insertItem(tlb->ui->listWidget_4->count() + 1, newItem1);
                tlb->ui->listWidget_4->setItemWidget(newItem1, d1);
            }
			else if (d1->sign->text() == QString::fromLocal8Bit("住院医")) {
				tlb->ui->listWidget_5->insertItem(tlb->ui->listWidget_5->count() + 1, newItem1);
				tlb->ui->listWidget_5->setItemWidget(newItem1, d1);
			}
            else  {
                tlb->ui->listWidget_6->insertItem(tlb->ui->listWidget_6->count() + 1, newItem1);
                tlb->ui->listWidget_6->setItemWidget(newItem1, d1);
            }
			
        }

	//读入病房信息************************************************************
		QAxObject * worksheet2 = workbook->querySubObject("WorkSheets(int)", 2);
		QAxObject * usedrange2 = worksheet2->querySubObject("UsedRange");
		QAxObject * rows2 = usedrange2->querySubObject("Rows");
		QAxObject *columns2 = usedrange2->querySubObject("Columns");
		int intRows2 = rows2->property("Count").toInt();
		int intcolumn2 = columns2->property("Count").toInt();
		
		QVariant allEnvDataQVariant2 = rows2->property("Value");
		QVariantList allEnvDataList2 = allEnvDataQVariant2.toList();

		//建立病房矩阵******************************************************
		/*dep = IloArray<IloIntArray>(env, intRows2 - 1);
		

		for (int ii = 0; ii < intRows2 - 1; ii++) {
			dep[ii] = IloIntArray(env, intcolumn2 - 1);
		}*/
		dep_row = intRows2-1;
		dep_col = intcolumn2 - 1;
		//***************************************************************

		for (int i = 1; i < intRows2; i++)
		{
			QVariantList allEnvDataList2_i = allEnvDataList2[i].toList();

			dep_item *dep1 = new dep_item();
			dep1->dep_name->setText(allEnvDataList2_i[0].toString());
			dep1->num_zhuyuan1->setText(allEnvDataList2_i[1].toString());
			dep1->num_zhuyuan->setText(allEnvDataList2_i[2].toString());
			dep1->num_yanjiu->setText(allEnvDataList2_i[3].toString());
			dep1->num_guipei->setText(allEnvDataList2_i[4].toString());
			dep1->num_changqi->setText(allEnvDataList2_i[5].toString());
			dep1->num_duanqi->setText(allEnvDataList2_i[6].toString());
			//读入总人数限制***********************
			dep1->num_dep_max=allEnvDataList2_i[7].toInt();
			dep1->num_dep_min = allEnvDataList2_i[8].toInt();



			tlb->dep_group.append(dep1);
			dlgd->department_group.append(dep1);

			QListWidgetItem * newItem2 = new QListWidgetItem();
			newItem2->setSizeHint(QSize(100, 100));
		
			dlgd->ui.listWidget->insertItem(dlgd->ui.listWidget->count() + 1, newItem2);
			dlgd->ui.listWidget->setItemWidget(newItem2, dep1);
		
			//填充病房矩阵*************************************************************
			/*for (int j = 1; j <= dep_col; j++) {
				dep[i - 1][j-1] = allEnvDataList2_i[j].toInt();
			}*/
			
		}
	//结束病房读入*********************************************************

        workbooks->dynamicCall("Close()");
        excel.dynamicCall("Quit()");
	
		/*output*op1 = new output();
		for (int i = 0; i <intRows - 1; i++) {
			for (int j = 0; j < intcolumn-10; j++) {
				op1->ui.textBrowser->insertPlainText(QString::number(req[i][j]) + " ");
			}
			op1->ui.textBrowser->insertPlainText("\n");
		}
		op1->show();

		output*op2 = new output();
		for (int i = 0; i <intRows - 1; i++) {
			for (int j = 0; j < intcolumn - 10; j++) {
				op2->ui.textBrowser->insertPlainText(QString::number(done[i][j]) + " ");
			}
			op2->ui.textBrowser->insertPlainText("\n");
		}
		op2->show();

		output*op3 = new output();
		for (int i = 0; i <dep_row; i++) {
			for (int j = 0; j < dep_col; j++) {
				op3->ui.textBrowser->insertPlainText(QString::number(dep[i][j]) + " ");
			}
			op3->ui.textBrowser->insertPlainText("\n"); 
		}
		op3->show();

		output*op4 = new output();
		for (int i = 0; i <intRows - 1; i++) {
			for (int j = 0; j < intcolumn - 10; j++) {
				op4->ui.textBrowser->insertPlainText(QString::number(doc_choice[i][j]) + " ");
			}
			op4->ui.textBrowser->insertPlainText("\n");
		}
		op4->show();*/
		
    }
    else {

  
    }

}


void MainWindow::on_pushButton_2_clicked()
{
	//进度条***********************************************
	QProgressDialog *progressDialog = new QProgressDialog(QStringLiteral("正在计算......"), QStringLiteral("取消"), 0, 100, this);
	//QFont font("ZYSong18030", 12);
	progressDialog->setWindowTitle(QStringLiteral("请稍候"));
	//progressDialog->setFont(font);
	QSize size(300,100);
	progressDialog->setFixedSize(size);
	progressDialog->setWindowModality(Qt::WindowModal);
	progressDialog->setRange(0, 100);
	progressDialog->setMinimumDuration(0);
	
	//******************************************************
	var_row = tlb->doc_group.size();

	IloEnv env;
	IloModel model(env);

	IloArray<IloIntArray>done(env, var_row);//轮转历史
	IloArray<IloIntArray>req(env, var_row);//轮转计划
	IloArray<IloIntArray>doc_choice(env, var_row);//医生志愿
	IloIntArray doc_type(env, var_row); //医生类型
	IloArray<IloIntArray>dep(env, dep_row);//病房人数


	//构建历史、计划、志愿矩阵*************************************
	for (int i = 0; i < var_row; i++) {
		done[i] = IloIntArray(env, var_col);
		req[i] = IloIntArray(env, var_col);
		doc_choice[i] = IloIntArray(env, var_col);
	}
	
	//填充历史、计划矩阵*************************************
	for (int i = 0; i < var_row; i++) {
		for (int j = 0; j < var_col; j++) {
			QStringList dr = tlb->doc_group[i]->task[j].split(";");
			done[i][j] = dr[0].toInt();
			req[i][j] = dr[1].toInt();
		}
	}
	progressDialog->setValue(10);
	
	//填充志愿矩阵*************************************
	int val_choice[5] = { -18,-8,-5,-3,-1 };//志愿权重

	for (int i = 0; i < var_row; i++) {
		for (int j = 0; j < 5; j++) {
			int ed = excel_dep.indexOf(tlb->doc_group[i]->choice[j]);
			if (ed >= 0) {
				/*if (j == 0) { doc_choice[i][ed] = -1000000; }
				else if (j == 1) { doc_choice[i][ed] = -8; }
				else if (j == 2) { doc_choice[i][ed] = -5; }
				else if (j == 3) { doc_choice[i][ed] = -3; }
				else { doc_choice[i][ed] = -1; }*/
				doc_choice[i][ed] = val_choice[j];
			}
			else {
				if (tlb->doc_group[i]->choice[j] == QString::fromLocal8Bit("青光眼")) {
					doc_choice[i][0] = val_choice[j]; doc_choice[i][8] = val_choice[j];
				}
				else if(tlb->doc_group[i]->choice[j] == QString::fromLocal8Bit("外伤")){
					doc_choice[i][1] = val_choice[j]; doc_choice[i][9] = val_choice[j]; doc_choice[i][17] = val_choice[j];
				}
				else if (tlb->doc_group[i]->choice[j] == QString::fromLocal8Bit("眼底")) {
					doc_choice[i][2] = val_choice[j]; doc_choice[i][19] = val_choice[j]; doc_choice[i][20] = val_choice[j];
				}
				else if (tlb->doc_group[i]->choice[j] == QString::fromLocal8Bit("白内障")) {
					doc_choice[i][3] = val_choice[j]; doc_choice[i][16] = val_choice[j]; 
				}
				else if (tlb->doc_group[i]->choice[j] == QString::fromLocal8Bit("整形")) {
					doc_choice[i][6] = val_choice[j]; doc_choice[i][23] = val_choice[j]; 
				}
				else if (tlb->doc_group[i]->choice[j] == QString::fromLocal8Bit("眼肌")) {
					doc_choice[i][7] = val_choice[j]; doc_choice[i][13] = val_choice[j]; doc_choice[i][14] = val_choice[j]; doc_choice[i][15] = val_choice[j];
				}
				else if (tlb->doc_group[i]->choice[j] == QString::fromLocal8Bit("角膜")) {
					doc_choice[i][10] = val_choice[j]; doc_choice[i][18] = val_choice[j]; 
				}
				else if (tlb->doc_group[i]->choice[j] == QString::fromLocal8Bit("FFA")) {
					doc_choice[i][24] = val_choice[j]; doc_choice[i][25] = val_choice[j]; doc_choice[i][26] = val_choice[j];
				}
				else {}
			}

		}
	}
	progressDialog->setValue(20);
	//填充医生类型*************************************
	for (int i = 0; i < var_row; i++) {
		if (tlb->doc_group[i]->sign->text() == QString::fromLocal8Bit("住院医一阶段")) {
			doc_type[i] = 1;
		}
		else if (tlb->doc_group[i]->sign->text() == QString::fromLocal8Bit("住院医")) {
			doc_type[i] = 2;
		}
		else if (tlb->doc_group[i]->sign->text() == QString::fromLocal8Bit("研究生")) {
			doc_type[i] = 3;
		}
		else if (tlb->doc_group[i]->sign->text() == QString::fromLocal8Bit("规培生")) {
			doc_type[i] = 4;
		}
		else if (tlb->doc_group[i]->sign->text() == QString::fromLocal8Bit("长期进修医生")) {
			doc_type[i] = 5;
		}
		else {
			doc_type[i] = 6;
		}
	}
	progressDialog->setValue(30);
	//构建病房人数矩阵****************************
	for (int ii = 0; ii < dep_row; ii++) {
		dep[ii] = IloIntArray(env, dep_col);
	}
	
	//填充病房人数***************************
	for (int i = 0; i < dep_row; i++) {
		dep[i][0] = dlgd->department_group[i]->num_zhuyuan1->text().toInt();
		dep[i][1] = dlgd->department_group[i]->num_zhuyuan->text().toInt();
		dep[i][2] = dlgd->department_group[i]->num_yanjiu->text().toInt();
		dep[i][3] = dlgd->department_group[i]->num_guipei->text().toInt();
		dep[i][4] = dlgd->department_group[i]->num_changqi->text().toInt();
		dep[i][5] = dlgd->department_group[i]->num_duanqi->text().toInt();

		//填充病房人数限制*********
		dep[i][6] = dlgd->department_group[i]->num_dep_max;
		dep[i][7] = dlgd->department_group[i]->num_dep_min;

	}
	progressDialog->setValue(40);

	//领导矩阵*********************************************
	int num_itm = ui->listWidget->count();
	int num_itm2=ui->listWidget_2->count();
	
	IloArray<IloIntArray>leader_must(env, var_row);
	IloArray<IloIntArray>leader_avoid(env, var_row);

	for (int i = 0; i < var_row; i++) {
		leader_must[i] = IloIntArray(env, var_col);
		leader_avoid[i] = IloIntArray(env, var_col);
	}
	
	for (int i = 0; i < num_itm; i++) {
		leader_avoid[lea_avoid[i]->idx_doc][lea_avoid[i]->idx_dep] = 1;
	}
	for (int i = 0; i < num_itm2; i++) {
		leader_must[lea_must[i]->idx_doc][lea_must[i]->idx_dep] = 1;
	}
	progressDialog->setValue(50);
	/*
	output*op4 = new output();
	for (int i = 0; i <var_row; i++) {
		for (int j = 0; j < var_col; j++) {
			op4->ui.textBrowser->insertPlainText(QString::number(leader_avoid[i][j]) + " ");
		}
		op4->ui.textBrowser->insertPlainText("\n");
	}
	op4->show();


	output*op5 = new output();
	for (int i = 0; i <var_row; i++) {
		for (int j = 0; j < var_col; j++) {
			op5->ui.textBrowser->insertPlainText(QString::number(leader_must[i][j]) + " ");
		}
		op5->ui.textBrowser->insertPlainText("\n");
	}
	op5->show();
	*/
//开始约束**************************************************************
	IloInt i, j; int c;
	IloArray<IloIntVarArray>var(env, var_row);
	for (i = 0; i < var_row; i++) {
		var[i] = IloIntVarArray(env, var_col, 0, 1);
	}

	IloExpr exp1(env);
	int con=0;
	QList<int> err;
	QList<int> err2;
	QList<int> err3;
	
	//判断是否完成计划******************************
	for (i = 0; i < var_row; i++) {
		int count = 0;
		for (j = 0; j < var_col; j++) {
			int flag = 0;
			if (j == 11 || j == 27 || j == 40) {
				int count1 = 0;
				for (int k = 1; k <= dep_equ[j][0]; k++) {
					count1 = count1 + done[i][dep_equ[j][k]];
				}
				if (count1 >= req[i][dep_equ[j][1]]) { flag = 1; }
			}
			else{
				for (int k = 1; k <= dep_equ[j][0]; k++) {
					if (done[i][dep_equ[j][k]] >= req[i][dep_equ[j][k]]) { flag = 1; }
				}
			}
			if (flag == 1) { count=count+1; }
		}
		if (count == var_col) { doc_over[i] = 1; }
		else { doc_over[i] = 0; }
	}

		//判断是否在FFA前转了眼底
	for (i = 0; i < var_row; i++) {
		int count = done[i][2] + done[i][19] + done[i][20];
		if (count >= 3) { yandi_over[i] = 1; }
	}
		//判断是否在清光眼西前转了眼底or外伤
	for (i = 0; i < var_row; i++) {
		if ((done[i][2] + done[i][19] + done[i][20] >= 3)||(done[i][1] + done[i][9] + done[i][17] >= 3)) { yandiorwaishang_over[i] = 1; }
	}

	progressDialog->setValue(60);

	/*int flag2[165][45];

	for (int i = 0; i < 165; i++) {
		for (int j = 0; j < 45; j++) {
			flag2[i][j] = 0;

		}
	}*/
	//基本：根据done和req********与领导意志*******************************
	for (i = 0; i < var_row; i++) {
		con = 0;
		
			for (j = 0; j < var_col; j++) {
				if (doc_type[i] != 2 && doc_over[i] == 0) {
					if (done[i][j] < req[i][j] && done[i][j]>0 && j != 11 && j != 40  && j!=27) {
						model.add(var[i][j] == 1); 
						//if (flag2[i][j] == 2) { err2.append(i); err3.append(j);}
						//flag2[i][j] = 1;
						con++;
					}
					if (done[i][j] >= req[i][j]) {
						//if (j == 0|| j == 3) {
						for (int k = 1; k <= dep_equ[j][0]; k++) {
							model.add(var[i][dep_equ[j][k]] == 0); 
							//if (flag2[i][dep_equ[j][k]] == 1) { err2.append(i); err3.append(dep_equ[j][k]);}
							//flag2[i][dep_equ[j][k]] = 2;
						}
						model.add(var[i][j] == 0);
					}
				}
				if (leader_must[i][j] == 1) {
					model.add(var[i][j] == 1);
				}
				if (leader_avoid[i][j] == 1) {
					model.add(var[i][j] == 0);
				}
			}
			if (con > 1) { err.append(i); }

			if ((yandi_over[i] == 0)&&(doc_type[i] == 1|| doc_type[i] == 3|| doc_type[i] == 4)) {
				model.add(var[i][24] == 0); model.add(var[i][25] == 0);model.add(var[i][26] == 0);
			}
			if ((yandiorwaishang_over[i] == 0) && (doc_type[i] == 1 || doc_type[i] == 3 || doc_type[i] == 4)) {
				model.add(var[i][8] == 0);
			}
		
	}
	progressDialog->setValue(70);
	//增加tytt

	//output*op6 = new output();
	//for (int i = 0; i <err.size(); i++) {
	//	
	//		op6->ui.textBrowser->insertPlainText(QString::number(err[i]) + " ");
	//
	//	op6->ui.textBrowser->insertPlainText("\n");
	//}
	////op6->show();

	//output*op8 = new output();
	//for (int i = 0; i <var_row; i++) {

	//	op8->ui.textBrowser->insertPlainText(QString::number(doc_over[i]) + " ");

	//	op8->ui.textBrowser->insertPlainText("\n");
	//}
	////op8->show();

	//output*op9 = new output();
	//for (int i = 0; i <err2.size(); i++) {

	//	op9->ui.textBrowser->insertPlainText(QString::number(err2[i]) + " ");

	//	op9->ui.textBrowser->insertPlainText("\n");
	//}
	////op9->show();
	//output*op10 = new output();
	//for (int i = 0; i <err3.size(); i++) {

	//	op10->ui.textBrowser->insertPlainText(QString::number(err3[i]) + " ");

	//	op10->ui.textBrowser->insertPlainText("\n");
	//}
	////op10->show();

	//每人只能去一个科室***************************************

	for (i = 0; i < var_row; i++) {
		exp1.clear();
		for (j = 0; j < var_col; j++) {
			exp1 = exp1 + var[i][j];
		}
		if (doc_over[i] == 1&&(doc_type[i]==3|| doc_type[i] == 4)) { model.add(exp1 <= 1); }
		else {  model.add(exp1 == 1);}
	}
	

	//构建目标函数******************************************
	IloExpr exp_n1(env); IloExpr exp_n2(env); IloExpr exp_n3(env);
	IloExpr exp_n4(env); IloExpr exp_n5(env); IloExpr exp_n6(env);
	IloExpr n1(env); IloExpr n2(env); IloExpr n3(env);
	IloExpr n4(env); IloExpr n5(env); IloExpr n6(env);
	
	for (j = 0; j < var_col; j++) {
		n1.clear(); n2.clear(); n3.clear(); n4.clear(); n5.clear(); n6.clear();
		for (i = 0; i < var_row; i++) {
			if (doc_type[i] == 1) { n1 = n1 + var[i][j]; }
			else if (doc_type[i] == 2) { n2 = n2 + var[i][j]; }
			else if (doc_type[i] == 3) { n3 = n3 + var[i][j]; }
			else if (doc_type[i] == 4) { n4 = n4 + var[i][j]; }
			else if (doc_type[i] == 5) { n5 = n5 + var[i][j]; }
			else { n6 = n6 + var[i][j]; }
		}
		//总人数约束********************
		model.add(n1+n2+n3+n4+n5+n6 <= dep[j][6]);
		model.add(n1 + n2 + n3 + n4 + n5 + n6 >= dep[j][7]);

		exp_n1 = exp_n1 + IloAbs(n1 - dep[j][0]);
		exp_n2 = exp_n2 + IloAbs(n2 - dep[j][1]);
		exp_n3 = exp_n3 + IloAbs(n3 - dep[j][2]);
		exp_n4 = exp_n4 + IloAbs(n4 - dep[j][3]);
		exp_n5 = exp_n5 + IloAbs(n5 - dep[j][4]);
		exp_n6 = exp_n6 + IloAbs(n6 - dep[j][5]);
	}

	IloExpr exp_n7(env);

	for (j = 0; j < var_col; j++) {
		for (i = 0; i < var_row; i++) {
			exp_n7 = exp_n7 + var[i][j] * doc_choice[i][j];
		}
	}
	//人数权重*********************
    IloObjective obj(env, 50*exp_n1+50*exp_n2+30*exp_n3+30*exp_n4+30*exp_n5+30*exp_n6+100*exp_n7, IloObjective::Minimize);
	//IloObjective obj(env, exp_n7, IloObjective::Maximize);
	model.add(obj);

	IloCplex cplex(model);
	
	progressDialog->setValue(80);
	
	try
	{
		if (!cplex.solve())
		{
			progressDialog->setValue(100);
			if ((cplex.getStatus() == IloAlgorithm::Infeasible) ||
				(cplex.getStatus() == IloAlgorithm::InfeasibleOrUnbounded))
			{
				QMessageBox::information(NULL, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("约束存在矛盾"), QMessageBox::Yes, QMessageBox::Yes);
			}
			QMessageBox::information(NULL, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("无法完成求解"), QMessageBox::Yes, QMessageBox::Yes);
			throw(-1);
		}
		else {
	//cplex.solve();
	
	progressDialog->setValue(90);
	//结束约束**************************************************************	
	
	
	//写入结果*****************************************************************
		QAxObject excel("Excel.Application");

		excel.setProperty("Visible", false);
		QAxObject *workbooks = excel.querySubObject("WorkBooks");
		workbooks->dynamicCall("Add"); // 新建一个工作簿
		QAxObject* workbook2 = excel.querySubObject("ActiveWorkBook"); // 获取当前工作簿
		QAxObject *worksheets2 = workbook2->querySubObject("Sheets");//获取工作表集合
		QAxObject *worksheet2 = worksheets2->querySubObject("Item(int)", 1);//获取工作表集合的工作表1，即sheet1


		IloArray<IloIntArray>ans(env, var_row);//轮转历史
		for (int i = 0; i < var_row; i++) {
			ans[i] = IloIntArray(env, var_col);
		}

		for (j = 0; j < var_col; j++) {
		//for (j = 0; j < 45; j++) {
			int exdoc = 2;
			for (i = 0; i < var_row; i++) {
			//for (i = 0; i < 168; i++) {
				c = cplex.getValue(var[i][j]); ans[i][j] = cplex.getValue(var[i][j]);
				if (i == 0) {
					QAxObject *cell = worksheet2->querySubObject("Cells(int,int)", i + 1, j + 1);
					cell->setProperty("Value", excel_dep[j]);  //设置单元格值
					QAxObject *interior = cell->querySubObject("Interior");
					interior->setProperty("Color", QColor(255, 0, 0));
				}
				if (c == 1) {
					QAxObject *cell = worksheet2->querySubObject("Cells(int,int)", exdoc, j + 1);
					exdoc++;
					//cell->setProperty("Value", excel_doc[i]);  //设置单元格值
					cell->setProperty("Value", tlb->doc_group[i]->head->text());  //设置单元格值
					QAxObject* interior = cell->querySubObject("Interior");
					interior->setProperty("Color", QColor(255, 255, 255 - (30 + (j % 2) * 60)));
				}
			}
		}
		//你好
		//检查志愿满足情况****************************************
		worksheets2->dynamicCall("Add"); // 新建一个sheet
		QAxObject *worksheet2_2 = worksheets2->querySubObject("Item(int)", 1);//获取工作表集合的工作表1，即sheet1
		int itr = 1;
		QAxObject *cell = worksheet2_2->querySubObject("Cells(int,int)", 1, 1);
		cell->setProperty("Value", QString::fromLocal8Bit("志愿未满足人员如下："));  //设置单元格值
		for (i = 0; i < var_row; i++) {
			int flag_choice = 0; int flag_num_choice=0;
			for (j = 0; j < var_col; j++) {
				if (doc_choice[i][j] != 0) { flag_num_choice = 1; }
				if (ans[i][j] == 1 && doc_choice[i][j] != 0) { flag_choice = 1; }
			}
			if (flag_choice == 0 && flag_num_choice == 1) {
				QAxObject *cell = worksheet2_2->querySubObject("Cells(int,int)", itr+1,1);
				cell->setProperty("Value", tlb->doc_group[i]->head->text());  //设置单元格值
				itr++;
			}
		}


		QDateTime current_date_time = QDateTime::currentDateTime();
		QString current_date = current_date_time.toString("MMddhhmmss");
		QString fileName = QFileDialog::getSaveFileName(this, QString::fromLocal8Bit("保存文件"), (QString::fromLocal8Bit("排班THU") + current_date), tr("EXCEL(*.xlsx)"));
		workbook2->dynamicCall("SaveAs(const QString&)", QDir::toNativeSeparators(fileName));
		workbook2->dynamicCall("Close()");//关闭工作簿

		//写入记录更新文件*************************************************************
		
		workbooks->dynamicCall("Add"); // 新建一个工作簿
		QAxObject* workbook3 = excel.querySubObject("ActiveWorkBook"); // 获取当前工作簿
		QAxObject *worksheets3 = workbook3->querySubObject("Sheets");//获取工作表集合
		worksheets3->dynamicCall("Add"); // 新建一个sheet
		QAxObject *worksheet3_1 = worksheets3->querySubObject("Item(int)", 1);//获取工作表集合的工作表1，即sheet1

		QList<QVariant> allRowsData;//保存所有行数据
		allRowsData.clear();
		for (int i = 0; i <var_row; i++)
		{
			QList<QVariant> aRowData;//保存一行数据
			for (int j=0; j< var_col; j++)
			{
				QStringList dra = tlb->doc_group[i]->task[j].split(";");
				aRowData.append(QVariant(QString::number(dra[0].toInt()+ans[i][j])+";"+dra[1]));
			}
				allRowsData.append(QVariant(aRowData));
		}
		
		QAxObject *range = worksheet3_1->querySubObject("Range(const QString )", ("K2:BC"+QString::number(1+var_row)));
		range->dynamicCall("SetValue(const QVariant&)", QVariant(allRowsData));//存储所有数据到 excel 中,批量操作,速度极快
		
		allRowsData.clear();
		for (int i = 0; i <var_row; i++)
		{
			QList<QVariant> aRowData;//保存一行数据
			
			aRowData.append(QVariant(tlb->doc_group[i]->head->text()));
			aRowData.append(QVariant(tlb->doc_group[i]->id));
			aRowData.append(QVariant(tlb->doc_group[i]->sign->text()));
			aRowData.append(QVariant(tlb->doc_group[i]->res));
			aRowData.append(QVariant(tlb->doc_group[i]->tel));
			aRowData.append(QVariant(tlb->doc_group[i]->choice[0]));
			aRowData.append(QVariant(tlb->doc_group[i]->choice[1]));
			aRowData.append(QVariant(tlb->doc_group[i]->choice[2]));
			aRowData.append(QVariant(tlb->doc_group[i]->choice[3]));
			aRowData.append(QVariant(tlb->doc_group[i]->choice[4]));

			allRowsData.append(QVariant(aRowData));
		}
		QAxObject *range1 = worksheet3_1->querySubObject("Range(const QString )", ("A2:J" + QString::number(1 + var_row)));
		range1->dynamicCall("SetValue(const QVariant&)", QVariant(allRowsData));//存储所有数据到 excel 中,批量操作,速度极快

		allRowsData.clear();
		for (int i = 0;i <1; i++)
		{
			QList<QVariant> aRowData;//保存一行数据

			aRowData.append(QVariant(QString::fromLocal8Bit("姓名")));
			aRowData.append(QVariant(QString::fromLocal8Bit("id")));
			aRowData.append(QVariant(QString::fromLocal8Bit("属性")));
			aRowData.append(QVariant(QString::fromLocal8Bit("单位")));
			aRowData.append(QVariant(QString::fromLocal8Bit("电话")));
			aRowData.append(QVariant(QString::fromLocal8Bit("志愿一")));
			aRowData.append(QVariant(QString::fromLocal8Bit("志愿二")));
			aRowData.append(QVariant(QString::fromLocal8Bit("志愿三")));
			aRowData.append(QVariant(QString::fromLocal8Bit("志愿四")));
			aRowData.append(QVariant(QString::fromLocal8Bit("志愿五")));
			for (int j = 0; j < dep_row; j++)
			{
				aRowData.append(QVariant(excel_dep[j]));
			}
			allRowsData.append(QVariant(aRowData));
		}
		QAxObject *range2 = worksheet3_1->querySubObject("Range(const QString )", ("A1:BC1" ));
		range2->dynamicCall("SetValue(const QVariant&)", QVariant(allRowsData));//存储所有数据到 excel 中,批量操作,速度极快


		QAxObject *worksheet3_2 = worksheets3->querySubObject("Item(int)",2);//获取工作表集合的工作表1，即sheet1

		allRowsData.clear();
		for (int i = 0; i <var_col; i++)
		{
			QList<QVariant> aRowData;//保存一行数据
			
			aRowData.append(QVariant(tlb->dep_group[i]->num_zhuyuan1->text()));
			aRowData.append(QVariant(tlb->dep_group[i]->num_zhuyuan->text()));
			aRowData.append(QVariant(tlb->dep_group[i]->num_yanjiu->text()));
			aRowData.append(QVariant(tlb->dep_group[i]->num_guipei->text()));
			aRowData.append(QVariant(tlb->dep_group[i]->num_changqi->text()));
			aRowData.append(QVariant(tlb->dep_group[i]->num_duanqi->text()));
			
			allRowsData.append(QVariant(aRowData));
		}

		QAxObject *range5 = worksheet3_2->querySubObject("Range(const QString )", ("B2:G46" ));
		range5->dynamicCall("SetValue(const QVariant&)", QVariant(allRowsData));//存储所有数据到 excel 中,批量操作,速度极快

		allRowsData.clear();
		for (int i = 0; i <1; i++)
		{
			QList<QVariant> aRowData;//保存一行数据
			aRowData.append(QVariant(QString::fromLocal8Bit("病房")));
			aRowData.append(QVariant(QString::fromLocal8Bit("住院医一阶段")));
			aRowData.append(QVariant(QString::fromLocal8Bit("住院医")));
			aRowData.append(QVariant(QString::fromLocal8Bit("研究生")));
			aRowData.append(QVariant(QString::fromLocal8Bit("规培生")));
			aRowData.append(QVariant(QString::fromLocal8Bit("长期进修医生")));
			aRowData.append(QVariant(QString::fromLocal8Bit("短期进修医生")));
			allRowsData.append(QVariant(aRowData));
		}
		QAxObject *range6 = worksheet3_2->querySubObject("Range(const QString )", ("A1:G1"));
		range6->dynamicCall("SetValue(const QVariant&)", QVariant(allRowsData));//存储所有数据到 excel 中,批量操作,速度极快
		
		allRowsData.clear();
		for (int i = 0; i <var_col; i++)
		{
			QList<QVariant> aRowData;//保存一行数据
			aRowData.append(QVariant(excel_dep[i]));
			allRowsData.append(QVariant(aRowData));
		}
		QAxObject *range7 = worksheet3_2->querySubObject("Range(const QString )", ("A2:A46"));
		range7->dynamicCall("SetValue(const QVariant&)", QVariant(allRowsData));//存储所有数据到 excel 中,批量操作,速度极

	
		workbook3->dynamicCall("SaveAs(const QString&)", QDir::toNativeSeparators(fileName.insert(fileName.size()-5,"d")));
		workbook3->dynamicCall("Close()");//关闭工作簿
		
		env.end();
		progressDialog->setValue(100);
		

		}
	}
	catch (IloException& e)
	{
		QMessageBox::information(NULL, QString::fromLocal8Bit("提示"), "Concert exception caught: ", QMessageBox::Yes, QMessageBox::Yes);
	}
	catch (...)
	{
		QMessageBox::information(NULL, QString::fromLocal8Bit("提示"), "Unknown exception caught ", QMessageBox::Yes, QMessageBox::Yes);
	}

}

void MainWindow::on_pushButton_8_clicked()
{
	dlgd->show();
}


