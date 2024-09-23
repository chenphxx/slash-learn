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
    explicit new_data_dialog(QWidget *parent = nullptr);
    explicit new_data_dialog(const QString &tableValue, QWidget *parent = nullptr);  // 新增构造函数
    ~new_data_dialog();

private slots:
    void on_new_data_save_clicked();

    void on_new_data_cancel_clicked();

private:
    Ui::new_data_dialog *ui;
    QString table_receive;  // 添加table1变量
};

#endif  // NEW_DATA_DIALOG_H
