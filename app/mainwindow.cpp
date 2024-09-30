#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "new_data_dialog.h"
#include "query_execute.h"
#include "new_table.h"
#include "code_highlighter.h"


QString table = "C";  // 给定一个默认值
unsigned int result_count = 0;  // 查询结果的数量
int number_index = 0;  // 索引编号

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    new code_highlighter(ui->code_edit->document());  // 应用代码高亮
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");  // 创建数据库对象

    // 获取当前.exe路径并定位到sources文件夹
    QString exe_path = QCoreApplication::applicationDirPath();
    QDir project_path(exe_path);
    project_path.cdUp();  // 上一级目录
    project_path.cdUp();
    project_path.cdUp();
    QString default_path = project_path.filePath("sources/database/code_database.db");

    // 从 QSettings 中读取保存的数据库路径
    QSettings settings("code_database", "path");  // 注册表中的存储路径
    QString database_path = settings.value("DatabasePath", default_path).toString();

    db.setDatabaseName(database_path);  // 数据库路径
    if (!db.open())
    {
        QString errorMsg = "数据库连接失败: " + db.lastError().text();
        ui->statusbar->showMessage(errorMsg, 3000);

        return ;
    }
    init_table();
}

MainWindow::~MainWindow()
{
    delete ui;
}


/**
 * @brief 初始化技术栈列表
 *
 * @param NULL
 * @return 无
 */
void MainWindow::init_table()
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
 * @brief 点击切换数据库位置
 *
 * @param NULL
 * @return 无
 */
void MainWindow::on_change_database_path_clicked()
{
    QString dir = QFileDialog::getExistingDirectory(this, tr("选择数据库保存的位置"), "/code_database",
                                                    QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);

    if (!dir.isEmpty())
    {
        QString database_path = dir + "/code_database.db";
        // 存储位置到注册表以便下一次打开软件时也能读取
        QSettings settings("code_database", "path");
        settings.setValue("DatabasePath", database_path);

        QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");  // 创建数据库对象
        db.setDatabaseName(database_path);
        if (!db.open())
        {
            QString errorMsg = "数据库连接失败: " + db.lastError().text();
            ui->statusbar->showMessage(errorMsg, 2000);

            return ;
        }
        init_table();
    }
}

/**
 * @brief 切换数据库中的表
 *
 * @param NULL
 * @return 无
 */
void MainWindow::on_language_switch_activated(int)
{
    table = ui->language_switch->currentText();
    ui->statusbar->showMessage(ui->language_switch->currentText(), 2000);

    if (table == "C++")
        table = "CPP";
    if (table == "New Table")  // 打开new_table新建数据表
    {
        new_table *dialog = new new_table(this);
        dialog->setModal(false);
        dialog->setAttribute(Qt::WA_DeleteOnClose);
        connect(dialog, &new_table::send_table_name, this, &MainWindow::receive_table_name);  // 连接槽函数用于接收table_name
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
void MainWindow::receive_table_name(const QString &table_name)
{ 
    // 检查是否已经存在相同的项
    if (ui->language_switch->findText(table_name) == -1)
    {
        int count = ui->language_switch->count();  // 获取当前 ComboBox 中的选项数量

        QIcon icon = QApplication::style()->standardIcon(QStyle::SP_CommandLink);  // 图标
        ui->language_switch->insertItem(count, icon, table_name);  // 插入选项
        ui->language_switch->setCurrentText(table_name);
    }
}

/**
* @brief 搜索功能
*
* @param NULL
* @return 无
*/
void MainWindow::on_search_button_clicked()
{
    QSqlQuery query;  // 创建一个查询对象
    QString index = ui->search_box->text();  // 获取查询内容
    number_index = index.toInt();

    if(index.isEmpty())
    {
        ui->code_edit->setText("请输入关键词进行查找\n");
        ui->comment_edit->setText("请输入关键词进行查找\n");
        result_count = 0;
        return;  // 结束当前查询
    }

    if (number_index == 0)
    {
        // 使用参数化查询, 防止SQL注入风险
        table = ui->language_switch->currentText();
        QString command = "SELECT * FROM " + table + " WHERE en_index = :en_index OR zh_index = :zh_index";
        if (index == "000")  // 000表示查询所有数据
            command = "SELECT * FROM " + table;

        query.prepare(command);
        query.bindValue(":en_index", index);
        query.bindValue(":zh_index", index);
    }
    else
    {
        QString command = "SELECT * FROM " + table + " WHERE number_index = :number_index";
        if (index == "000")
            command = "SELECT * FROM " + table;

        query.prepare(command);
        query.bindValue(":number_index", number_index);
    }

    // 清空之前的查询结果
    ui->code_edit->clear();
    ui->comment_edit->clear();
    ui->number_index_browser->clear();

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
    QTextCursor number_index_cursor(ui->number_index_browser->textCursor());

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

        number_index_cursor.insertText(QString::number(number_index));
        number_index_cursor.insertText("\n---\n");
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

    ui->statusbar->showMessage("code已复制到剪贴板", 2000);
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

    ui->statusbar->showMessage("comment已复制到剪贴板", 2000);
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
        QMessageBox::information(this, "title", "没有查询到结果, 保存失败");
    }
    else if (result_count == 1)
    {
        QString command = "UPDATE " + table + " SET code_snippet = :code WHERE number_index = " + QString::number(number_index);
        query.prepare(command);
        query.bindValue(":code", code);

        // 执行更新语句
        query.exec();
        if (query.exec())
        {
            QMessageBox::information(this, "title", "保存成功");
        }
        else
        {
            QString error_msg = "保存失败: " + query.lastError().text();
            QMessageBox::information(this, "title", error_msg);
        }
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
        QMessageBox::information(this, "title", "没有查询到结果, 保存失败");
    }
    else if (result_count == 1)
    {
        QString command = "UPDATE " + table + " SET zh_comment = :comment WHERE number_index = " + QString::number(number_index);
        query.prepare(command);
        query.bindValue(":comment", comment);

        query.exec();
        if (query.exec())
        {
            QMessageBox::information(this, "title", "保存成功");
        }
        else
        {
            QString error_msg = "保存失败: " + query.lastError().text();
            QMessageBox::information(this, "title", error_msg);
        }
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
    ui->statusbar->showMessage("清空code", 2000);
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
    ui->statusbar->showMessage("清空comment", 2000);
}

/**
 * @brief 另存为界面
 *
 * @param NULL
 * @return 无
 */
void MainWindow::on_save_as_clicked()
{
    new_data_dialog *dialog = new new_data_dialog(table, this);  // 在堆上创建一个QDialog实例
    dialog->setModal(false);  // 设置为非模态
    dialog->setAttribute(Qt::WA_DeleteOnClose);  // 对话框关闭时自动删除对象
    dialog->show();  // 非模态形式 保持主窗口可访问
}

/**
 * @brief 执行查询语句
 *
 * @param NULL
 * @return 无
 */
void MainWindow::on_search_query_button_clicked()
{
    query_execute *dialog = new query_execute(this);
    dialog->setModal(false);
    dialog->setAttribute(Qt::WA_DeleteOnClose);
    dialog->show();
}
