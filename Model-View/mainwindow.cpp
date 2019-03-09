#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    model = new QStringListModel(this);

    //creates lists.
    QStringList list;
    list <<"Cats"<< "Dogs"<< "Birds";

    //take data from model and put it in the listView Element in the ui
    model->setStringList(list);
    ui->listView->setModel(model);
    ui->comboBox->setModel(model);

    ui->listView->setEditTriggers(QAbstractItemView::AnyKeyPressed | QAbstractItemView::DoubleClicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    //add
    int row =  model->rowCount();
    model->insertRows(row,1);

    //To change the text in the list Item we need to change the Model value.
    QModelIndex index = model->index(row);

    //Going to edit mode.
    ui->listView->setCurrentIndex(index);
    ui->listView->edit(index);
}

void MainWindow::on_pushButton_3_clicked()
{
    //insert
    int row =  ui->listView->currentIndex().row();
    model->insertRows(row,1);

    //To change the text in the list Item we need to change the Model value.
    QModelIndex index = model->index(row);

    //Going to edit mode.
    ui->listView->setCurrentIndex(index);
    ui->listView->edit(index);
}

void MainWindow::on_pushButton_2_clicked()
{
    //delete
    model->removeRows(ui->listView->currentIndex().row(),1);
}
