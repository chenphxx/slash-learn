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
    QComboBox *language_choose;
    QLabel *language_label;
    QFrame *code_frame;
    QTextEdit *code_edit;
    QPushButton *code_copy;
    QFrame *comment_frame;
    QTextEdit *comment_edit;
    QPushButton *comment_copy;
    QPushButton *search_button;
    QLabel *label_logo;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1023, 629);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        search_box = new QLineEdit(centralwidget);
        search_box->setObjectName("search_box");
        search_box->setGeometry(QRect(30, 100, 481, 41));
        search_box->setStyleSheet(QString::fromUtf8(""));
        language_choose = new QComboBox(centralwidget);
        language_choose->addItem(QString());
        language_choose->addItem(QString());
        language_choose->addItem(QString());
        language_choose->addItem(QString());
        language_choose->addItem(QString());
        language_choose->addItem(QString());
        language_choose->addItem(QString());
        language_choose->addItem(QString());
        language_choose->addItem(QString());
        language_choose->addItem(QString());
        language_choose->setObjectName("language_choose");
        language_choose->setGeometry(QRect(890, 100, 101, 41));
        language_choose->setStyleSheet(QString::fromUtf8(""));
        language_label = new QLabel(centralwidget);
        language_label->setObjectName("language_label");
        language_label->setGeometry(QRect(770, 100, 111, 41));
        language_label->setStyleSheet(QString::fromUtf8(""));
        code_frame = new QFrame(centralwidget);
        code_frame->setObjectName("code_frame");
        code_frame->setGeometry(QRect(30, 160, 461, 411));
        code_frame->setFrameShape(QFrame::Shape::StyledPanel);
        code_frame->setFrameShadow(QFrame::Shadow::Raised);
        code_edit = new QTextEdit(code_frame);
        code_edit->setObjectName("code_edit");
        code_edit->setGeometry(QRect(10, 10, 441, 391));
        code_edit->setStyleSheet(QString::fromUtf8(""));
        code_copy = new QPushButton(code_frame);
        code_copy->setObjectName("code_copy");
        code_copy->setGeometry(QRect(410, 20, 31, 23));
        comment_frame = new QFrame(centralwidget);
        comment_frame->setObjectName("comment_frame");
        comment_frame->setGeometry(QRect(530, 160, 461, 411));
        comment_frame->setFrameShape(QFrame::Shape::StyledPanel);
        comment_frame->setFrameShadow(QFrame::Shadow::Raised);
        comment_edit = new QTextEdit(comment_frame);
        comment_edit->setObjectName("comment_edit");
        comment_edit->setGeometry(QRect(10, 10, 441, 391));
        comment_copy = new QPushButton(comment_frame);
        comment_copy->setObjectName("comment_copy");
        comment_copy->setGeometry(QRect(410, 20, 31, 23));
        search_button = new QPushButton(centralwidget);
        search_button->setObjectName("search_button");
        search_button->setGeometry(QRect(530, 100, 221, 41));
        search_button->setStyleSheet(QString::fromUtf8(""));
        label_logo = new QLabel(centralwidget);
        label_logo->setObjectName("label_logo");
        label_logo->setGeometry(QRect(30, 20, 211, 61));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1023, 20));
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
        language_choose->setItemText(0, QCoreApplication::translate("MainWindow", "Rust", nullptr));
        language_choose->setItemText(1, QCoreApplication::translate("MainWindow", "C/C++", nullptr));
        language_choose->setItemText(2, QCoreApplication::translate("MainWindow", "Go", nullptr));
        language_choose->setItemText(3, QCoreApplication::translate("MainWindow", "Python", nullptr));
        language_choose->setItemText(4, QCoreApplication::translate("MainWindow", "Lisp", nullptr));
        language_choose->setItemText(5, QCoreApplication::translate("MainWindow", "Assembly", nullptr));
        language_choose->setItemText(6, QCoreApplication::translate("MainWindow", "Java", nullptr));
        language_choose->setItemText(7, QCoreApplication::translate("MainWindow", "JavaScript", nullptr));
        language_choose->setItemText(8, QCoreApplication::translate("MainWindow", "HTML", nullptr));
        language_choose->setItemText(9, QCoreApplication::translate("MainWindow", "CSS", nullptr));

        language_label->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:14pt; font-weight:700; color:#5e17eb;\">Language:</span></p></body></html>", nullptr));
        code_copy->setText(QCoreApplication::translate("MainWindow", "\345\244\215\345\210\266", nullptr));
        comment_copy->setText(QCoreApplication::translate("MainWindow", "\345\244\215\345\210\266", nullptr));
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
