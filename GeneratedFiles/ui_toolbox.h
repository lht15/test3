/********************************************************************************
** Form generated from reading UI file 'toolbox.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TOOLBOX_H
#define UI_TOOLBOX_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLayout>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QToolBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ToolBox
{
public:
    QWidget *page;
    QPushButton *pushButton;
    QListWidget *listWidget;
    QPushButton *pushButton_6;
    QPushButton *pushButton_11;
    QWidget *page_2;
    QPushButton *pushButton_2;
    QListWidget *listWidget_2;
    QPushButton *pushButton_7;
    QWidget *page_3;
    QListWidget *listWidget_3;
    QPushButton *pushButton_3;
    QPushButton *pushButton_8;
    QWidget *page_4;
    QListWidget *listWidget_4;
    QPushButton *pushButton_4;
    QPushButton *pushButton_9;
    QWidget *page_5;
    QListWidget *listWidget_5;
    QPushButton *pushButton_5;
    QPushButton *pushButton_10;
    QWidget *page_6;
    QListWidget *listWidget_6;
    QPushButton *pushButton_12;
    QPushButton *pushButton_13;

    void setupUi(QToolBox *ToolBox)
    {
        if (ToolBox->objectName().isEmpty())
            ToolBox->setObjectName(QStringLiteral("ToolBox"));
        ToolBox->resize(800, 900);
        QFont font;
        font.setFamily(QStringLiteral("Adobe Arabic"));
        font.setPointSize(15);
        ToolBox->setFont(font);
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        page->setGeometry(QRect(0, 0, 800, 714));
        QFont font1;
        font1.setFamily(QStringLiteral("Adobe Arabic"));
        font1.setPointSize(18);
        page->setFont(font1);
        pushButton = new QPushButton(page);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(520, 20, 120, 40));
        QFont font2;
        font2.setPointSize(10);
        pushButton->setFont(font2);
        listWidget = new QListWidget(page);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        listWidget->setGeometry(QRect(10, 20, 470, 670));
        listWidget->setAutoScrollMargin(16);
        listWidget->setBatchSize(10);
        pushButton_6 = new QPushButton(page);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        pushButton_6->setGeometry(QRect(670, 20, 120, 40));
        pushButton_6->setFont(font2);
        pushButton_11 = new QPushButton(page);
        pushButton_11->setObjectName(QStringLiteral("pushButton_11"));
        pushButton_11->setGeometry(QRect(520, 100, 120, 40));
        pushButton_11->setFont(font2);
        ToolBox->addItem(page, QString::fromUtf8("\351\225\277\346\234\237\350\277\233\344\277\256\345\214\273\347\224\237"));
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        page_2->setGeometry(QRect(0, 0, 800, 714));
        pushButton_2 = new QPushButton(page_2);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(520, 20, 120, 40));
        pushButton_2->setFont(font2);
        listWidget_2 = new QListWidget(page_2);
        listWidget_2->setObjectName(QStringLiteral("listWidget_2"));
        listWidget_2->setGeometry(QRect(10, 20, 470, 670));
        listWidget_2->setAutoScrollMargin(16);
        listWidget_2->setBatchSize(10);
        pushButton_7 = new QPushButton(page_2);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));
        pushButton_7->setGeometry(QRect(670, 20, 120, 40));
        pushButton_7->setFont(font2);
        ToolBox->addItem(page_2, QString::fromUtf8("\347\237\255\346\234\237\350\277\233\344\277\256\345\214\273\347\224\237"));
        page_3 = new QWidget();
        page_3->setObjectName(QStringLiteral("page_3"));
        page_3->setGeometry(QRect(0, 0, 800, 714));
        listWidget_3 = new QListWidget(page_3);
        listWidget_3->setObjectName(QStringLiteral("listWidget_3"));
        listWidget_3->setGeometry(QRect(10, 20, 470, 670));
        listWidget_3->setAutoScrollMargin(16);
        listWidget_3->setBatchSize(10);
        pushButton_3 = new QPushButton(page_3);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(520, 20, 120, 40));
        pushButton_3->setFont(font2);
        pushButton_8 = new QPushButton(page_3);
        pushButton_8->setObjectName(QStringLiteral("pushButton_8"));
        pushButton_8->setGeometry(QRect(670, 20, 120, 40));
        pushButton_8->setFont(font2);
        ToolBox->addItem(page_3, QString::fromUtf8("\347\240\224\347\251\266\347\224\237"));
        page_4 = new QWidget();
        page_4->setObjectName(QStringLiteral("page_4"));
        page_4->setGeometry(QRect(0, 0, 800, 714));
        listWidget_4 = new QListWidget(page_4);
        listWidget_4->setObjectName(QStringLiteral("listWidget_4"));
        listWidget_4->setGeometry(QRect(10, 20, 470, 670));
        listWidget_4->setAutoScrollMargin(16);
        listWidget_4->setBatchSize(10);
        pushButton_4 = new QPushButton(page_4);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(520, 20, 120, 40));
        pushButton_4->setFont(font2);
        pushButton_9 = new QPushButton(page_4);
        pushButton_9->setObjectName(QStringLiteral("pushButton_9"));
        pushButton_9->setGeometry(QRect(670, 20, 120, 40));
        pushButton_9->setFont(font2);
        ToolBox->addItem(page_4, QString::fromUtf8("\350\247\204\345\237\271\347\224\237"));
        page_5 = new QWidget();
        page_5->setObjectName(QStringLiteral("page_5"));
        page_5->setGeometry(QRect(0, 0, 800, 714));
        listWidget_5 = new QListWidget(page_5);
        listWidget_5->setObjectName(QStringLiteral("listWidget_5"));
        listWidget_5->setGeometry(QRect(10, 20, 470, 670));
        listWidget_5->setAutoScrollMargin(16);
        listWidget_5->setBatchSize(10);
        pushButton_5 = new QPushButton(page_5);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setGeometry(QRect(520, 20, 120, 40));
        pushButton_5->setFont(font2);
        pushButton_10 = new QPushButton(page_5);
        pushButton_10->setObjectName(QStringLiteral("pushButton_10"));
        pushButton_10->setGeometry(QRect(670, 20, 120, 40));
        pushButton_10->setFont(font2);
        ToolBox->addItem(page_5, QString::fromUtf8("\344\275\217\351\231\242\345\214\273"));
        page_6 = new QWidget();
        page_6->setObjectName(QStringLiteral("page_6"));
        page_6->setGeometry(QRect(0, 0, 800, 714));
        listWidget_6 = new QListWidget(page_6);
        listWidget_6->setObjectName(QStringLiteral("listWidget_6"));
        listWidget_6->setGeometry(QRect(10, 20, 470, 670));
        listWidget_6->setAutoScrollMargin(16);
        listWidget_6->setBatchSize(10);
        pushButton_12 = new QPushButton(page_6);
        pushButton_12->setObjectName(QStringLiteral("pushButton_12"));
        pushButton_12->setGeometry(QRect(520, 20, 120, 40));
        pushButton_12->setFont(font2);
        pushButton_13 = new QPushButton(page_6);
        pushButton_13->setObjectName(QStringLiteral("pushButton_13"));
        pushButton_13->setGeometry(QRect(670, 20, 120, 40));
        pushButton_13->setFont(font2);
        ToolBox->addItem(page_6, QString::fromUtf8("\344\275\217\351\231\242\345\214\273\344\270\200\351\230\266\346\256\265"));

        retranslateUi(ToolBox);
       // QObject::connect(pushButton_12, SIGNAL(clicked()), ToolBox, SLOT(on_pushButton_12_clicked()));
        //QObject::connect(pushButton_13, SIGNAL(clicked()), ToolBox, SLOT(on_pushButton_13_clicked()));

        ToolBox->setCurrentIndex(5);
        ToolBox->layout()->setSpacing(4);


        QMetaObject::connectSlotsByName(ToolBox);
    } // setupUi

    void retranslateUi(QToolBox *ToolBox)
    {
        ToolBox->setWindowTitle(QApplication::translate("ToolBox", "\345\214\273\347\224\237\344\277\241\346\201\257", nullptr));
        pushButton->setText(QApplication::translate("ToolBox", "\346\267\273\345\212\240", nullptr));
        pushButton_6->setText(QApplication::translate("ToolBox", "\345\210\240\351\231\244", nullptr));
        pushButton_11->setText(QApplication::translate("ToolBox", "\345\257\274\345\205\245", nullptr));
        ToolBox->setItemText(ToolBox->indexOf(page), QApplication::translate("ToolBox", "\351\225\277\346\234\237\350\277\233\344\277\256\345\214\273\347\224\237", nullptr));
        pushButton_2->setText(QApplication::translate("ToolBox", "\346\267\273\345\212\240", nullptr));
        pushButton_7->setText(QApplication::translate("ToolBox", "\345\210\240\351\231\244", nullptr));
        ToolBox->setItemText(ToolBox->indexOf(page_2), QApplication::translate("ToolBox", "\347\237\255\346\234\237\350\277\233\344\277\256\345\214\273\347\224\237", nullptr));
        pushButton_3->setText(QApplication::translate("ToolBox", "\346\267\273\345\212\240", nullptr));
        pushButton_8->setText(QApplication::translate("ToolBox", "\345\210\240\351\231\244", nullptr));
        ToolBox->setItemText(ToolBox->indexOf(page_3), QApplication::translate("ToolBox", "\347\240\224\347\251\266\347\224\237", nullptr));
        pushButton_4->setText(QApplication::translate("ToolBox", "\346\267\273\345\212\240", nullptr));
        pushButton_9->setText(QApplication::translate("ToolBox", "\345\210\240\351\231\244", nullptr));
        ToolBox->setItemText(ToolBox->indexOf(page_4), QApplication::translate("ToolBox", "\350\247\204\345\237\271\347\224\237", nullptr));
        pushButton_5->setText(QApplication::translate("ToolBox", "\346\267\273\345\212\240", nullptr));
        pushButton_10->setText(QApplication::translate("ToolBox", "\345\210\240\351\231\244", nullptr));
        ToolBox->setItemText(ToolBox->indexOf(page_5), QApplication::translate("ToolBox", "\344\275\217\351\231\242\345\214\273", nullptr));
        pushButton_12->setText(QApplication::translate("ToolBox", "\346\267\273\345\212\240", nullptr));
        pushButton_13->setText(QApplication::translate("ToolBox", "\345\210\240\351\231\244", nullptr));
        ToolBox->setItemText(ToolBox->indexOf(page_6), QApplication::translate("ToolBox", "\344\275\217\351\231\242\345\214\273\344\270\200\351\230\266\346\256\265", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ToolBox: public Ui_ToolBox {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TOOLBOX_H
