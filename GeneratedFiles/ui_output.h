/********************************************************************************
** Form generated from reading UI file 'output.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OUTPUT_H
#define UI_OUTPUT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_output
{
public:
    QTextBrowser *textBrowser;

    void setupUi(QWidget *output)
    {
        if (output->objectName().isEmpty())
            output->setObjectName(QStringLiteral("output"));
        output->resize(800, 800);
        textBrowser = new QTextBrowser(output);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        textBrowser->setGeometry(QRect(20, 70, 600, 600));

        retranslateUi(output);

        QMetaObject::connectSlotsByName(output);
    } // setupUi

    void retranslateUi(QWidget *output)
    {
        output->setWindowTitle(QApplication::translate("output", "output", nullptr));
    } // retranslateUi

};

namespace Ui {
    class output: public Ui_output {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OUTPUT_H
