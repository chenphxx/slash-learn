#include "new_data_dialog.h"
#include "ui_new_data_dialog.h"
#include "new_table.h"
#include "code_highlighter.h"

#include <QtSql>
#include <QMessageBox>


// 新增的带QString参数的构造函数
new_data_dialog::new_data_dialog(const QString &tableValue, QWidget *parent)
    : QDialog(parent), ui(new Ui::new_data_dialog), table_receive(tableValue)
{
    ui->setupUi(this);

    new code_highlighter(ui->new_data_code_edit->document());  // 应用代码高亮
    init_table();  // 更新列表选项
    ui->language_switch->setCurrentText(table_receive);  // 根据传递过来的值调整选项
}

new_data_dialog::~new_data_dialog()
{
    delete ui;
}


/**
 * @brief 初始化技术栈列表
 *
 * @param NULL
 * @return 无
 */
void new_data_dialog::init_table()
{
    QString command = "SELECT name FROM sqlite_master WHERE type='table' AND name NOT LIKE 'sqlite_%';";
    QSqlQuery query;
    if (!query.exec(command))
    {
        QString error_msg = "表名获取失败: " + query.lastError().text();
        QMessageBox::information(this, "title", error_msg);

        return ;
    }

    // 将除了"New Table" "Refresh"之外的选项都删除
    for (int i = ui->language_switch->count() - 1; i >= 0; --i)
    {
        if (ui->language_switch->itemText(i) != "New Table" && ui->language_switch->itemText(i) != "Refresh")
        {
            ui->language_switch->removeItem(i);
        }
    }

    while (query.next())
    {
        QString table_name = query.value(0).toString();
        int count = ui->language_switch->count();  // 获取当前 ComboBox 中的选项数量
        int position = (count >= 3) ? count - 3 : 0;  // 计算倒数第三个位置

        if (ui->language_switch->findText(table_name) == -1)
        {
            QIcon icon = QApplication::style()->standardIcon(QStyle::SP_CommandLink);  // 图标
            ui->language_switch->insertItem(position, icon, table_name);
            ui->language_switch->setCurrentText(query.value(0).toString());  // 设置默认值
        }
    }
}

/**
 * @brief 切换数据表
 *
 * @param NULL
 * @return 无
 */
void new_data_dialog::on_language_switch_activated(int)
{
    QString table = ui->language_switch->currentText();  // 获取从mainwindow传过来的值
    if (table == "C++")
        table = "CPP";
    if (table == "New Table")  // 使用new_table新建数据表
    {
        new_table *dialog = new new_table(this);
        dialog->setModal(false);
        dialog->setAttribute(Qt::WA_DeleteOnClose);
        connect(dialog, &new_table::send_table_name, this, &new_data_dialog::receive_table_name);  // 连接槽函数用于接收table_name
        dialog->show();
    }
    else if (table == "Refresh")
    {
        init_table();
    }
}

/**
 * @brief 从new_table接收table_name, 并插入到combobox
 *
 * @param table_name
 * @return 无
 */
void new_data_dialog::receive_table_name(const QString &table_name)
{ 
    // 检查是否已经存在相同的项
    if (ui->language_switch->findText(table_name) == -1)
    {
        int count = ui->language_switch->count();  // 获取当前 ComboBox 中的选项数量

        QIcon icon = QApplication::style()->standardIcon(QStyle::SP_CommandLink);  // 图标
        ui->language_switch->insertItem(count, icon, table_name);  // 插入选项
    }
}

/**
 * @brief 向数据库写入数据
 *
 * @param NULL
 * @return 无
 */
void new_data_dialog::on_new_data_save_clicked()
{
    QSqlQuery query;

    QString zh_index = ui->new_data_zh_index->text();
    QString en_index = ui->new_data_en_index->text();
    QString code = ui->new_data_code_edit->toPlainText();
    QString comment = ui->new_data_comment_edit->toPlainText();
    QString number_index = ui->new_data_number_index->text();
    QString command;

    // 是否输入了数据
    bool zh_flag = !zh_index.isEmpty();
    bool en_flag = !en_index.isEmpty();
    bool code_flag = !code.isEmpty();
    bool comment_flag = !comment.isEmpty();

    if (zh_flag && en_flag && code_flag && comment_flag)
    {
        if (!number_index.isEmpty() && number_index.toInt() != 0)
            command = "UPDATE " + table_receive + " SET zh_index = :zh_index, en_index = :en_index, code_snippet = :code_snippet, "
                                                  "zh_comment = :zh_comment WHERE number_index = " + number_index + " ;";
        else
            command = "INSERT INTO " + table_receive + " (zh_index, en_index, code_snippet, zh_comment) "
                                                       "VALUES (:zh_index, :en_index, :code_snippet, :zh_comment)";
    }
    else
    {
        QMessageBox::information(this, "title", "有数据未输入");
        return ;
    }

    query.prepare(command);
    query.bindValue(":zh_index", zh_index);
    query.bindValue(":en_index", en_index);
    query.bindValue(":code_snippet", code);
    query.bindValue(":zh_comment", comment);
    if (query.exec())
        QMessageBox::information(this, "title", "保存/修改成功");
    else
        QMessageBox::information(this, "title", "保存/修改失败");
}

/**
 * @brief 删除数据
 *
 * @param NULL
 * @return 无
 */
void new_data_dialog::on_new_data_delete_clicked()
{
    QSqlQuery query;

    QString index_type = "number_index";
    QString index = ui->new_data_number_index->text();

    QString command = "DELETE FROM " + table_receive + " WHERE " + index_type + " = :index";
    // 判断用户输入的 index 是什么类型
    if(index.isEmpty())
    {
        index = ui->new_data_zh_index->text();
        index_type = "zh_index";
        if(index.isEmpty())
        {
            index = ui->new_data_en_index->text();
            index_type = "en_index";
            if (index.isEmpty())
            {
                QMessageBox::information(this, "title", "请输入要删除的数据信息");
                return ;
            }
        }
    }
    query.prepare(command);
    if(index_type == "number_index")
        query.bindValue(":index", index.toInt());
    else
        query.bindValue(":index", index);

    if(query.exec())
        QMessageBox::information(this, "title", "删除成功");
    else
        QMessageBox::information(this, "title", "删除失败, 请重试");
}

/**
 * @brief 清空输入框
 *
 * @param NULL
 * @return 无
 */
void new_data_dialog::on_new_data_clear_clicked()
{
    ui->new_data_number_index->clear();
    ui->new_data_zh_index->clear();
    ui->new_data_en_index->clear();
    ui->new_data_code_edit->clear();
    ui->new_data_comment_edit->clear();
}

/**
 * @brief 关闭dialog
 *
 * @param NULL
 * @return 无
 */
void new_data_dialog::on_new_data_cancel_clicked()
{
    close();
}
