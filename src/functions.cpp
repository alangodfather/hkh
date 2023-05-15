#include "main.h"
#include "math.h"


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
    while(fabs(target - inertial.get_rotation()) > 0.5){
        if(target > inertial.get_rotation()){
            Powerdrive(0,30);
        }else if(target < inertial.get_rotation()){
            Powerdrive(0,-30);

        }
    }Powerdrive(0,0);
}
void drive(int target){
	left_1.tare_position();
    while(abs(target - left_1.get_position()) > 2 ){
        if(target > left_1.get_position()){
            Powerdrive(30,0);
        }else if(target < left_1.get_position()){
            Powerdrive(-30,0);

        }
    }Powerdrive(0,0);

}
double InchtoTick(int distance){
	double external = (double)3/5; 
	double internal = 300;
	double diameter = 3.25; 
	double PI = 3.14;

	return  (distance*internal*external/diameter*PI); 
}
void PDIdrive (int inches, double kP, double kI, double kD){
	double target = InchtoTick(inches);
	double error = target-left_1.get_position();
	int power;
	int integral;
	int past_error;
	int derivative;
	while(fabs(target-left_1.get_position())> 2){
		past_error = error; 
		error = target-left_1.get_position();
		derivative = error-past_error;

		if(fabs(target-left_1.get_position())<10){
			integral += error;

		}

		power = error*kP + integral*kI + derivative*kD;
		Powerdrive(power,0);
	}
	Powerdrive(0,0);
}