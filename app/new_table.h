#ifndef NEW_TABLE_H
#define NEW_TABLE_H


#include <QDialog>


namespace Ui {
class new_table;
}

class new_table : public QDialog
{
    Q_OBJECT

public:
    explicit new_table(QWidget *parent = nullptr);
    ~new_table();

signals:
    /**
     * @brief 向mainwindow发送table_name
     *
     * @param table_name
     * @return 无
     */
    void send_table_name(const QString &table_name);

private slots:
    /**
     * @brief 确认按键
     *
     * @param NULL
     * @return 无
     */
    void on_new_table_confirm_clicked();

    /**
     * @brief 取消按键
     *
     * @param NULL
     * @return 无
     */
    void on_new_table_cancel_clicked();

private:
    Ui::new_table *ui;
};


#endif // NEW_TABLE_H
