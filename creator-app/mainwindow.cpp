#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QTimer>
#include <QFileDialog>
#include <QFile>
#include <QClipboard>
#include <QApplication>
#include <QSqlDatabase>
#include <QtSql>
#include <QMessageBox>
#include <QDebug>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>
#include <QVariant>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    qDebug() << QSqlDatabase::drivers();  // 控制台输出支持的数据库驱动
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");  // 创建数据库对象

    // 数据库参数
    db.setHostName("127.0.0.1");
    db.setPort(3306);
    db.setDatabaseName("code_data");
    db.setUserName("root");
    db.setPassword("147819");

    bool ok = db.open();  // 打开数据库
    if (ok)
        ui->statusbar->showMessage("成功连接到数据库", 2000);
    else
        ui->statusbar->showMessage("数据库连接失败", 2000);
}

MainWindow::~MainWindow()
{
    delete ui;
}

QString language = "C";

// combobox 不同选择连接到不同的表
void MainWindow::on_language_switch_currentIndexChanged(int index)
{
    language = ui->language_switch->currentText();  // 当前选择的选项
    ui->statusbar->showMessage(language, 1000);
    if (language == "C++")
        language = "CPP";
}

// 搜索按钮
void MainWindow::on_search_button_clicked()
{
    QSqlQuery query;  // 创建一个查询对象

    QString index = ui->search_box->text();
    QString command = "SELECT * FROM " + language + " WHERE en_index = '" + index + "'"  + " OR zh_index = '" + index + "';";
    query.exec(command);  // 执行查询

    // 获取字段索引
    int code_snippet = query.record().indexOf("code_snippet");
    int zh_comment = query.record().indexOf("zh_comment");

    // 遍历结果集并输出
    while (query.next())
    {
        QString code = query.value(code_snippet).toString();  // 获取code的值
        QString comment = query.value(zh_comment).toString();  // 获取comment列的值

        qDebug() << "code:" << code << "\t" << "comment:" << comment;
        ui->code_edit->append(code);
        ui->comment_edit->append(comment);
    }
}

// 复制code_edit内容
void MainWindow::on_code_copy_clicked()
{
    // 获取code_edit中的内容
    QString text = ui->code_edit->toPlainText();

    // 将内容复制到剪贴板
    QClipboard *clipboard = QApplication::clipboard();
    clipboard->setText(text);

    ui->statusbar->showMessage("code已复制到剪贴板", 1000);
}

// 复制comment_edit内容
void MainWindow::on_comment_copy_clicked()
{
    QString text = ui->comment_edit->toPlainText();

    QClipboard *clipboard = QApplication::clipboard();
    clipboard->setText(text);

    ui->statusbar->showMessage("comment已复制到剪贴板", 1000);
}

// code_save 保存code
void MainWindow::on_code_save_clicked()
{
    ui->statusbar->showMessage("code已保存", 1000);
}

// comment_save 保存comment
void MainWindow::on_comment_save_clicked()
{
    ui->statusbar->showMessage("comment已保存", 1000);
}

// code_clear code清屏
void MainWindow::on_code_clear_clicked()
{
    ui->code_edit->setText("");
    ui->statusbar->showMessage("code清屏", 1000);
}

// comment_clear comment清屏
void MainWindow::on_comment_clear_clicked()
{
    ui->comment_edit->setText("");
    ui->statusbar->showMessage("comment清屏", 1000);
}

//  save_as
void MainWindow::on_save_as_clicked()
{
    ui->statusbar->showMessage("另存为", 1000);
}
