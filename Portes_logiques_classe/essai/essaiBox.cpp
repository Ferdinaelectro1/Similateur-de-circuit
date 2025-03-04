#include <QApplication>
#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QPushButton>
#include <QVBoxLayout>
#include <QWidget>
#include <QGraphicsRectItem>

class MainWindow : public QMainWindow
{
    public:
      MainWindow(QWidget *parent = nullptr) : QMainWindow(parent)
      {
          // Créer la scène graphique et y ajouter des objets
          QGraphicsScene *scene = new QGraphicsScene(this);
          QGraphicsRectItem *rect = new QGraphicsRectItem(0, 0, 100, 100);
          rect->setBrush(Qt::blue);
          scene->addItem(rect);

          // Créer une vue graphique pour afficher la scène
          QGraphicsView *graphicsView = new QGraphicsView(scene);
          graphicsView->setMinimumSize(400, 400);

          // Créer un bouton simple
          QPushButton *button = new QPushButton("Cliquez-moi");

          // Créer un layout vertical pour contenir les widgets
          QVBoxLayout *layout = new QVBoxLayout;

          // Ajouter la vue graphique et le bouton au layout
          layout->addWidget(graphicsView);
          layout->addWidget(button);

          // Créer un widget central pour contenir le layout
          QWidget *centralWidget = new QWidget;
          centralWidget->setLayout(layout);

          // Définir le widget central dans la fenêtre principale
          setCentralWidget(centralWidget);

          // Configurer la fenêtre principale
          setWindowTitle("QGraphicsView et QWidget Ensemble");
          resize(600, 600);
      }
};

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    // Créer et afficher la fenêtre principale
    MainWindow window;
    window.show();

    return app.exec();
}
