#include "new_data.h"
#include "ui_new_data.h"
#include <QtSql>
#include <QMessageBox>


Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}


void Dialog::on_new_data_save_clicked()
{
    QSqlQuery query;
    QString zh_index = ui->new_data_zh_index->text();
    QString en_index = ui->new_data_en_index->text();
    QString code = ui->new_data_code_edit->toPlainText();
    QString comment = ui->new_data_comment_edit->toPlainText();

    QString command = "INSERT INTO C (zh_index, en_index, code_snippet, zh_comment) VALUES (:zh_index, :en_index, :code_comment, zh_comment)";
    query.prepare(command);
    query.bindValue(":zh_index", zh_index);
    query.bindValue(":en_index", en_index);
    query.bindValue(":code_snippet", code);
    query.bindValue(":zh_comment", comment);

    // 执行更新语句
    if (query.exec())
        QMessageBox::information(this, "title", "保存成功");
    else
        QMessageBox::warning(this, "title", "保存失败");
}

void Dialog::on_new_data_cancel_clicked()
{
    accept();  // 关闭窗口
}
