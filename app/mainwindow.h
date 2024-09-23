#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <QMainWindow>


QT_BEGIN_NAMESPACE
namespace Ui
{
    class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

    public:
        MainWindow(QWidget *parent = nullptr);
        ~MainWindow();

        /**
         * @brief 对字符串中的"和\进行转义
         *
         * @param input 目标字符串
         * @return 无
         */
        void escape_string(QString &input);

    private slots:
        /**
         * @brief 搜索
         *
         * @param NULL
         * @return 无
         */
        void on_search_button_clicked();

        /**
         * @brief 复制code_edit的内容
         *
         * @param NULL
         * @return 无
         */
        void on_code_copy_clicked();

        /**
         * @brief 复制comment_edit的内容
         *
         * @param NULL
         * @return 无
         */
        void on_comment_copy_clicked();

        /**
         * @brief 保存code_edit中的内容到数据库
         *
         * @param NULL
         * @return 无
         */
        void on_code_save_clicked();

        /**
         * @brief 清空code_edit中的内容
         *
         * @param NULL
         * @return 无
         */
        void on_code_clear_clicked();

        /**
         * @brief 保存comment_edit中的内容到数据库
         *
         * @param NULL
         * @return 无
         */
        void on_comment_save_clicked();

        /**
         * @brief 清空comment_edit中的内容
         *
         * @param NULL
         * @return 无
         */
        void on_comment_clear_clicked();

        /**
         * @brief 另存为按钮, 将code_edit以及comment_edit另存为新的数据
         *
         * @param NULL
         * @return 无
         */
        void on_save_as_clicked();

        /**
         * @brief 切换数据库中的表
         *
         * @param index 选项
         * @return 无
         */
        void on_language_switch_currentTextChanged(const QString &arg1);

    private:
        Ui::MainWindow *ui;
};


#endif // MAINWINDOW_H
