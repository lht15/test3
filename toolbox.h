#ifndef TOOLBOX_H
#define TOOLBOX_H

#include <QToolBox>
#include <QButtonGroup>
#include<qlist.h>
#include"doc_longterm.h"
#include"doc.h"
#include"dep_item.h"
//#include<dialog.h>
#include <QWidget>
#include <QLabel>
#include <QEvent>
#include <QPushButton>
namespace Ui {
class ToolBox;
}

class ToolBox : public QToolBox
{
    Q_OBJECT

public:
    explicit ToolBox(QWidget *parent = 0);

    ~ToolBox();
    int number_1=0;
    int number_2=0;
    int number_3=0;
    int number_4=0;
    int number_5=0;

	QVector<doc_longterm*> doc_group; //医生longterm指针表
	QVector<dep_item*>dep_group;//病房item指针表
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_11_clicked();

	void on_pushButton_12_clicked();

	void on_pushButton_13_clicked();

public:
    Ui::ToolBox *ui;
};

#endif // TOOLBOX_H
