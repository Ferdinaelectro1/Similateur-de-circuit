#ifndef __APK_WINDOW_H__
#define __APK_WINDOW_H__
#include <QMainWindow>
#include <QFileSystemModel>
#include <QSplitter>
#include <QTreeView>
#include <QMainWindow>
#include <QInputDialog>
#include <QLineEdit>
#include <QFormLayout>
#include <QList>
#include <QMenu>
#include <QStatusBar>
#include <QColorDialog>
#include "win_new_project.h"

class apk_window : public QMainWindow
{
  Q_OBJECT
    public :
      apk_window();
      void quit();
      void open_project_action();
      void new_projects_action();
      QList<QAction *> recent_project_list();
      void update_apk_recent();
      void theme_change();

    private:
      QSplitter *splitter = new QSplitter(this);
      QTreeView *treeview = new QTreeView(this);
      QFileSystemModel *model = new QFileSystemModel(this);
      QMenu *menu_recent_project;
      win_new_project win_project_new;
      QColorDialog *dialog_color;
      
};

#endif