#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QTimer>
#include<QFileDialog>
#include<QFile>
#include <QClipboard>
#include <QApplication>
#include <QSqlDatabase>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


// 点击按钮连接到数据库
void MainWindow::on_search_button_clicked()
{
    qDebug() << QSqlDatabase::drivers();

    QString path =QFileDialog::getOpenFileName(this,"open");
    if(path.isEmpty() ==false)
    {
        // 文件对象
        QFile file(path);

        // 打开文件 只读方式 默认只识别utf8编码
        bool bRet  =file.open(QIODevice::ReadOnly);
        if(bRet == true)
        {
            // 读文件
            QByteArray array = file.readAll();
            // 显示到textEdit
            ui->code_edit->setText(QString(array));
        }
        file.close();
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

    // 在状态栏显示消息 持续一秒
    ui->statusbar->showMessage("内容已复制到剪贴板！", 1000);
}

// 复制comment_edit内容
void MainWindow::on_comment_copy_clicked()
{
    // 获取textEdit中的内容
    QString text = ui->comment_edit->toPlainText();

    // 将内容复制到剪贴板
    QClipboard *clipboard = QApplication::clipboard();
    clipboard->setText(text);

    // 在状态栏显示消息 持续一秒
    ui->statusbar->showMessage("内容已复制到剪贴板！", 1000);
}
