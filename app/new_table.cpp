#include "new_table.h"
#include "ui_new_table.h"
#include <QtSql>
#include <QMessageBox>


new_table::new_table(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::new_table)
{
    ui->setupUi(this);
}

new_table::~new_table()
{
    delete ui;
}


QString table_name;

/**
 * @brief 确认按键
 *
 * @param NULL
 * @return 无
 */
void new_table::on_new_table_confirm_clicked()
{
    table_name = ui->new_table_name->text();
    QSqlQuery query;
    // 构造 SQL 语句，直接将表名插入到 SQL 字符串中
    QString command = QString
                      (
                          "CREATE TABLE IF NOT EXISTS %1 "
                          "("
                                "number_index INTEGER PRIMARY KEY AUTOINCREMENT, "
                                "zh_index VARCHAR(50), "
                                "en_index VARCHAR(50), "
                                "code_snippet TEXT, "
                                "zh_comment TEXT"
                            ")"
                        ).arg(table_name);
    query.prepare(command);

    if(!query.exec())
    {
        QString error = "新建表失败, 请重试:\n" + query.lastError().text();
        QMessageBox::information(this, "title", error);

        return;
    }
    emit send_table_name(table_name);  // 向mainwindow发送table_name
    QDialog::accept();  // 关闭对话框
}

/**
 * @brief 取消按键
 *
 * @param NULL
 * @return 无
 */
void new_table::on_new_table_cancel_clicked()
{
    close();
}
