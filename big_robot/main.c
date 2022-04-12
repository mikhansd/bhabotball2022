#include <kipr/wombat.h>
int distance;

int main()
{
    enable_servos();
    create_connect();
    printf("les go tigers\n");
    distance =  get_create_distance();
	//Does Botguy mission
    botGuyTwo();
    return 0; 
    
}



void forward(int time){
    create_drive_direct(-200,-200);
    msleep(time);
    create_stop();
    msleep(250);
}
void backward(int time){
    create_drive_direct(300,300);
    msleep(time);
    create_stop();
    msleep(250);
}
void turnLeft(){
    create_drive_direct(-500,500);
    msleep(550);
    create_stop();
    msleep(250);
}
void turnLeftHalf(){
    create_drive_direct(-500,500);
    msleep(275);
    create_stop();
    msleep(250);
}
void turnRight(){
    create_drive_direct(500,-500);
    msleep(500);
    create_stop();
    msleep(250);
}
void turnRightHalf(){
    create_drive_direct(500,-500);
    msleep(275);
    create_stop();
    msleep(250);
}
void forwardSlow(){
    create_drive_direct(-100,-100);
    msleep(5500);
    create_stop();
    msleep(250);
}
void backwardSlow(){
    create_drive_direct(100,100);
    msleep(1000);
    create_stop();
    msleep(250);
}
void turnLeftSlow(int time){
    create_drive_direct(-100,100);
    msleep(time);
    create_stop();
    msleep(250);
}
void turnRightSlow(int time){
    create_drive_direct(100,-100);
    msleep(time);
    create_stop();
    msleep(250);
}
void followBlack(){
    while ((analog(2) < 1200)){
    	while(analog(0)<2500){
        	turnLeftSlow(250);
        }
        forward(50);
        create_stop();
    	msleep(250);
        while(analog(0)>2500){
            turnRightSlow(250);
        }
        forward(100);
        create_stop();
    	sleep(250);
    }
}
void forwardUntilBump(){
    
    while ((digital(8)== 0) && (digital(9)== 0)){
        create_drive_direct(-100,-100);
    }
    create_stop();
    msleep(100);
    
} 

void botGuy(){
    //armUp();
    turnLeftSlow(2350);
    forwardUntilBlack();
    forwardUntilWhite();
    forward(250);
    turnRightUntilBlack();
    //followBlack(); 
}
void botGuyTwo(){
    armUp();
    create_stop();
    msleep(1000);
    turnLeftSlow(2750);
    forward(1000);
    backward(350);
    turnLeftSlow(1600);
    forward(1000);
    forwardUntilBlackScnd();
    turnLeftSlow(1600);
    backwardUntilBump();
    forwardUntilBlack();
    forward(300);
    followBlack();
    
}
void findBlack(){
    while(analog(0) > 2500){
        forward(200);
        turnLeft();
        turnRight();
    }
}
void backwardUntilBump(){
     while (get_create_rbump() == 0){
     	create_drive_direct(100,100);
     }
    create_stop();
}
void forwardUntilBlack(){
    while (analog(0) < 2500){
        create_drive_direct(-100,-100);
    }
}
void forwardUntilBlackScnd(){
    while (analog(1) < 3500){
        create_drive_direct(-100,-100);
    }
}
void forwardUntilWhite(){
    while (analog(0) > 900){
        create_drive_direct(-100,-100);
    }
} 
void turnRightUntilBlack(){
    while (analog(0) < 2500){
    create_drive_direct(100,-100);
    }
}
void turnLeftUntilBlack(){
    while (analog(0) < 2500){
    create_drive_direct(-100,100);
    }
}
void armUp(){
	set_servo_position(0, 1585);
}

void armDown(){
    set_servo_position(1, 144);
}

void armMiddle(){
    set_servo_position(1, 558);
}
void clawClose(){
    set_servo_position(0, 150);
}
void clawOpen(){
    set_servo_position(0, 956);
}








