#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui {
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
    void on_start_btn_clicked();

    void on_pause_btn_clicked();

    void on_stop_btn_clicked();

    void prosses();

private:
    Ui::MainWindow *ui;
    short int min;
    short int sec;
    bool pause;
    QTimer reloj;
};
#endif // MAINWINDOW_H
