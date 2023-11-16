#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <Qstring>
#include <QFile>
#include <QDebug>
#include <QFileDialog>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void openfilein(QString path);
    void openfileout(QString path);
    void openfilecode(QString path);
    void openfiletable(QString path);
    void openfileinput(QString path);
    void openfileres(QString path);
    void savefilein(QString path);
    void savefileinput(QString path);
    void load();
    void resload();

//修改


//修改




private slots:
    void on_BuildButton_clicked();

    void on_SaveButton_clicked();

    void openActionSlot();
    void saveActionSlot();



private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
