#include "mypushbutton.h"

#include "QPropertyAnimation"
#include "QDebug"

//MyPushButton::MyPushButton(QWidget *parent) : QWidget(parent)
//{

//}

MyPushButton::MyPushButton(QString normalImg,QString pressImg ){
    this->normalImgPath = normalImg;
    this->pressImgPath = pressImg;

    QPixmap pix;
    bool ret = pix.load(normalImg);
    if(!ret){
        qDebug()<<"图片加载失败";
        return;
    }

    this->setFixedSize(pix.width(),pix.height());

    this->setStyleSheet("QPushButton{border:0px}");

    this->setIcon(pix);

    this->setIconSize(QSize(pix.width(),pix.height()));

}

void MyPushButton::zoom1(){

    QPropertyAnimation *animation = new QPropertyAnimation(this,"geometry");

    //设置持续时间
    animation->setDuration(200);

    //设置开始位置
    animation->setStartValue(QRect(this->x(),this->y(),this->width(),this->height()));

    //设置结束位置
    animation->setEndValue(QRect(this->x(),this->y()+10,this->width(),this->height()));


    //设置弹跳曲线
    animation->setEasingCurve(QEasingCurve::OutBounce);

    //执行动画
    animation->start();


}

void MyPushButton::zoom2(){
    QPropertyAnimation *animation = new QPropertyAnimation(this,"geometry");

    //设置持续时间
    animation->setDuration(200);

    //设置开始位置
    animation->setStartValue(QRect(this->x(),this->y()+10,this->width(),this->height()));

    //设置结束位置
    animation->setEndValue(QRect(this->x(),this->y(),this->width(),this->height()));


    //设置弹跳曲线
    animation->setEasingCurve(QEasingCurve::OutBounce);

    //执行动画
    animation->start();


}
