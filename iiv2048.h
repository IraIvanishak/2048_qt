

#include <QMainWindow>
#include <QTableWidget>
#include <QGridLayout>
#include <QLabel>
#include <QPushButton>
#include <QGroupBox>



class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private:

    int m[4][4];
    int a, b;
    bool noFreeCells;

    void matrix();
    void gen();
    void viz();
    QLabel* cell(int row, int column);

   void  wictory();
   void gameOver();
   void activeFild(bool );

   int sum=0;


   QGridLayout * game= new   QGridLayout;
   QGridLayout * move= new   QGridLayout;
   QPushButton * up= new QPushButton;
   QPushButton * down= new QPushButton;
   QPushButton * left= new QPushButton;
   QPushButton * right= new QPushButton;
   QPushButton * newGame= new QPushButton;
   QPushButton * playAgain= new QPushButton;
   QGridLayout * mainLayout= new   QGridLayout;

   QWidget * gameWidget= new QWidget;

   QLabel * score=new QLabel;
   QLabel * gameStatus=new QLabel;
   QPushButton * startGame= new QPushButton();

private slots:
   void sLeft();
    void sRight();
    void sUp();
    void sDown();
        void start();
    void keyPressEvent(QKeyEvent *event);

};

