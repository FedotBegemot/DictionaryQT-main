#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "MyDictionary.h"
#include <QDebug>
#include <QFileDialog>
#include <QStandardItemModel>
#include <QTableView>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_loadFileButton_clicked()
{
    QString text = QFileDialog::getOpenFileName(0, "Open File", QString(), "*.json");
    dictionary.loadFromFile(text);
    setItemsInTableView();
}

void MainWindow::setItemsInTableView() {
    QMap<QString, int> dictMap = dictionary.getDict();

    QStandardItemModel *standardItemModel = new QStandardItemModel();

    standardItemModel->setHorizontalHeaderLabels(QStringList() << "Слово" << "Встречаемость");

    int rowNumber = 0;
    for (auto cur = dictMap.begin(); it != dictMap.end(); ++it)
    {
        QStandardItem *newItem1 = new QStandardItem(cur.key());
        QStandardItem *newItem2 = new QStandardItem(QString::number(cur.value()));
        standardItemModel->setItem(rowNumber, 0, newItem1);
        standardItemModel->setItem(rowNumber, 1, newItem2);
        rowNumber++;
    }
    ui->tableView->setModel(standardItemModel);
    ui->tableView->resizeColumnsToContents();
}

void MainWindow::on_SaveFileButton_clicked()
{
    QFileDialog dialog(this);
    dialog.setFileMode(QFileDialog::AnyFile);
    dialog.setAcceptMode(QFileDialog::AcceptSave);
    dialog.setNameFilter(tr("Text files (*.json)"));
    if (dialog.exec()) {
        QString filePath = dialog.selectedFiles().first();
        dictionary.saveToFile(filePath);
    }
}

void MainWindow::on_addFileButton_clicked()
{
    QString text = QFileDialog::getOpenFileName(0, "Open File", QString(), "*.txt");
    dictionary.addWordsFromFile(text);
    setItemsInTableView();
}
