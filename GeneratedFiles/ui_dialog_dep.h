/********************************************************************************
** Form generated from reading UI file 'dialog_dep.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_DEP_H
#define UI_DIALOG_DEP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_dialog_dep
{
public:
    QListWidget *listWidget;
    QPushButton *pushButton;

    void setupUi(QWidget *dialog_dep)
    {
        if (dialog_dep->objectName().isEmpty())
            dialog_dep->setObjectName(QStringLiteral("dialog_dep"));
        dialog_dep->resize(600, 800);
        listWidget = new QListWidget(dialog_dep);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        listWidget->setGeometry(QRect(40, 20, 470, 670));
        pushButton = new QPushButton(dialog_dep);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(428, 739, 101, 31));

        retranslateUi(dialog_dep);
        //QObject::connect(pushButton, SIGNAL(clicked()), dialog_dep, SLOT(on_pushButton_clicked()));

        QMetaObject::connectSlotsByName(dialog_dep);
    } // setupUi

    void retranslateUi(QWidget *dialog_dep)
    {
        dialog_dep->setWindowTitle(QApplication::translate("dialog_dep", "dialog_dep", nullptr));
        pushButton->setText(QApplication::translate("dialog_dep", "OK", nullptr));
    } // retranslateUi

};

namespace Ui {
    class dialog_dep: public Ui_dialog_dep {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_DEP_H
