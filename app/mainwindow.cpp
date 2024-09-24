#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "new_data_dialog.h"
#include "code_highlighter.h"

#include <QTimer>  // 定时
#include <QClipboard>  // 复制到剪贴板
#include <QtSql>  // 数据库
#include <QDebug>  // 控制台输出
#include <QMessageBox>  // 消息弹窗
#include <QDialog>  // dialog


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    new code_highlighter(ui->code_edit->document());  // 应用代码高亮

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
unsigned int result_count = 0;  // 查询结果的数量
int number_index = 0;  // 索引编号


/**
 * @brief 切换数据库中的表
 *
 * @param index 选项
 * @return 无
 */
void MainWindow::on_language_switch_currentTextChanged(const QString &)
{
    table = ui->language_switch->currentText();  // 当前选择的选项
    ui->statusbar->showMessage(table, 1000);
    if (table == "C++")
        table = "CPP";
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
    if(index.isEmpty())
    {
        ui->code_edit->setText("没有输入任何关键词\n");
        ui->comment_edit->setText("没有输入任何关键词\n");
        result_count = 0;
        return;  // 结束当前查询
    }

    // 使用参数化查询, 防止SQL注入风险
    QString command = "SELECT * FROM " + table + " WHERE en_index = :index OR zh_index = :index";
    if (index == "000")  // 000表示查询所有数据
        command = "SELECT * FROM " + table;

    query.prepare(command);
    query.bindValue(":index", index);

    // 清空之前的查询结果
    ui->code_edit->clear();
    ui->comment_edit->clear();

    if(!query.exec())
    {
        // 查询失败时, 显示错误信息
        QString error = "查询失败: " + query.lastError().text();
        ui->code_edit->setText(error);
        ui->comment_edit->setText(error);
        return;
    }

    // 获取字段索引
    int code_snippet = query.record().indexOf("code_snippet");
    int zh_comment = query.record().indexOf("zh_comment");
    int count_index1 = query.record().indexOf("number_index");

    QTextCursor code_cursor(ui->code_edit->textCursor());
    QTextCursor comment_cursor(ui->comment_edit->textCursor());

    result_count = 0;  // 重置结果计数器
    while (query.next())
    {
        result_count++;
        QString code = query.value(code_snippet).toString();  // 获取 code 的值
        QString comment = query.value(zh_comment).toString();  // 获取 comment 的值
        number_index = query.value(count_index1).toInt();  // 获取计数索引的值

        // 使用 QTextCursor 插入内容
        code_cursor.insertText(code);
        code_cursor.insertText("\n---\n");  // 插入一条水平线 分隔多条结果

        comment_cursor.insertText(comment);
        comment_cursor.insertText("\n---\n");
    }
    if(result_count == 0)
    {
        code_cursor.insertText("没有查询到结果\n");
        comment_cursor.insertText("没有查询到结果\n");
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
    QString code = ui->code_edit->toPlainText();  // 获取code_edit的内容

    if (result_count == 0)
    {
        QMessageBox::information(this, "title", "没有任何查询结果, 无法保存");
    }
    else if (result_count == 1)
    {
        QString command = "UPDATE " + table + " SET code_snippet = :code WHERE number_index = :index";
        query.prepare(command);
        query.bindValue(":code", code);
        query.bindValue(":index", number_index);

        // 执行更新语句
        query.exec();
        if (query.exec())
            ui->statusbar->showMessage("代码已成功保存", 1000);
        else
            ui->statusbar->showMessage("代码保存失败: " + query.lastError().text(), 3000);
    }
    else
    {
        QMessageBox::information(this, "title", "检测到有多条查询结果, 请选择要保存至哪一条结果");
    }
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
    QString comment = ui->comment_edit->toPlainText();

    if (result_count == 0)
    {
        QMessageBox::information(this, "title", "没有检测到内容, 无法保存");
    }
    else if (result_count == 1)
    {
        QString command = "UPDATE " + table + " SET zh_comment = :comment WHERE number_index = :index";
        query.prepare(command);
        query.bindValue(":comment", comment);
        query.bindValue(":index", number_index);

        if (query.exec())
            ui->statusbar->showMessage("注释已成功保存", 1000);
        else
            ui->statusbar->showMessage("注释保存失败: " + query.lastError().text(), 3000);
    }
    else
    {
        QMessageBox::information(this, "title", "检测到有多条查询结果, 请选择要保存至哪一条结果");
    }
}

/**
 * @brief 清空code_edit中的内容
 *
 * @param NULL
 * @return 无
 */
void MainWindow::on_code_clear_clicked()
{
    ui->code_edit->clear();
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
    ui->comment_edit->clear();
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
    new_data_dialog new_dialog(table, this);  // 创建一个QDialog实例
    new_dialog.exec();  // 以模态形式显示对话框
}
