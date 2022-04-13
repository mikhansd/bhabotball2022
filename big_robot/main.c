#include <kipr/wombat.h>
int distance;
void botGuy();
void botGuyTwo();
void forward();
void backward();
void clawOpen();
void forwardUntilBlack();
void forwardUntilBlackScnd();
void armUp();
void backwardUntilBump();
void clawClose();
void armMiddle();


int main()
{
    enable_servos();
    create_connect();
    printf("les go tigers\n");
    distance =  get_create_distance();
	//Does Botguy mission
    botGuyTwo();
    create_stop();
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
    msleep(4750);
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
void followBlack(int x, int y){
    while(x < y){
    	if(analog(0)<2000){
        	create_drive_direct(-25,10);
        }
    	
        if (analog(0)>2000){
            create_drive_direct(10,-25);
        }
        x = x + 1;
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
    //forwardUntilWhite();
    forward(250);
    //turnRightUntilBlack();
    //followBlack(); 
}
void botGuyTwo(){
    armUp();
    clawOpen();
    create_stop();
    msleep(1000);
    turnLeftSlow(2750);
    forward(1000);
    backward(350);
    turnLeftSlow(1600);
    forward(1100);
    forwardUntilBlackScnd();
    turnLeftSlow(1700);
    backwardUntilBump();
    forwardUntilBlack();
    forward(1500);
    clawClose();
    create_stop();
    msleep(2000);
    backward(350);
    turnLeftSlow(1500);
    //armMiddle();
    create_stop();
    msleep(1000);
    forward(5000);
    turnLeftSlow(1350);
    create_stop();
    msleep(1000);
    clawOpen();
    create_stop();
    msleep(1000);
    turnLeftSlow(250);
    forwardSlow();
    backward(2000);
    //turnLeftSlow(500);
    //clawOpen();
    
    
    
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
    set_servo_position(0, 144);
}

void armMiddle(){
    set_servo_position(0, 558);
}
void clawClose(){
    set_servo_position(1, 0);
}
void clawOpen(){
    set_servo_position(1, 956);
}








