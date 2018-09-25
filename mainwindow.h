#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <ilcplex/ilocplex.h>
#include <QMainWindow>
#include"toolbox.h"
#include"hard_constraint.h"
#include"ui_dialog_dep.h"
#include"dep_item.h"
#include"dialog_dep.h"
#include <QKeyEvent>
#include <QMessageBox>
#include"var.h"
ILOSTLBEGIN
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

   ToolBox *tlb;
   dialog_dep*dlgd;
   void addc(QString str);

  // IloEnv env;
   //IloModel model;

  // IloRangeArray con;
   //<IloIntArray> done;//医生矩阵
   //IloArray<IloIntArray> req;
   //IloArray<IloIntArray> doc_choice;//医生志愿矩阵


   //IloArray<IloIntArray> dep;//病房人数矩阵

   //int  dep_equ[6][] = { {1,2},{3,4,5},{6,7,8,9},{9,11,1},{2,3},{2,44,6} };
   int  dep_equ0[3] = { 2,0,8 };
   int  dep_equ1[4] = { 3,1,9,17 };
   int  dep_equ2[4] = { 3,2,19,20 };
   int  dep_equ3[3] = { 2,3,16 };
   int  dep_equ4[3] = { 1,4};
   int  dep_equ5[3] = { 1,5 };
   int  dep_equ6[3] = { 2,6,23 };
   int  dep_equ7[5] = { 4,7,13,14,15 };
   int  dep_equ8[3] = { 2,0,8 };
   int  dep_equ9[4] = { 3,9,1,17 };
   int  dep_equ10[3] = { 2,10,18 };
   int  dep_equ11[5] = { 3,11,27,40 };
   int  dep_equ12[3] = { 1,12};
   int  dep_equ13[5] = { 4,7,13,14,15  };
   int  dep_equ14[5] = { 4,7,13,14,15 };
   int  dep_equ15[5] = { 4,7,13,14,15 };
   int  dep_equ16[3] = { 2,3,16 };
   int  dep_equ17[4] = { 3,9,1,17 };
   int  dep_equ18[3] = { 2,10,18 };
   int  dep_equ19[4] = { 3,2,19,20 };
   int  dep_equ20[4] = { 3,2,19,20 };
   
   int  dep_equ21[4] = { 1,21 };
   int  dep_equ22[3] = { 1,22 };
   int  dep_equ23[4] = { 2,6,23 };
   int  dep_equ24[4] = { 3,24,25,26 };
   int  dep_equ25[4] = { 3,24,25,26 };
   int  dep_equ26[4] = { 3,24,25,26 };

   int  dep_equ27[5] = { 3,11,27,40 };
   int  dep_equ28[4] = { 1,28 };
   int  dep_equ29[4] = { 1,29 };
   int  dep_equ30[4] = { 1,30 };
   int  dep_equ31[4] = { 1,31 };
   int  dep_equ32[4] = { 1,32 };
   int  dep_equ33[4] = { 1,33 };
   int  dep_equ34[4] = { 1,34 };
   int  dep_equ35[4] = { 1,35 };
   int  dep_equ36[4] = { 1,36 };
   int  dep_equ37[4] = { 1,37 };
   int  dep_equ38[4] = { 1,38 };
   int  dep_equ39[4] = { 1,39 }; 
   int  dep_equ40[5] = { 3,11,27,40 };
   int  dep_equ41[5] = { 1,41 };
   int  dep_equ42[4] = { 1,42};
   int  dep_equ43[4] = { 1,43 };
   int  dep_equ44[4] = { 1,44 };

   int* dep_equ[45] = { dep_equ0, dep_equ1,dep_equ2, dep_equ3,dep_equ4, dep_equ5,dep_equ6, dep_equ7,dep_equ8, dep_equ9,dep_equ10,dep_equ11,dep_equ12, dep_equ13,dep_equ14, dep_equ15,dep_equ16, dep_equ17,dep_equ18, dep_equ19,dep_equ20,dep_equ21,dep_equ22, dep_equ23,dep_equ24, dep_equ25,dep_equ26, dep_equ27,dep_equ28, dep_equ29,dep_equ30,dep_equ31,dep_equ32, dep_equ33,dep_equ34, dep_equ35,dep_equ36, dep_equ37,dep_equ38, dep_equ39,dep_equ40,dep_equ41,dep_equ42, dep_equ43,dep_equ44 };
  // QList<int*>dep_equ = { dep_equ0, dep_equ1, dep_equ2 };

  // IloArray<IloIntArray> leader_must;//领导矩阵
  // IloArray<IloIntArray> leader_avoid;

   QList<hard_constraint*> lea_must;//领导listwidget的指针表
   QList<hard_constraint*> lea_avoid;

   //IloIntArray doc_type;//医生类型矩阵

   

   IloArray<IloIntVarArray>var;
 
   int var_row;//医生矩阵大小
   int var_col;

   int dep_row;//病房矩阵大小
   int dep_col;

   //int *doc_over = new int[var_row];//记录医生是否完成培养方案
   int doc_over[500];
   int yandi_over[500];//眼底是否轮转过
   int yandiorwaishang_over[500];//眼底或外伤是否轮转过


   QList<QString> excel_doc;//获取表中医生姓名
   QList<QString> excel_dep;//获取表中科室姓名
  
private slots:
    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_6_clicked();

	void on_pushButton_2_clicked();

	void on_pushButton_7_clicked();

	void on_pushButton_8_clicked();

	//void keyPressEvent(QKeyEvent*);
public:
    Ui::MainWindow *ui;

	//bool eventFilter(QObject *watched, QEvent *event);
};

#endif // MAINWINDOW_H
