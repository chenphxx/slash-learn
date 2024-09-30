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
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
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
    QTextBrowser *number_index_browser;
    QPushButton *change_database_path;
    QPushButton *search_query_button;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1135, 665);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        search_box = new QLineEdit(centralwidget);
        search_box->setObjectName("search_box");
        search_box->setGeometry(QRect(120, 80, 471, 41));
        QFont font;
        font.setFamilies({QString::fromUtf8("Cascadia Code")});
        font.setPointSize(12);
        search_box->setFont(font);
        search_box->setStyleSheet(QString::fromUtf8("border-radius:10px;"));
        language_switch = new QComboBox(centralwidget);
        QIcon icon(QIcon::fromTheme(QString::fromUtf8("document-new")));
        language_switch->addItem(icon, QString());
        QIcon icon1(QIcon::fromTheme(QIcon::ThemeIcon::ViewRefresh));
        language_switch->addItem(icon1, QString());
        language_switch->setObjectName("language_switch");
        language_switch->setGeometry(QRect(980, 80, 141, 41));
        language_switch->setFont(font);
        language_switch->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        language_switch->setStyleSheet(QString::fromUtf8("color: rgb(31, 171, 137);"));
        language_label = new QLabel(centralwidget);
        language_label->setObjectName("language_label");
        language_label->setGeometry(QRect(830, 80, 141, 41));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Cascadia Code")});
        font1.setPointSize(20);
        font1.setBold(true);
        language_label->setFont(font1);
        language_label->setStyleSheet(QString::fromUtf8(""));
        code_frame = new QFrame(centralwidget);
        code_frame->setObjectName("code_frame");
        code_frame->setGeometry(QRect(10, 140, 511, 481));
        code_frame->setStyleSheet(QString::fromUtf8(""));
        code_frame->setFrameShape(QFrame::Shape::StyledPanel);
        code_frame->setFrameShadow(QFrame::Shadow::Raised);
        code_edit = new QTextEdit(code_frame);
        code_edit->setObjectName("code_edit");
        code_edit->setGeometry(QRect(0, 0, 511, 481));
        code_edit->setFont(font);
        code_edit->viewport()->setProperty("cursor", QVariant(QCursor(Qt::CursorShape::IBeamCursor)));
        code_edit->setTabStopDistance(40.000000000000000);
        code_copy = new QPushButton(code_frame);
        code_copy->setObjectName("code_copy");
        code_copy->setGeometry(QRect(450, 10, 51, 31));
        QFont font2;
        font2.setPointSize(12);
        code_copy->setFont(font2);
        code_copy->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        code_copy->setStyleSheet(QString::fromUtf8("background-color: rgb(185, 187, 223);\n"
"color: rgb(185, 187, 223);"));
        QIcon icon2(QIcon::fromTheme(QIcon::ThemeIcon::EditCopy));
        code_copy->setIcon(icon2);
        code_save = new QPushButton(code_frame);
        code_save->setObjectName("code_save");
        code_save->setGeometry(QRect(450, 50, 51, 31));
        code_save->setFont(font2);
        code_save->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        code_save->setStyleSheet(QString::fromUtf8("background-color: rgb(185, 187, 223);"));
        QIcon icon3(QIcon::fromTheme(QIcon::ThemeIcon::DocumentSave));
        code_save->setIcon(icon3);
        code_clear = new QPushButton(code_frame);
        code_clear->setObjectName("code_clear");
        code_clear->setGeometry(QRect(450, 90, 51, 31));
        code_clear->setFont(font2);
        code_clear->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        code_clear->setStyleSheet(QString::fromUtf8("background-color: rgb(185, 187, 223);"));
        QIcon icon4(QIcon::fromTheme(QIcon::ThemeIcon::EditClear));
        code_clear->setIcon(icon4);
        comment_frame = new QFrame(centralwidget);
        comment_frame->setObjectName("comment_frame");
        comment_frame->setGeometry(QRect(530, 140, 501, 481));
        comment_frame->setStyleSheet(QString::fromUtf8(""));
        comment_frame->setFrameShape(QFrame::Shape::StyledPanel);
        comment_frame->setFrameShadow(QFrame::Shadow::Raised);
        comment_edit = new QTextEdit(comment_frame);
        comment_edit->setObjectName("comment_edit");
        comment_edit->setGeometry(QRect(0, 0, 501, 481));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Cascadia Code")});
        font3.setPointSize(12);
        font3.setBold(false);
        comment_edit->setFont(font3);
        comment_edit->viewport()->setProperty("cursor", QVariant(QCursor(Qt::CursorShape::IBeamCursor)));
        comment_edit->setLineWidth(1);
        comment_edit->setTabStopDistance(40.000000000000000);
        comment_copy = new QPushButton(comment_frame);
        comment_copy->setObjectName("comment_copy");
        comment_copy->setGeometry(QRect(440, 10, 51, 31));
        comment_copy->setFont(font2);
        comment_copy->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        comment_copy->setStyleSheet(QString::fromUtf8("background-color: rgb(185, 187, 223);"));
        comment_copy->setIcon(icon2);
        comment_save = new QPushButton(comment_frame);
        comment_save->setObjectName("comment_save");
        comment_save->setGeometry(QRect(440, 50, 51, 31));
        comment_save->setFont(font2);
        comment_save->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        comment_save->setStyleSheet(QString::fromUtf8("background-color: rgb(185, 187, 223);"));
        comment_save->setIcon(icon3);
        comment_clear = new QPushButton(comment_frame);
        comment_clear->setObjectName("comment_clear");
        comment_clear->setGeometry(QRect(440, 90, 51, 31));
        comment_clear->setFont(font2);
        comment_clear->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        comment_clear->setStyleSheet(QString::fromUtf8("background-color: rgb(185, 187, 223);"));
        comment_clear->setIcon(icon4);
        save_as = new QPushButton(comment_frame);
        save_as->setObjectName("save_as");
        save_as->setGeometry(QRect(440, 130, 51, 31));
        QFont font4;
        font4.setPointSize(10);
        save_as->setFont(font4);
        save_as->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        save_as->setStyleSheet(QString::fromUtf8("background-color: rgb(185, 187, 223);"));
        QIcon icon5(QIcon::fromTheme(QIcon::ThemeIcon::DocumentSaveAs));
        save_as->setIcon(icon5);
        search_button = new QPushButton(centralwidget);
        search_button->setObjectName("search_button");
        search_button->setGeometry(QRect(600, 80, 101, 41));
        QFont font5;
        font5.setPointSize(9);
        search_button->setFont(font5);
        search_button->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        search_button->setStyleSheet(QString::fromUtf8("border-radius:10px;\n"
"background-color: rgb(185, 187, 223);\n"
""));
        QIcon icon6(QIcon::fromTheme(QIcon::ThemeIcon::SystemSearch));
        search_button->setIcon(icon6);
        label_logo = new QLabel(centralwidget);
        label_logo->setObjectName("label_logo");
        label_logo->setGeometry(QRect(10, 10, 261, 61));
        label_logo->setFont(font);
        label_logo->setStyleSheet(QString::fromUtf8(""));
        number_index_browser = new QTextBrowser(centralwidget);
        number_index_browser->setObjectName("number_index_browser");
        number_index_browser->setGeometry(QRect(1040, 140, 81, 481));
        QFont font6;
        font6.setFamilies({QString::fromUtf8("Cascadia Code")});
        font6.setPointSize(14);
        number_index_browser->setFont(font6);
        change_database_path = new QPushButton(centralwidget);
        change_database_path->setObjectName("change_database_path");
        change_database_path->setGeometry(QRect(10, 80, 101, 41));
        change_database_path->setFont(font5);
        change_database_path->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        change_database_path->setStyleSheet(QString::fromUtf8("border-radius:10px;\n"
"background-color: rgb(185, 187, 223);\n"
""));
        QIcon icon7(QIcon::fromTheme(QIcon::ThemeIcon::FolderNew));
        change_database_path->setIcon(icon7);
        search_query_button = new QPushButton(centralwidget);
        search_query_button->setObjectName("search_query_button");
        search_query_button->setGeometry(QRect(710, 80, 101, 41));
        search_query_button->setFont(font5);
        search_query_button->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        search_query_button->setStyleSheet(QString::fromUtf8("border-radius:10px;\n"
"background-color: rgb(185, 187, 223);\n"
""));
        search_query_button->setIcon(icon6);
        MainWindow->setCentralWidget(centralwidget);
        search_box->raise();
        language_switch->raise();
        language_label->raise();
        code_frame->raise();
        label_logo->raise();
        comment_frame->raise();
        number_index_browser->raise();
        search_button->raise();
        change_database_path->raise();
        search_query_button->raise();
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1135, 20));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);
        QObject::connect(search_box, &QLineEdit::returnPressed, search_button, qOverload<>(&QPushButton::click));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
#if QT_CONFIG(whatsthis)
        search_box->setWhatsThis(QCoreApplication::translate("MainWindow", "<html><head/><body><p><br/></p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        search_box->setText(QCoreApplication::translate("MainWindow", "000", nullptr));
        language_switch->setItemText(0, QCoreApplication::translate("MainWindow", "New Table", nullptr));
        language_switch->setItemText(1, QCoreApplication::translate("MainWindow", "Refresh", nullptr));

        language_label->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:16pt; color:#5e17eb;\">Tech-Stack:</span></p></body></html>", nullptr));
        code_copy->setText(QString());
        code_save->setText(QString());
        code_clear->setText(QString());
        comment_copy->setText(QString());
        comment_save->setText(QString());
        comment_clear->setText(QString());
        save_as->setText(QString());
#if QT_CONFIG(tooltip)
        search_button->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>\346\220\234\347\264\242</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        search_button->setText(QCoreApplication::translate("MainWindow", "\347\264\242\345\274\225", nullptr));
        label_logo->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:26pt; font-weight:700; font-style:italic; text-decoration: underline; color:#1fab89;\">Code is Art.</span></p></body></html>", nullptr));
#if QT_CONFIG(tooltip)
        change_database_path->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>\345\210\207\346\215\242\346\225\260\346\215\256\345\272\223\344\275\215\347\275\256</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        change_database_path->setText(QCoreApplication::translate("MainWindow", "\346\225\260\346\215\256\345\272\223\345\210\207\346\215\242", nullptr));
#if QT_CONFIG(tooltip)
        search_query_button->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>\346\220\234\347\264\242</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        search_query_button->setText(QCoreApplication::translate("MainWindow", "\350\257\255\345\217\245", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
