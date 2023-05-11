#include "chooselevelscene.h"
#include "QPainter"
#include "QMenuBar"
#include "mypushbutton.h"


ChooseLevelScene::ChooseLevelScene(QWidget *parent) : QMainWindow(parent)
{
    this->setFixedSize(320,588);
    this->setWindowIcon(QPixmap(":/res/Coin0001.png"));
    this->setWindowTitle("选择关卡场景");

    //
    QMenuBar *bar = menuBar();
    setMenuBar(bar);

    QMenu *startMenu = bar->addMenu("开始");

    QAction *quitAction = startMenu->addAction("退出");

    connect(quitAction,&QAction::triggered,[=](){
       this->close();
    });

    for(int i = 0;i<20;i++){
        MyPushButton *menuBtn = new MyPushButton(":/res/LevelIcon.png");
        menuBtn->setParent(this);
        menuBtn->move(25+i%4*70,130+i/4*70);

        connect(menuBtn,&MyPushButton::clicked,[=](){

            this->hide();
            play = new PlayScene(i+1);
            play->show();


        });
    }

}

void ChooseLevelScene::paintEvent(QPaintEvent *){
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/res/OtherSceneBg.png");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);

    pix.load(":/res/Title.png");
    painter.drawPixmap((this->width()-pix.width())*0.5,30,pix.width(),pix.height(),pix);

}
