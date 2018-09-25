/********************************************************************************
** Form generated from reading UI file 'dialog_task.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_TASK_H
#define UI_DIALOG_TASK_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_dialog_task
{
public:
    QPushButton *pushButton;
    QWidget *widget;
    QGridLayout *gridLayout;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;

    void setupUi(QDialog *dialog_task)
    {
        if (dialog_task->objectName().isEmpty())
            dialog_task->setObjectName(QStringLiteral("dialog_task"));
        dialog_task->resize(400, 300);
        pushButton = new QPushButton(dialog_task);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(270, 230, 111, 31));
        QFont font;
        font.setPointSize(13);
        pushButton->setFont(font);
        widget = new QWidget(dialog_task);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(60, 90, 271, 61));
        gridLayout = new QGridLayout(widget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));
        label->setFont(font);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        label_2 = new QLabel(widget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font);

        gridLayout->addWidget(label_2, 0, 1, 1, 1);

        lineEdit = new QLineEdit(widget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        gridLayout->addWidget(lineEdit, 1, 0, 1, 1);

        lineEdit_2 = new QLineEdit(widget);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));

        gridLayout->addWidget(lineEdit_2, 1, 1, 1, 1);


        retranslateUi(dialog_task);
        QObject::connect(pushButton, SIGNAL(clicked()), dialog_task, SLOT(accept()));

        QMetaObject::connectSlotsByName(dialog_task);
    } // setupUi

    void retranslateUi(QDialog *dialog_task)
    {
        dialog_task->setWindowTitle(QApplication::translate("dialog_task", "dialog_task", nullptr));
        pushButton->setText(QApplication::translate("dialog_task", "\347\241\256\345\256\232", nullptr));
        label->setText(QApplication::translate("dialog_task", "\345\267\262\345\256\214\346\210\220\357\274\232", nullptr));
        label_2->setText(QApplication::translate("dialog_task", "\345\272\224\345\256\214\346\210\220\357\274\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class dialog_task: public Ui_dialog_task {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_TASK_H
