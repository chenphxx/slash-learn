#ifndef QUERY_EXECUTE_H
#define QUERY_EXECUTE_H

#include <QDialog>

namespace Ui {
class query_execute;
}

class query_execute : public QDialog
{
    Q_OBJECT

public:
    explicit query_execute(QWidget *parent = nullptr);
    ~query_execute();

private slots:
    /**
     * @brief 执行语句
     *
     * @param NULL
     * @return 无
     */
    void on_query_execute_button_clicked();

    /**
     * @brief 关闭
     *
     * @param NULL
     * @return 无
     */
    void on_query_cacel_button_clicked();

private:
    Ui::query_execute *ui;
};

#endif // QUERY_EXECUTE_H
