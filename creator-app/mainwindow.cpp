#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QTimer>
#include <QClipboard>
#include <QApplication>
#include <QSqlDatabase>
#include <QtSql>
#include <QDebug>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>
#include <QVariant>
#include <stdlib.h>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");  // 创建数据库对象

    // 数据库参数
    db.setHostName("127.0.0.1");
    db.setPort(3306);
    db.setDatabaseName("code_data");
    db.setUserName("root");
    db.setPassword("147819");
    if (db.open())
        ui->statusbar->showMessage("成功连接到数据库", 2000);
    else
        ui->statusbar->showMessage("数据库连接失败", 2000);
}

MainWindow::~MainWindow()
{
    delete ui;
}

QString table = "C";  // 给定一个默认值
bool table_change_flag = 0;  // 是否选择了新的语言

/**
 * @brief 对字符串中的"和\进行转义
 *
 * @param input
 * @return 无
 */
void MainWindow::escape_string(QString& input)
{
    QString escaped_string;

    for (QChar ch : input) {
        if (ch == '\"' || ch == '\\')
        {
            escaped_string.append('\\');  // 添加转义字符
        }
        escaped_string.append(ch);  // 添加原字符
    }

    input = escaped_string;  // 将转义后的字符串赋回原输入
}

/**
 * @brief 切换数据库中的表
 *
 * @param index 选项
 * @return 无
 */
void MainWindow::on_language_switch_currentIndexChanged(int index)
{
    table = ui->language_switch->currentText();  // 当前选择的选项
    ui->statusbar->showMessage(table, 1000);
    if (table == "C++")
        table = "CPP";
    table_change_flag = 1;
}

/**
* @brief 根据输入的内容进行搜索
*
* @param NULL
* @return 无
*/
void MainWindow::on_search_button_clicked()
{
    QSqlQuery query;  // 创建一个查询对象
    QString index = ui->search_box->text();  // 获取查询内容

    // 使用参数化查询, 防止SQL注入风险
    QString command = "SELECT * FROM " + table + " WHERE en_index = :index OR zh_index = :index";
    query.prepare(command);
    query.bindValue(":index", index);
    query.exec();

    // 获取字段索引
    int code_snippet = query.record().indexOf("code_snippet");
    int zh_comment = query.record().indexOf("zh_comment");

    // 如果选择了新的语言表, 就清空之前的查询结果
    if (table_change_flag)
    {
        ui->code_edit->setText("");
        ui->comment_edit->setText("");
        table_change_flag = 0;
    }

    // 遍历结果集并输出
    while (query.next())
    {
        QString code = query.value(code_snippet).toString();  // 获取code的值
        QString comment = query.value(zh_comment).toString();  // 获取comment的值

        ui->code_edit->setPlainText(code);
        ui->comment_edit->setPlainText(comment);
    }
}

/**
 * @brief 复制code_edit中的内容
 *
 * @param NULL
 * @return 无
 */
void MainWindow::on_code_copy_clicked()
{
    // 获取code_edit中的内容
    QString code = ui->code_edit->toPlainText();

    // 将内容复制到剪贴板
    QClipboard *clipboard = QApplication::clipboard();
    clipboard->setText(code);

    ui->statusbar->showMessage("code已复制到剪贴板", 1000);
}

/**
 * @brief 复制comment_edit中的内容
 *
 * @param NULL
 * @return 无
 */
void MainWindow::on_comment_copy_clicked()
{
    QString comment = ui->comment_edit->toPlainText();

    QClipboard *clipboard = QApplication::clipboard();
    clipboard->setText(comment);

    ui->statusbar->showMessage("comment已复制到剪贴板", 1000);
}

/**
 * @brief 保存code_edit中的内容到数据库
 *
 * @param NULL
 * @return 无
 */
void MainWindow::on_code_save_clicked()
{
    QSqlQuery query;
    QString index = ui->search_box->text();  // 获取查询内容
    QString code = ui->code_edit->toPlainText();  // 获取code_edit的内容

    QString command = "UPDATE " + table + " SET code_snippet = :code WHERE zh_index = :index OR en_index = :index";
    query.prepare(command);
    query.bindValue(":code", code);
    query.bindValue(":index", index);

    // 执行更新语句
    query.exec();
    if (query.exec())
        ui->statusbar->showMessage("代码已成功保存", 1000);
    else
        ui->statusbar->showMessage("代码保存失败: " + query.lastError().text(), 3000);
}

/**
 * @brief 保存comment_edit中的内容到数据库
 *
 * @param NULL
 * @return 无
 */
void MainWindow::on_comment_save_clicked()
{
    QSqlQuery query;
    QString index = ui->search_box->text();
    QString comment = ui->comment_edit->toPlainText();

    QString command = "UPDATE " + table + " SET zh_comment = :comment WHERE zh_index = :index OR en_index = :index";
    query.prepare(command);
    query.bindValue(":comment", comment);
    query.bindValue(":index", index);

    query.exec();
    if (query.exec())
        ui->statusbar->showMessage("注释已成功保存", 1000);
    else
        ui->statusbar->showMessage("注释保存失败: " + query.lastError().text(), 3000);
}

/**
 * @brief 清空code_edit中的内容
 *
 * @param NULL
 * @return 无
 */
void MainWindow::on_code_clear_clicked()
{
    ui->code_edit->setText("");
    ui->statusbar->showMessage("code清屏", 1000);
}

/**
 * @brief 清空comment_edit中的内容
 *
 * @param NULL
 * @return 无
 */
void MainWindow::on_comment_clear_clicked()
{
    ui->comment_edit->setText("");
    ui->statusbar->showMessage("comment清屏", 1000);
}

/**
 * @brief 将code_edit和comment_edit另存为新的数据
 *
 * @param NULL
 * @return 无
 */
void MainWindow::on_save_as_clicked()
{
    ui->statusbar->showMessage("另存为", 1000);
}
