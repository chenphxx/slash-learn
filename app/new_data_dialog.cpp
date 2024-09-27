#include "new_data_dialog.h"
#include "ui_new_data_dialog.h"
#include "code_highlighter.h"

#include <QtSql>
#include <QMessageBox>


// 新增的带QString参数的构造函数
new_data_dialog::new_data_dialog(const QString &tableValue, QWidget *parent)
    : QDialog(parent), ui(new Ui::new_data_dialog), table_receive(tableValue)
{
    ui->setupUi(this);

    new code_highlighter(ui->new_data_code_edit->document());  // 应用代码高亮

    ui->language_switch->setCurrentText(table_receive);  // 设置默认选项
    qDebug() << "传递过来的table值为: " << table_receive;
}

new_data_dialog::~new_data_dialog()
{
    delete ui;
}

/**
 * @brief 更新table_receive
 *
 * @param NULL
 * @return 无
 */
void new_data_dialog::on_language_switch_currentTextChanged(const QString &)
{
    table_receive = ui->language_switch->currentText();
    if (table_receive == "C++")
        table_receive = "CPP";
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
    if (zh_index.isEmpty())
    {
        QMessageBox::information(this, "title", "zh_index为空, 请输入");
        return ;
    }
    QString en_index = ui->new_data_en_index->text();
    if (en_index.isEmpty())
    {
        QMessageBox::information(this, "title", "en_index为空, 请输入");
        return ;
    }
    QString code = ui->new_data_code_edit->toPlainText();
    if (code.isEmpty())
    {
        QMessageBox::information(this, "title", "code为空, 请输入");
        return ;
    }
    QString comment = ui->new_data_comment_edit->toPlainText();
    if (comment.isEmpty())
    {
        QMessageBox::information(this, "title", "comment为空, 请输入");
        return ;
    }

    QString command = "INSERT INTO " + table_receive + " (zh_index, en_index, code_snippet, zh_comment) VALUES (:zh_index, :en_index, :code_snippet, :zh_comment)";
    query.prepare(command);
    query.bindValue(":zh_index", zh_index);
    query.bindValue(":en_index", en_index);
    query.bindValue(":code_snippet", code);
    query.bindValue(":zh_comment", comment);

    if (query.exec())
        QMessageBox::information(this, "title", "保存成功");
    else
        QMessageBox::information(this, "title", "保存失败");
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
 * @brief 关闭dialog
 *
 * @param NULL
 * @return 无
 */
void new_data_dialog::on_new_data_cancel_clicked()
{
    close();
}
