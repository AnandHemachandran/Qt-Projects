#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->treeWidget->setHeaderLabel("Palette");
    ui->treeWidget->setColumnCount(1);
    AddClef("Clef");
    AddKeySig("Key Signarute");

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::AddClef(QString name)
{
    QTreeWidgetItem *clef =new QTreeWidgetItem(ui->treeWidget);
    clef->setText(0,name);
    ui->treeWidget->addTopLevelItem(clef);

    AddChild(clef,"Treble Clef");
    AddChild(clef,"Base Clef");
    AddChild(clef,"Alto Clef");
    AddChild(clef,"Tenor Clef");
}

void MainWindow::AddKeySig(QString name)
{
    QTreeWidgetItem *keysig =new QTreeWidgetItem(ui->treeWidget);
    keysig->setText(0,name);
    ui->treeWidget->addTopLevelItem(keysig);

    AddChild(keysig,"G Minor");
    AddChild(keysig,"B Major");
    AddChild(keysig,"F Minor");
    AddChild(keysig,"C Major");
}


void MainWindow::AddChild(QTreeWidgetItem *parent,QString name)
{
    QTreeWidgetItem *itm =new QTreeWidgetItem();
    itm->setText(0,name);
    parent->addChild(itm);

}

void MainWindow::on_pushButton_clicked()
{
    //adds a palette.
}

void MainWindow::on_pushButton_2_clicked()
{
    //deletes a palette
}
