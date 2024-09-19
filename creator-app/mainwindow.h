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

    private slots:
        void on_search_button_clicked();

        void on_code_copy_clicked();

        void on_comment_copy_clicked();

        void on_code_save_clicked();

        void on_code_clear_clicked();

        void on_comment_save_clicked();

        void on_comment_clear_clicked();

        void on_save_as_clicked();

        void on_language_switch_currentIndexChanged(int index);

    private:
        Ui::MainWindow *ui;
};


#endif // MAINWINDOW_H
