#ifndef MAINWINSOFT_H
#define MAINWINSOFT_H

#include <QMainWindow>
#include <QTreeView>
#include <QSplitter>
#include <QFileSystemModel>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWinSoft; }
QT_END_NAMESPACE

class MainWinSoft : public QMainWindow
{
    Q_OBJECT

public:
    MainWinSoft(QWidget *parent = nullptr);
    ~MainWinSoft();

private slots:
    void on_actionOpen_File_triggered();

private:
    Ui::MainWinSoft *ui;
    QTreeView *treeview = new QTreeView;
    QSplitter *splitter = new QSplitter(this);
    QFileSystemModel *model = new QFileSystemModel(this);
};
#endif // MAINWINSOFT_H
