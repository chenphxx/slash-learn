#ifndef NEW_DATA_H
#define NEW_DATA_H

#include <QDialog>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();

private slots:
    void on_new_data_save_clicked();

    void on_new_data_cancel_clicked();

private:
    Ui::Dialog *ui;
};

#endif // NEW_DATA_H
