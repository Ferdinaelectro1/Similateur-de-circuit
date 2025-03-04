#include "mainwinsoft.h"
#include "./ui_mainwinsoft.h"
#include <QFileDialog>

MainWinSoft::MainWinSoft(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWinSoft)
{
    ui->setupUi(this);
}

MainWinSoft::~MainWinSoft()
{
    delete ui;
}


void MainWinSoft::on_actionOpen_File_triggered()
{
    QUrl project = QFileDialog::getExistingDirectory(this,"Open Folder","/",QFileDialog::ShowDirsOnly);
}

