#ifndef DOC_H
#define DOC_H
#include<dialog.h>
#include <QWidget>
#include <QLabel>
#include <QEvent>
#include <QPushButton>
//自定义信息Item类
class doc : public QWidget
{
    Q_OBJECT
public:
    explicit doc(QWidget *parent = 0);
    doc(int);
    void initUi();//初始化Ui
    QPushButton *head;  //名字
    QLabel *name;  //
    QLabel *sign;  //类型
    //void on_head_clicked();
    void mouseDoubleClickEvent(QMouseEvent*);
    //void head->mouseDoubleClickEvent(QMouseEvent*);

public slots:
	void jie();
};




#endif // DOC_H
