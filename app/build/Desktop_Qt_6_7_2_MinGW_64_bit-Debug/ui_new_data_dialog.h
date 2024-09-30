/********************************************************************************
** Form generated from reading UI file 'new_data_dialog.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEW_DATA_DIALOG_H
#define UI_NEW_DATA_DIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_new_data_dialog
{
public:
    QPushButton *new_data_save;
    QPushButton *new_data_cancel;
    QTextEdit *new_data_code_edit;
    QTextEdit *new_data_comment_edit;
    QLineEdit *new_data_zh_index;
    QLineEdit *new_data_en_index;
    QLabel *label;
    QLabel *label_2;
    QComboBox *language_switch;
    QLabel *label_3;
    QPushButton *new_data_delete;
    QLabel *label_4;
    QLineEdit *new_data_number_index;
    QPushButton *new_data_clear;
    QLabel *label_5;
    QLabel *label_6;

    void setupUi(QDialog *new_data_dialog)
    {
        if (new_data_dialog->objectName().isEmpty())
            new_data_dialog->setObjectName("new_data_dialog");
        new_data_dialog->resize(720, 421);
        new_data_save = new QPushButton(new_data_dialog);
        new_data_save->setObjectName("new_data_save");
        new_data_save->setGeometry(QRect(30, 310, 91, 41));
        QFont font;
        font.setFamilies({QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221")});
        font.setPointSize(12);
        font.setBold(false);
        new_data_save->setFont(font);
        new_data_save->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        new_data_save->setStyleSheet(QString::fromUtf8("border-radius:10px;\n"
"background-color: rgb(185, 187, 223);\n"
""));
        QIcon icon(QIcon::fromTheme(QIcon::ThemeIcon::DocumentSave));
        new_data_save->setIcon(icon);
        new_data_cancel = new QPushButton(new_data_dialog);
        new_data_cancel->setObjectName("new_data_cancel");
        new_data_cancel->setGeometry(QRect(130, 360, 91, 41));
        new_data_cancel->setFont(font);
        new_data_cancel->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        new_data_cancel->setStyleSheet(QString::fromUtf8("border-radius:10px;\n"
"background-color: rgb(185, 187, 223);"));
        QIcon icon1(QIcon::fromTheme(QIcon::ThemeIcon::SystemLogOut));
        new_data_cancel->setIcon(icon1);
        new_data_code_edit = new QTextEdit(new_data_dialog);
        new_data_code_edit->setObjectName("new_data_code_edit");
        new_data_code_edit->setGeometry(QRect(240, 40, 461, 181));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Cascadia Code")});
        font1.setPointSize(12);
        new_data_code_edit->setFont(font1);
        new_data_code_edit->viewport()->setProperty("cursor", QVariant(QCursor(Qt::CursorShape::IBeamCursor)));
        new_data_code_edit->setTabStopDistance(40.000000000000000);
        new_data_comment_edit = new QTextEdit(new_data_dialog);
        new_data_comment_edit->setObjectName("new_data_comment_edit");
        new_data_comment_edit->setGeometry(QRect(240, 250, 461, 161));
        new_data_comment_edit->setFont(font1);
        new_data_comment_edit->viewport()->setProperty("cursor", QVariant(QCursor(Qt::CursorShape::IBeamCursor)));
        new_data_comment_edit->setStyleSheet(QString::fromUtf8(""));
        new_data_comment_edit->setTabStopDistance(40.000000000000000);
        new_data_zh_index = new QLineEdit(new_data_dialog);
        new_data_zh_index->setObjectName("new_data_zh_index");
        new_data_zh_index->setGeometry(QRect(30, 180, 191, 41));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221")});
        font2.setPointSize(12);
        new_data_zh_index->setFont(font2);
        new_data_zh_index->setStyleSheet(QString::fromUtf8("border-radius:10px;"));
        new_data_en_index = new QLineEdit(new_data_dialog);
        new_data_en_index->setObjectName("new_data_en_index");
        new_data_en_index->setGeometry(QRect(30, 250, 191, 41));
        new_data_en_index->setFont(font1);
        new_data_en_index->setStyleSheet(QString::fromUtf8("border-radius:10px;"));
        label = new QLabel(new_data_dialog);
        label->setObjectName("label");
        label->setGeometry(QRect(30, 150, 101, 31));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Cascadia Code")});
        font3.setPointSize(14);
        label->setFont(font3);
        label->setStyleSheet(QString::fromUtf8("color: rgb(31, 171, 137);"));
        label_2 = new QLabel(new_data_dialog);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(30, 220, 101, 31));
        label_2->setFont(font3);
        label_2->setStyleSheet(QString::fromUtf8("color: rgb(31, 171, 137);"));
        language_switch = new QComboBox(new_data_dialog);
        QIcon icon2(QIcon::fromTheme(QIcon::ThemeIcon::DocumentNew));
        language_switch->addItem(icon2, QString());
        QIcon icon3(QIcon::fromTheme(QIcon::ThemeIcon::ViewRefresh));
        language_switch->addItem(icon3, QString());
        language_switch->setObjectName("language_switch");
        language_switch->setGeometry(QRect(30, 40, 191, 41));
        language_switch->setFont(font1);
        language_switch->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        language_switch->setStyleSheet(QString::fromUtf8("color: rgb(31, 171, 137);"));
        label_3 = new QLabel(new_data_dialog);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(30, 10, 101, 31));
        label_3->setFont(font3);
        label_3->setStyleSheet(QString::fromUtf8("color: rgb(31, 171, 137);"));
        new_data_delete = new QPushButton(new_data_dialog);
        new_data_delete->setObjectName("new_data_delete");
        new_data_delete->setGeometry(QRect(130, 310, 91, 41));
        new_data_delete->setFont(font);
        new_data_delete->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        new_data_delete->setStyleSheet(QString::fromUtf8("border-radius:10px;\n"
"background-color: rgb(185, 187, 223);"));
        QIcon icon4(QIcon::fromTheme(QIcon::ThemeIcon::EditDelete));
        new_data_delete->setIcon(icon4);
        label_4 = new QLabel(new_data_dialog);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(30, 80, 141, 31));
        label_4->setFont(font3);
        label_4->setStyleSheet(QString::fromUtf8("color: rgb(31, 171, 137);"));
        new_data_number_index = new QLineEdit(new_data_dialog);
        new_data_number_index->setObjectName("new_data_number_index");
        new_data_number_index->setGeometry(QRect(30, 110, 191, 41));
        new_data_number_index->setFont(font1);
        new_data_number_index->setStyleSheet(QString::fromUtf8("border-radius:10px;"));
        new_data_clear = new QPushButton(new_data_dialog);
        new_data_clear->setObjectName("new_data_clear");
        new_data_clear->setGeometry(QRect(30, 360, 91, 41));
        new_data_clear->setFont(font);
        new_data_clear->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        new_data_clear->setStyleSheet(QString::fromUtf8("border-radius:10px;\n"
"background-color: rgb(185, 187, 223);"));
        QIcon icon5(QIcon::fromTheme(QIcon::ThemeIcon::EditClear));
        new_data_clear->setIcon(icon5);
        label_5 = new QLabel(new_data_dialog);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(240, 10, 141, 31));
        label_5->setFont(font3);
        label_5->setStyleSheet(QString::fromUtf8("color: rgb(31, 171, 137);"));
        label_6 = new QLabel(new_data_dialog);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(240, 220, 121, 31));
        label_6->setFont(font3);
        label_6->setStyleSheet(QString::fromUtf8("color: rgb(31, 171, 137);"));
        QWidget::setTabOrder(new_data_number_index, new_data_zh_index);
        QWidget::setTabOrder(new_data_zh_index, new_data_en_index);
        QWidget::setTabOrder(new_data_en_index, new_data_code_edit);
        QWidget::setTabOrder(new_data_code_edit, new_data_comment_edit);
        QWidget::setTabOrder(new_data_comment_edit, language_switch);
        QWidget::setTabOrder(language_switch, new_data_save);
        QWidget::setTabOrder(new_data_save, new_data_delete);
        QWidget::setTabOrder(new_data_delete, new_data_cancel);

        retranslateUi(new_data_dialog);

        QMetaObject::connectSlotsByName(new_data_dialog);
    } // setupUi

    void retranslateUi(QDialog *new_data_dialog)
    {
        new_data_dialog->setWindowTitle(QCoreApplication::translate("new_data_dialog", "Dialog", nullptr));
        new_data_save->setText(QString());
        new_data_cancel->setText(QString());
        label->setText(QCoreApplication::translate("new_data_dialog", "<html><head/><body><p><span style=\" font-weight:700; font-style:italic;\">zh_index</span></p></body></html>", nullptr));
        label_2->setText(QCoreApplication::translate("new_data_dialog", "<html><head/><body><p><span style=\" font-weight:700; font-style:italic;\">en_index</span></p></body></html>", nullptr));
        language_switch->setItemText(0, QCoreApplication::translate("new_data_dialog", "New Table", nullptr));
        language_switch->setItemText(1, QCoreApplication::translate("new_data_dialog", "Refresh", nullptr));

        label_3->setText(QCoreApplication::translate("new_data_dialog", "<html><head/><body><p><span style=\" font-weight:700; font-style:italic;\">language</span></p></body></html>", nullptr));
        new_data_delete->setText(QString());
        label_4->setText(QCoreApplication::translate("new_data_dialog", "<html><head/><body><p><span style=\" font-weight:700; font-style:italic;\">number_index</span></p></body></html>", nullptr));
        new_data_clear->setText(QString());
        label_5->setText(QCoreApplication::translate("new_data_dialog", "<html><head/><body><p><span style=\" font-weight:700; font-style:italic;\">code_snippet</span></p></body></html>", nullptr));
        label_6->setText(QCoreApplication::translate("new_data_dialog", "<html><head/><body><p><span style=\" font-weight:700; font-style:italic;\">zh_comment</span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class new_data_dialog: public Ui_new_data_dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEW_DATA_DIALOG_H
