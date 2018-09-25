#include "doc.h"


doc::doc(QWidget *parent) :
    QWidget(parent)
{
    initUi();
}

//初始化Ui
void doc::initUi()
{
    //初始化
    head=new QPushButton(this);

    name=new QLabel(this);
    sign=new QLabel(this);
    //设置头像大小
    head->setFixedSize(150,30);
    name->setFixedSize(150,30);
    //设置个性签名字体为灰色
    QPalette color;
    color.setColor(QPalette::Text,Qt::red);
    sign->setPalette(color);
    //布局
    head->move(7,7);
    name->move(154,30);
    sign->move(280,30);
     connect(this->head, SIGNAL(clicked(bool)), this, SLOT(jie()));
}

void doc::jie(){

    Dialog*dl;
    dl=new Dialog();
    dl->show();
}

void doc::mouseDoubleClickEvent(QMouseEvent* event)
{
   // qDebug("sss");
    Dialog*dl;
    dl=new Dialog();
    dl->setWindowTitle(name->text());
    dl->show();

}
