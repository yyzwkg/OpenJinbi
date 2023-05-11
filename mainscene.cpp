#include "mainscene.h"
#include "ui_mainscene.h"
#include "mypushbutton.h"
#include "QPainter"
#include "QPixmap"
#include "chooselevelscene.h"
#include "QTimer"

MainScene::MainScene(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainScene)
{
    ui->setupUi(this);

    setFixedSize(320,588);
    setWindowIcon(QIcon(":/res/Coin0001.png"));
    setWindowTitle("翻金币场景");

    connect(ui->actionquit,&QAction::triggered,[=](){
        this->close();
    });

    //开始按钮
    MyPushButton *startBtn = new MyPushButton(":/res/MenuSceneStartButton.png");

    startBtn->setParent(this);
    startBtn->move(this->width()*0.5-startBtn->width()*0.5,this->height()*0.7);

    //实例化选择关卡场景
    chooseScene = new ChooseLevelScene;





    connect(startBtn,&MyPushButton::clicked,[=](){
        startBtn->zoom1();
        startBtn->zoom2();

        QTimer::singleShot(500,this,[=](){
            this->hide();

            chooseScene->show();
        });
    });


}

void MainScene::paintEvent(QPaintEvent *){
    QPainter painter(this);

    QPixmap pix;
    pix.load(":/res/PlayLevelSceneBg.png");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);

    pix.load(":/res/Title.png");
    pix = pix.scaled(pix.width()*0.5,pix.height()*0.5);
    painter.drawPixmap(10,30,pix);

}


MainScene::~MainScene()
{
    delete ui;
}
