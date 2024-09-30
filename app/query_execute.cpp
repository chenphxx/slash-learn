#include "query_execute.h"
#include "ui_query_execute.h"
#include <QtSql>
#include <QMessageBox>


query_execute::query_execute(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::query_execute)
{
    ui->setupUi(this);
}

query_execute::~query_execute()
{
    delete ui;
}


/**
 * @brief 执行语句
 *
 * @param NULL
 * @return 无
 */
void query_execute::on_query_execute_button_clicked()
{
    QSqlQuery query;
    QString command = ui->query_edit->toPlainText();

    query.prepare(command);

    ui->result_browser->clear();  // 清空之前的结果
    if(!query.exec())
    {
        QString error = "执行失败, 请重试:\n" + query.lastError().text();
        ui->result_browser->setText(error);

        return;
    }

    QString result;
    int column_count = query.record().count();  // 获取查询的列数

    // 遍历查询结果, 将每一行数据追加到 result 中
    while (query.next())
    {
        for (int i = 0; i < column_count; ++i)
        {
            QString value = query.value(i).toString();
            result += value + "\n";
        }
        result += "---\n";  // 行与行之间添加分隔
    }
    ui->result_browser->append(result);
}

/**
 * @brief 关闭窗口
 *
 * @param NULL
 * @return 无
 */
void query_execute::on_query_cacel_button_clicked()
{
    close();
}
