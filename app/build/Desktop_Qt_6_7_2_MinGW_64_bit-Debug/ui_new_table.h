/********************************************************************************
** Form generated from reading UI file 'new_table.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEW_TABLE_H
#define UI_NEW_TABLE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_new_table
{
public:
    QLineEdit *new_table_name;
    QPushButton *new_table_confirm;
    QPushButton *new_table_cancel;
    QLabel *label_2;

    void setupUi(QDialog *new_table)
    {
        if (new_table->objectName().isEmpty())
            new_table->setObjectName("new_table");
        new_table->resize(221, 120);
        new_table_name = new QLineEdit(new_table);
        new_table_name->setObjectName("new_table_name");
        new_table_name->setGeometry(QRect(10, 30, 201, 41));
        QFont font;
        font.setFamilies({QString::fromUtf8("Cascadia Code")});
        font.setPointSize(12);
        new_table_name->setFont(font);
        new_table_confirm = new QPushButton(new_table);
        new_table_confirm->setObjectName("new_table_confirm");
        new_table_confirm->setGeometry(QRect(10, 80, 91, 31));
        QFont font1;
        font1.setPointSize(12);
        new_table_confirm->setFont(font1);
        new_table_confirm->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        new_table_confirm->setStyleSheet(QString::fromUtf8("border-radius:10px;\n"
"background-color: rgb(185, 187, 223);"));
        new_table_cancel = new QPushButton(new_table);
        new_table_cancel->setObjectName("new_table_cancel");
        new_table_cancel->setGeometry(QRect(120, 80, 91, 31));
        new_table_cancel->setFont(font1);
        new_table_cancel->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        new_table_cancel->setStyleSheet(QString::fromUtf8("border-radius:10px;\n"
"background-color: rgb(185, 187, 223);"));
        label_2 = new QLabel(new_table);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(10, 0, 121, 31));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Cascadia Code")});
        font2.setPointSize(14);
        label_2->setFont(font2);
        label_2->setStyleSheet(QString::fromUtf8("color: rgb(31, 171, 137);"));

        retranslateUi(new_table);

        QMetaObject::connectSlotsByName(new_table);
    } // setupUi

    void retranslateUi(QDialog *new_table)
    {
        new_table->setWindowTitle(QCoreApplication::translate("new_table", "Dialog", nullptr));
        new_table_confirm->setText(QCoreApplication::translate("new_table", "\347\241\256\345\256\232", nullptr));
        new_table_cancel->setText(QCoreApplication::translate("new_table", "\345\217\226\346\266\210", nullptr));
        label_2->setText(QCoreApplication::translate("new_table", "<html><head/><body><p><span style=\" font-weight:700; font-style:italic;\">Table Name</span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class new_table: public Ui_new_table {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEW_TABLE_H
