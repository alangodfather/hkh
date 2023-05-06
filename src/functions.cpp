#include "main.h"
	Motor left_1(-11, 1);
	Motor right_1(17);
	Motor left_2(-12, 1);
	Motor right_2(18);
	Motor left_3(-13, 1);
	Motor right_3(19);
	Motor left_4(-14, 1);
	Motor right_4(20);
	Imu inertial(21);



void Powerdrive(int powerforward, int powerturning){

	left_1 = powerforward + powerturning;
	right_1 = powerforward - powerturning;
	left_2 = powerforward + powerturning;
	right_2 = powerforward - powerturning;
	left_3 = powerforward + powerturning;
	right_3 = powerforward - powerturning;
 	left_4 = powerforward + powerturning;
	right_4 = powerforward - powerturning;
}


void timedmove(int time){
	Powerdrive(60,0);
	delay(time);
	Powerdrive(0,0);
}

void millisdrive(int time, int power){
	int st = millis();
	while(time > millis() - st){
		Powerdrive(60*power,0 );
	}
	Powerdrive(0,0);
}

void turning(int time, int turnp){
	int st = millis();
	while(time > millis() - st){
		Powerdrive(0,60*turnp);
	}
	Powerdrive(0,0);
}
void turn(int target){
    while(fabs(target - intertial.get_rotation()) > 2 ){
        if(target > intertial.get_rotation()){
            Powerdrive(0,10);
        }else if(target < intertial.get_rotation()){
            Powerdrive(0,-10);

        }
    }
}
void drive(int target){
    while(abs(target - left_1.get_position()) > 2 ){
        if(target > left_1.get_position()){
            Powerdrive(10,0);
        }else if(target < left_1.get_position()){
            Powerdrive(-10,0);

        }
    }






}