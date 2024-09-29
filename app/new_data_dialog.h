#ifndef NEW_DATA_DIALOG_H
#define NEW_DATA_DIALOG_H


#include <QDialog>


namespace Ui {
class new_data_dialog;
}

class new_data_dialog : public QDialog
{
    Q_OBJECT

public:
    explicit new_data_dialog(const QString &tableValue, QWidget *parent = nullptr);  // 新增构造函数 用于接收table
    ~new_data_dialog();

private slots:
    /**
     * @brief 保存数据
     *
     * @param NULL
     * @return 无
     */
    void on_new_data_save_clicked();

    /**
     * @brief 取消
     *
     * @param NULL
     * @return 无
     */
    void on_new_data_cancel_clicked();

    /**
     * @brief 更改table_receive的值
     *
     * @param NULL
     * @return 无
     */
    void on_language_switch_currentTextChanged(const QString &);

    /**
     * @brief 删除数据
     *
     * @param NULL
     * @return 无
     */
    void on_new_data_delete_clicked();

    /**
     * @brief 清空输入框
     *
     * @param NULL
     * @return 无
     */
    void on_new_data_clear_clicked();

private:
    Ui::new_data_dialog *ui;
    QString table_receive;  // 添加table变量 从mainwindow接收
};


#endif  // NEW_DATA_DIALOG_H
