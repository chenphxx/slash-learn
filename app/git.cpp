#include "git.h"
#include "ui_git.h"
#include <QMessageBox>
#include <QDebug>


git::git(const QString &database_path, QWidget *parent)
    : QDialog(parent), ui(new Ui::git), path_receive(database_path)
{
    ui->setupUi(this);
}

git::~git()
{
    delete ui;
}


/**
 * @brief 推送更新到GitHub
 *
 * @param NULL
 * @return 无
 */
void git::on_git_push_clicked()
{
    QProcess git_process;
    QString git_directory = "C:/Users/chenphxx/Documents/Project/slash-learn";  // 指定打开git的地址

    git_process.setWorkingDirectory(git_directory);  // 设置工作目录为指定的 Git 仓库
    // git add
    git_process.start("git", QStringList() << "add" << path_receive);
    if (!git_process.waitForFinished())
    {
        QString err_msg = "git add failed: " + git_process.errorString();
        QMessageBox::information(this, "发生错误", err_msg);

        return;
    }

    // git commit -m "database update"
    git_process.start("git", QStringList() << "commit" << "-m" << "database update");
    if (!git_process.waitForFinished())
    {
        QString err_msg = "git commit failed: " + git_process.errorString();
        QMessageBox::information(this, "发生错误", err_msg);

        return;
    }

    // git push origin main
    git_process.start("git", QStringList() << "push" << "origin" << "main");
    if (!git_process.waitForFinished())
    {
        QString err_msg = "git push failed: " + git_process.errorString();
        QMessageBox::information(this, "发生错误", err_msg);

        return;
    }

    QMessageBox::information(this, "执行成功", "推送更新成功");
}

/**
 * @brief 拉取更新
 *
 * @param NULL
 * @return 无
 */
void git::on_git_pull_clicked()
{
    QProcess git_process;
    QString git_directory = "C:/Users/chenphxx/Documents/Project/slash-learn";  // 指定 Git 仓库的地址

    git_process.setWorkingDirectory(git_directory);  // 设置工作目录为指定的 Git 仓库

    // 1. git fetch origin
    git_process.start("git", QStringList() << "fetch" << "origin");
    if (!git_process.waitForFinished())
    {
        QString err_msg = "git fetch failed: " + git_process.errorString();
        QMessageBox::information(this, "发生错误", err_msg);

        return;
    }

    // 2. git pull origin main
    git_process.start("git", QStringList() << "pull" << "origin" << "main");
    if (!git_process.waitForFinished())
    {
        QString err_msg = "git pull failed: " + git_process.errorString();
        QMessageBox::information(this, "发生错误", err_msg);

        return;
    }

    QMessageBox::information(this, "执行成功", "拉取更新成功");
}
