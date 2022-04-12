#include <kipr/wombat.h>
void forward();
void backward();
void turnLeft();
void turnRight();
void findBlack();
void followBlack();
void moveUntilTouch();
void forwardSlow();
int main()
{
    enable_servo(0);
    enable_servo(1);
    //set_servo_position(1,1839);
    /*ao();
    msleep(1000);
    set_servo_position(0,1950);
    forward();
    msleep(2000);
    ao();
    msleep(1000);
    turnLeft();
    msleep(1500);
    ao();
    msleep(1000);
    //forward();
    //msleep(2500);
    */
    findBlack();
    ao();
    msleep(1000);
    ao();
    msleep(1000);
    forward();
    msleep(100);
    ao();
    msleep(1000);
    turnRight();
    msleep(2000);
    ao();
    msleep(1000);
    backward();//localize 
    msleep(1200);
    ao();
    msleep(1000);
    //set_servo_position(0,1030);
    //ao();
    //msleep(800);
    followBlack(1,5500);
    ao();
    msleep(1000);
    forward();
    msleep(1000);
    followBlack(1,5500);
    ao();
    msleep(1000);
    
    backward();
    msleep(900);
    ao();
    msleep(1000);
    //moveUntilTouch();
    //forward();
    //msleep(6000);
    ao();
    msleep(1000);
    set_servo_position(0,1128);
    ao();
    msleep(1000);
    //set_servo_position(0,1914);
    //ao();
    //msleep9(1000);
    backward();
    msleep(700);
    ao();
    msleep(1000);
    set_servo_position(0,2000);
    ao();
    msleep(1000);
    forward();
    msleep(300);
    ao();
    msleep(1000);
    set_servo_position(0,1079);
    ao();
    msleep(1000);
    backward();
    msleep(1000);
    turnRight();
    msleep(2500);
    ao();
    msleep(1000);
    forward();
    msleep(12000);
    ao();
    msleep(1000);
    backward();
    msleep(500);
    ao();
    msleep(1000);
    
    turnLeft();
    msleep(950);
    ao();
    msleep(1000);
    set_servo_position(0,2000);
    ao();
    msleep(1000);
    forward();
    msleep(3000);

    //followBlack();

    return 0;

}

void forward(){
    mav(0,5000);
    mav(1,5000);

}
void forwardSlow(){
    mav(0,1000);
    mav(1,1000);

}
void backward(){
    mav(0,-1000);
    mav(1,-1000);
}

void turnRight(){
    mav(1,1000);

}

void turnLeft(){
    mav(0,1000);
}

void findBlack(){

    while (analog(0) < 2000)
    {
        forwardSlow();
    }
    if (analog (0) > 2000)
    {
        ao();
    }
}
void moveUntilTouch(){

    while (digital(0) ==0)
    {
        forward();
    }
    if (digital (0) ==1)
    {
        ao();
    }
}

void followBlack(int x,int y){
    while (x<y){
        
        if(analog(0)<2000){
            mav(1,1000);
            ao();
        }
        else if(analog(0)>2000){
            mav(0,1000);
            ao();
        }
        x=x+1;
    }
    ao();
}

