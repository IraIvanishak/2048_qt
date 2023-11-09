#include "iiv2048.h"
#include "ui_iiv2048.h"

#include <QWidget>
#include <QLabel>

#include <QGridLayout>
#include <QKeyEvent>



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)

{
    setFocusPolicy(Qt::StrongFocus);

    connect(right, SIGNAL(clicked()), this, SLOT(sRight()));
    connect(up, SIGNAL(clicked()), this, SLOT(sUp()));
    connect(left, SIGNAL(clicked()), this, SLOT(sLeft()));
    connect(down, SIGNAL(clicked()), this, SLOT(sDown()));

    connect(newGame, SIGNAL(clicked()), this, SLOT(start()));
    connect(playAgain, SIGNAL(clicked()), this, SLOT(start()));

    this->setStyleSheet("background-color: #696970	;");

     game->setSpacing(8);
     game->setContentsMargins(0,0,0,0);
     for (int i= 0; i < 4; i ++)
          for(int j=0; j<4;j++){
                 QLabel *label = new QLabel;
                  label->setStyleSheet("background-color: white;");
                  label->setFixedSize(80,80);
                  label->setAlignment(Qt::AlignCenter);
                  game->addWidget(label, i, j);
         }

       move->setSpacing(4);
       move->setAlignment(Qt::AlignCenter);
       move->setContentsMargins(0, 0, 0, 0);
       move->sizeHint();

       score->setText("52");
       score->setMaximumWidth(168);
       score->setAlignment(Qt::AlignCenter);
       score->setStyleSheet("color: white");

       gameStatus->setText("YOU WIN!");
       gameStatus->setStyleSheet("color: white;");
       gameStatus->setMaximumWidth(150);
       gameStatus->setAlignment(Qt::AlignCenter);

       up->setFixedSize(50,50);
            up->setText("^");
       up->setStyleSheet("QPushButton{   background-color: white;    border-style: none;  }"
                     "QPushButton:hover{ background-color: aliceblue;   }");


       down->setFixedSize(50,50);
       down->setText("v");
       down->setStyleSheet("QPushButton{   background-color: white;    border-style: none;  }"
                           "QPushButton:hover{ background-color: aliceblue;   }");

       left->setFixedSize(50,50);
       left->setText("<");
       left->setStyleSheet("QPushButton{   background-color: white;    border-style: none;  }"
                           "QPushButton:hover{ background-color: aliceblue;   }");

       right->setFixedSize(50,50);
       right->setText(">");
       right->setStyleSheet("QPushButton{   background-color: white;    border-style: none;  }"
                            "QPushButton:hover{ background-color: aliceblue;   }");

       newGame->setText("NEW GAME");
       newGame->setFixedSize(168, 40);
       newGame->setStyleSheet("QPushButton{   background-color: white;    border-style: none;  }"
                            "QPushButton:hover{ background-color: aliceblue;   }");


      playAgain->setText("PLAY AGAIN");
       playAgain->setFixedSize(158, 40);

       playAgain->setStyleSheet("QPushButton{   background-color: white;    border-style: none;  }"
                            "QPushButton:hover{ background-color: aliceblue;   }");



       move->addWidget(up, 0,1);
       move->addWidget(down, 1,1);
       move->addWidget(left, 1,0);
       move->addWidget(right, 1,2);

            mainLayout->addLayout(game, 1, 0, 2,1);
            mainLayout->addLayout(move, 1, 1);

            QHBoxLayout * panel =new QHBoxLayout;
            panel->addWidget(newGame, 0);
            panel->addWidget(score, 1);
            panel->setContentsMargins(0,30, 0,20);

            QVBoxLayout * endofGame= new QVBoxLayout;
            endofGame->addWidget(gameStatus, 0);
            endofGame->addWidget(playAgain, 1);
            endofGame->setSpacing(0);
            endofGame->setContentsMargins(0, 60,0,100);

        mainLayout->addLayout(panel, 0,0);
        mainLayout->addLayout(endofGame, 2,1);

       mainLayout->setAlignment(endofGame, Qt::AlignVCenter);
       mainLayout->setAlignment(game, Qt::AlignCenter);


        gameWidget->setLayout(mainLayout);
        setCentralWidget(gameWidget);
        start();

}



void MainWindow:: matrix(){
    for(int i=0; i<4; i++)
       for(int j=0; j<4; j++)
           m[i][j]=0;

}
void MainWindow:: activeFild(bool is){
    up->setDisabled(is);
    down->setDisabled(is);
    right->setDisabled(is);
    left->setDisabled(is);
    newGame->setDisabled(is);
}
void MainWindow::gen()
{

    while(1)
    {
        a=rand()%4;
        b=rand()%4;
        if(m[a][b]!=0) continue; else
        {
            m[a][b]=2;
            break;
        }    }

}
void MainWindow::start(){
        activeFild(false);
        playAgain->hide();
        gameStatus->hide();
        sum=0;
        matrix();
            gen();
            gen();


          {
//                m[0][0]=1024;
//                m[0][1]=1024;
         }

          {
//                m[0][0]=4;
//                m[0][1]=2;
//                m[0][2]=4;
//                m[0][3]=2;

//                m[1][0]=2;
//                m[1][1]=4;
//                m[1][2]=2;
//                m[1][3]=4;

//                m[2][0]=4;
//                m[2][1]=8;
//                m[2][2]=4;
//                m[2][3]=8;

//                m[3][0]=16;
//                m[3][1]=32;
          }

            viz();
}
QLabel* MainWindow::cell(int row, int column)
{
    return qobject_cast<QLabel*>(game->itemAtPosition(row, column)->widget());
}
void MainWindow::viz()
{
int q=0;
QString s;
s=QString::number(sum);
score->setText(s);

    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            if(m[i][j]==0) q++;
            QString num;
            num=QString::number(m[i][j]);
            cell(i,j)->setText(num);

            if(m[i][j]==0){
                cell( i, j)->setStyleSheet("background-color: #F0FFFF;");
                cell( i, j)->setText("");
            }else
        if(m[i][j]==2) cell(i, j)->setStyleSheet("background-color: #AFEEEE;");else
        if(m[i][j]==4) cell( i, j)->setStyleSheet("background-color: #40E0D0;");else
        if(m[i][j]==8) cell( i, j)->setStyleSheet("background-color: #87CEEB;");else
        if(m[i][j]==16) cell( i, j)->setStyleSheet("background-color: #87CEFA;");else
        if(m[i][j]==32) cell(i, j)->setStyleSheet("background-color: #00BFFF;");else
        if(m[i][j]==64) cell( i, j)->setStyleSheet("background-color: #98FB98;");else
        if(m[i][j]==64) cell( i, j)->setStyleSheet("background-color: #90EE90;");else
        if(m[i][j]==128) cell( i, j)->setStyleSheet("background-color: #00FA9A;");else
        if(m[i][j]==256) cell( i, j)->setStyleSheet("background-color: #00FF7F;");else
        if(m[i][j]==2*256) cell( i, j)->setStyleSheet("background-color: #ADFF2F;");else
        if(m[i][j]==4*256) cell( i, j)->setStyleSheet("background-color: #7FFF00;");else
            if(m[i][j]==2048) {
                cell( i, j)->setStyleSheet("background-color: #32CD32;");
                wictory();
            }

}}
    if(q==0) gameOver();
}
void MainWindow::wictory()
{
    activeFild(true);
    gameStatus->setText("YOU WIN!");
    gameStatus->show();
    playAgain->show();


}
void MainWindow::gameOver()
{

    for(int i=0; i<4;i++)
        for(int j=0;j<3; j++){
            if(m[i][j]==m[i][j+1]) return;
            if(m[j][i]==m[j+1][i]) return;
        }
    gameStatus->setText("Game over");
    activeFild(true);
    gameStatus->show();
    playAgain->show();
}
void MainWindow::sLeft()
{
    bool operation=false;
    for(int i=0; i<4; i++)
    {
        int q=0;
 for(int j=0; j<3; j++){
             if(m[i][j])  {
                    int y=j+1;
                  while(m[i][y]==0&&y!=3)    y++;
             if(m[i][j]==m[i][y])
                    {
                        if(m[i][j])   operation=true;
                        m[i][j]+= m[i][y];
                        sum+=m[i][j];
                        m[i][y]=0;
                    }}}
 for(int j=0; j<4; j++){
            if(m[i][j])
            {
                if(m[i][q]!=m[i][j])
                {
                    operation=true;
                    m[i][q]=m[i][j];
                    m[i][j]=0;
                }
        q++;
            }  }  }
    if(operation)        gen();


    viz();
}
void MainWindow::sRight()
{
  bool operation=false;
    for(int i=0; i<4; i++)
    {
        int q=3;
 for(int j=3; j>0; j--){
       int y=j-1;
             if(m[i][j])  {

                    while(m[i][y]==0&&y!=0)    y--;

             if(m[i][j]==m[i][y])
                    {
                       if(m[i][j])   operation=true;
                        m[i][j]+= m[i][y];
                        sum+=m[i][j];
                        m[i][y]=0;
                    }}}
 for(int j=3; j>=0; j--){
            if(m[i][j])
            {
                if(q!=j)
                {
                 operation=true;
                    m[i][q]=m[i][j];
                    m[i][j]=0;
                }
        q--;
            }  }  }
    if(operation)        gen();

    viz();
}
void MainWindow::sUp()
{
    bool operation=false;
    for(int j=0; j<4; j++)
    {
        int q=0;
 for(int i=0; i<3; i++){
             if(m[i][j])  {
                    int y=i+1;
                    while(m[y][j]==0&&y!=3) y++;
             if(m[i][j]==m[y][j])
                    {
                        if(m[i][j])   operation=true;
                        m[i][j]+= m[y][j];
                        sum+=m[i][j];
                        m[y][j]=0;
                    }}}
 for(int i=0; i<4; i++){
            if(m[i][j])
            {
                if(m[q][j]!=m[i][j])
                {
                    operation=true;
                    m[q][j]=m[i][j];
                    m[i][j]=0;
                }
        q++;
            }  }  }
 if(operation)
     gen();

    viz();
}
void MainWindow::sDown()
{
    bool operation=false;
    for(int j=0; j<4; j++)
    {
        int q=3;
 for(int i=3; i>0; i--){
             if(m[i][j])  {
                    int y=i-1;
                    while(m[y][j]==0&&y!=0) y--;
             if(m[i][j]==m[y][j])
                    {
                        if(m[i][j])   operation=true;
                        m[i][j]+= m[y][j];
                        sum+=m[i][j];
                        m[y][j]=0;
                    }}}
 for(int i=3; i>=0; i--){
            if(m[i][j])
            {
                if(m[q][j]!=m[i][j])
                {
                    operation=true;
                    m[q][j]=m[i][j];
                    m[i][j]=0;
                }
        q--;
            }  }  }
    if(operation)
    {
        gen();
        noFreeCells=false;
    }

    else if(noFreeCells) gameOver();
 viz();
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if(event->key()==Qt::Key_Down) sDown();
    if(event->key()==Qt::Key_Up) sUp();
    if(event->key()==Qt::Key_Right) sRight();
    if(event->key()==Qt::Key_Left) sLeft();
}

MainWindow::~MainWindow()
{
    delete game;
    delete move;
    delete up;
    delete down;
    delete left;
    delete right;
    delete newGame;
    delete playAgain;
    delete mainLayout;
    delete gameWidget;
    delete score;
    delete gameStatus;
    delete startGame;


}




