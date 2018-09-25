#include "hard_constraint.h"

hard_constraint::hard_constraint()
{
initUi();
}
void hard_constraint::initUi()
{
    //初始化

    txt=new QLabel(this);
    department=new QPushButton(this);
    doctor=new QPushButton(this);

    //设置头像大小
    department->setFixedSize(150,30);
    doctor->setFixedSize(150,30);
    txt->setFixedSize(80,30);
    //设置个性签名字体为灰色
    QPalette color;
    color.setColor(QPalette::Text,Qt::red);
    doctor->setPalette(color);
     txt->setPalette(color);
    //布局
    doctor->move(7,27);
    txt->move(180,27);

    department->move(254,27);
    // connect(this->head, SIGNAL(clicked(bool)), this, SLOT(jie()));
}
