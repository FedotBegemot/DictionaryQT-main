#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "MyDictionary.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QString filePath;

private slots:
    void on_addFileButton_clicked();
    void on_loadFileButton_clicked();
    void on_SaveFileButton_clicked();
private:
    Ui::MainWindow *ui;
    void setItemsInTableView();
    Dictionary dictionary;
};
#endif // MAINWINDOW_H
