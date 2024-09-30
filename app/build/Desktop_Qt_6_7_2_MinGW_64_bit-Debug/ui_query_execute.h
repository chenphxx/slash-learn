/********************************************************************************
** Form generated from reading UI file 'query_execute.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QUERY_EXECUTE_H
#define UI_QUERY_EXECUTE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_query_execute
{
public:
    QTextEdit *query_edit;
    QPushButton *query_execute_button;
    QPushButton *query_cacel_button;
    QTextBrowser *result_browser;
    QLabel *label_4;
    QLabel *label_5;

    void setupUi(QDialog *query_execute)
    {
        if (query_execute->objectName().isEmpty())
            query_execute->setObjectName("query_execute");
        query_execute->resize(502, 505);
        query_edit = new QTextEdit(query_execute);
        query_edit->setObjectName("query_edit");
        query_edit->setGeometry(QRect(10, 300, 481, 131));
        QFont font;
        font.setFamilies({QString::fromUtf8("Cascadia Code")});
        font.setPointSize(12);
        query_edit->setFont(font);
        query_edit->viewport()->setProperty("cursor", QVariant(QCursor(Qt::CursorShape::IBeamCursor)));
        query_execute_button = new QPushButton(query_execute);
        query_execute_button->setObjectName("query_execute_button");
        query_execute_button->setGeometry(QRect(10, 440, 231, 51));
        query_execute_button->setFont(font);
        query_execute_button->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        query_execute_button->setStyleSheet(QString::fromUtf8("border-radius:10px;\n"
"background-color: rgb(185, 187, 223);"));
        query_cacel_button = new QPushButton(query_execute);
        query_cacel_button->setObjectName("query_cacel_button");
        query_cacel_button->setGeometry(QRect(260, 440, 231, 51));
        query_cacel_button->setFont(font);
        query_cacel_button->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        query_cacel_button->setStyleSheet(QString::fromUtf8("border-radius:10px;\n"
"background-color: rgb(185, 187, 223);"));
        result_browser = new QTextBrowser(query_execute);
        result_browser->setObjectName("result_browser");
        result_browser->setGeometry(QRect(10, 40, 481, 231));
        result_browser->setFont(font);
        label_4 = new QLabel(query_execute);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(10, 10, 71, 31));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Cascadia Code")});
        font1.setPointSize(14);
        label_4->setFont(font1);
        label_4->setStyleSheet(QString::fromUtf8("color: rgb(31, 171, 137);"));
        label_5 = new QLabel(query_execute);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(10, 270, 61, 31));
        label_5->setFont(font1);
        label_5->setStyleSheet(QString::fromUtf8("color: rgb(31, 171, 137);"));

        retranslateUi(query_execute);

        QMetaObject::connectSlotsByName(query_execute);
    } // setupUi

    void retranslateUi(QDialog *query_execute)
    {
        query_execute->setWindowTitle(QCoreApplication::translate("query_execute", "Dialog", nullptr));
        query_execute_button->setText(QCoreApplication::translate("query_execute", "\346\211\247\350\241\214\350\257\255\345\217\245", nullptr));
        query_cacel_button->setText(QCoreApplication::translate("query_execute", "\345\217\226\346\266\210", nullptr));
        label_4->setText(QCoreApplication::translate("query_execute", "<html><head/><body><p><span style=\" font-weight:700; font-style:italic;\">result</span></p></body></html>", nullptr));
        label_5->setText(QCoreApplication::translate("query_execute", "<html><head/><body><p><span style=\" font-weight:700; font-style:italic;\">query</span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class query_execute: public Ui_query_execute {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QUERY_EXECUTE_H
