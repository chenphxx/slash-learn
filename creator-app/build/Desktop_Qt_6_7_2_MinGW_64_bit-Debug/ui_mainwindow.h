/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLineEdit *search_box;
    QComboBox *language_switch;
    QLabel *language_label;
    QFrame *code_frame;
    QTextEdit *code_edit;
    QPushButton *code_copy;
    QPushButton *code_save;
    QPushButton *code_clear;
    QFrame *comment_frame;
    QTextEdit *comment_edit;
    QPushButton *comment_copy;
    QPushButton *comment_save;
    QPushButton *comment_clear;
    QPushButton *save_as;
    QPushButton *search_button;
    QLabel *label_logo;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1135, 658);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        search_box = new QLineEdit(centralwidget);
        search_box->setObjectName("search_box");
        search_box->setGeometry(QRect(10, 80, 621, 41));
        search_box->setStyleSheet(QString::fromUtf8(""));
        language_switch = new QComboBox(centralwidget);
        language_switch->addItem(QString());
        language_switch->addItem(QString());
        language_switch->addItem(QString());
        language_switch->addItem(QString());
        language_switch->addItem(QString());
        language_switch->addItem(QString());
        language_switch->addItem(QString());
        language_switch->addItem(QString());
        language_switch->addItem(QString());
        language_switch->addItem(QString());
        language_switch->addItem(QString());
        language_switch->setObjectName("language_switch");
        language_switch->setGeometry(QRect(1010, 80, 101, 41));
        language_switch->setStyleSheet(QString::fromUtf8(""));
        language_label = new QLabel(centralwidget);
        language_label->setObjectName("language_label");
        language_label->setGeometry(QRect(890, 80, 111, 41));
        language_label->setStyleSheet(QString::fromUtf8(""));
        code_frame = new QFrame(centralwidget);
        code_frame->setObjectName("code_frame");
        code_frame->setGeometry(QRect(10, 140, 551, 471));
        code_frame->setFrameShape(QFrame::Shape::StyledPanel);
        code_frame->setFrameShadow(QFrame::Shadow::Raised);
        code_edit = new QTextEdit(code_frame);
        code_edit->setObjectName("code_edit");
        code_edit->setGeometry(QRect(10, 10, 531, 451));
        code_edit->setStyleSheet(QString::fromUtf8(""));
        code_copy = new QPushButton(code_frame);
        code_copy->setObjectName("code_copy");
        code_copy->setGeometry(QRect(490, 20, 41, 23));
        code_save = new QPushButton(code_frame);
        code_save->setObjectName("code_save");
        code_save->setGeometry(QRect(490, 50, 41, 23));
        code_clear = new QPushButton(code_frame);
        code_clear->setObjectName("code_clear");
        code_clear->setGeometry(QRect(490, 80, 41, 23));
        comment_frame = new QFrame(centralwidget);
        comment_frame->setObjectName("comment_frame");
        comment_frame->setGeometry(QRect(580, 140, 541, 471));
        comment_frame->setFrameShape(QFrame::Shape::StyledPanel);
        comment_frame->setFrameShadow(QFrame::Shadow::Raised);
        comment_edit = new QTextEdit(comment_frame);
        comment_edit->setObjectName("comment_edit");
        comment_edit->setGeometry(QRect(10, 10, 521, 451));
        comment_copy = new QPushButton(comment_frame);
        comment_copy->setObjectName("comment_copy");
        comment_copy->setGeometry(QRect(480, 20, 41, 23));
        comment_save = new QPushButton(comment_frame);
        comment_save->setObjectName("comment_save");
        comment_save->setGeometry(QRect(480, 50, 41, 23));
        comment_clear = new QPushButton(comment_frame);
        comment_clear->setObjectName("comment_clear");
        comment_clear->setGeometry(QRect(480, 80, 41, 23));
        save_as = new QPushButton(comment_frame);
        save_as->setObjectName("save_as");
        save_as->setGeometry(QRect(480, 110, 41, 23));
        search_button = new QPushButton(centralwidget);
        search_button->setObjectName("search_button");
        search_button->setGeometry(QRect(650, 80, 221, 41));
        search_button->setStyleSheet(QString::fromUtf8(""));
        label_logo = new QLabel(centralwidget);
        label_logo->setObjectName("label_logo");
        label_logo->setGeometry(QRect(10, 10, 211, 61));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1135, 20));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
#if QT_CONFIG(whatsthis)
        search_box->setWhatsThis(QCoreApplication::translate("MainWindow", "<html><head/><body><p><br/></p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        search_box->setText(QCoreApplication::translate("MainWindow", "\345\234\250\350\277\231\351\207\214\350\276\223\345\205\245\350\246\201\346\237\245\346\211\276\347\232\204\345\206\205\345\256\271", nullptr));
        language_switch->setItemText(0, QCoreApplication::translate("MainWindow", "Rust", nullptr));
        language_switch->setItemText(1, QCoreApplication::translate("MainWindow", "C", nullptr));
        language_switch->setItemText(2, QCoreApplication::translate("MainWindow", "C++", nullptr));
        language_switch->setItemText(3, QCoreApplication::translate("MainWindow", "Go", nullptr));
        language_switch->setItemText(4, QCoreApplication::translate("MainWindow", "Python", nullptr));
        language_switch->setItemText(5, QCoreApplication::translate("MainWindow", "Lisp", nullptr));
        language_switch->setItemText(6, QCoreApplication::translate("MainWindow", "Assembly", nullptr));
        language_switch->setItemText(7, QCoreApplication::translate("MainWindow", "Java", nullptr));
        language_switch->setItemText(8, QCoreApplication::translate("MainWindow", "JavaScript", nullptr));
        language_switch->setItemText(9, QCoreApplication::translate("MainWindow", "HTML", nullptr));
        language_switch->setItemText(10, QCoreApplication::translate("MainWindow", "CSS", nullptr));

        language_label->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:14pt; font-weight:700; color:#5e17eb;\">Language:</span></p></body></html>", nullptr));
        code_copy->setText(QCoreApplication::translate("MainWindow", "\345\244\215\345\210\266", nullptr));
        code_save->setText(QCoreApplication::translate("MainWindow", "\344\277\235\345\255\230", nullptr));
        code_clear->setText(QCoreApplication::translate("MainWindow", "\346\270\205\345\261\217", nullptr));
        comment_copy->setText(QCoreApplication::translate("MainWindow", "\345\244\215\345\210\266", nullptr));
        comment_save->setText(QCoreApplication::translate("MainWindow", "\344\277\235\345\255\230", nullptr));
        comment_clear->setText(QCoreApplication::translate("MainWindow", "\346\270\205\345\261\217", nullptr));
        save_as->setText(QCoreApplication::translate("MainWindow", "\345\217\246\345\255\230\344\270\272", nullptr));
#if QT_CONFIG(tooltip)
        search_button->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p><br/></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        search_button->setText(QCoreApplication::translate("MainWindow", "\346\220\234\347\264\242", nullptr));
        label_logo->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:26pt; font-weight:700; font-style:italic; text-decoration: underline; color:#c1ff72;\">Code is Art.</span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
