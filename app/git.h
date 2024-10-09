#ifndef GIT_H
#define GIT_H

#include <QDialog>
#include <QProcess>


namespace Ui
{
class git;
}

class git : public QDialog
{
    Q_OBJECT

public:
    explicit git(const QString &database_path, QWidget *parent = nullptr);
    ~git();

private slots:
    /**
     * @brief 推送更新到GitHub
     *
     * @param NULL
     * @return 无
     */
    void on_git_push_clicked();

    /**
     * @brief 拉取更新
     *
     * @param NULL
     * @return 无
     */
    void on_git_pull_clicked();

private:
    Ui::git *ui;
    QString path_receive;
};


#endif
