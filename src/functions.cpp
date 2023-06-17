#include "main.h"
#include "math.h"
void resetSens(){
left_1.tare_position();
left_2.tare_position();
left_3.tare_position();
left_4.tare_position();
right_1.tare_position();
right_2.tare_position();
right_3.tare_position();
right_4.tare_position();

inertial.reset();
}
void BrakeOn(){
	left_1.set_brake_mode(MOTOR_BRAKE_HOLD);
	left_2.set_brake_mode(MOTOR_BRAKE_HOLD);
	left_3.set_brake_mode(MOTOR_BRAKE_HOLD);
	left_4.set_brake_mode(MOTOR_BRAKE_HOLD);
	right_1.set_brake_mode(MOTOR_BRAKE_HOLD);
	right_2.set_brake_mode(MOTOR_BRAKE_HOLD);
	right_3.set_brake_mode(MOTOR_BRAKE_HOLD);
	right_4.set_brake_mode(MOTOR_BRAKE_HOLD);
	
}
void BrakeOff(){
	left_1.set_brake_mode(MOTOR_BRAKE_COAST);
	left_2.set_brake_mode(MOTOR_BRAKE_COAST);
	left_3.set_brake_mode(MOTOR_BRAKE_COAST);
	left_4.set_brake_mode(MOTOR_BRAKE_COAST);
	right_1.set_brake_mode(MOTOR_BRAKE_COAST);
	right_2.set_brake_mode(MOTOR_BRAKE_COAST);
	right_3.set_brake_mode(MOTOR_BRAKE_COAST);
	right_4.set_brake_mode(MOTOR_BRAKE_COAST);
}

void Powerdrive(int powerforward, int powerturning){

	left_1 = powerforward + powerturning;
	right_1 = powerforward - powerturning;
	left_2 = powerforward + powerturning;
	right_2 = powerforward - powerturning;
	left_3 = powerforward + powerturning;
	right_3 = powerforward - powerturning;
	right_4 = powerforward - powerturning;
	left_4 = powerforward + powerturning;
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

	return  (distance*internal*external/diameter/PI); 
}
void PDIdrive (int inches, double kP, double kI, double kD){
	// double target = InchtoTick(inches);
	double target = inches;
	double difference = target-left_1.get_position();
	int power;
	int integral;
	int past_difference;
	int derivative;
	while(fabs(target-left_1.get_position())> 2){
		past_difference = difference; 
		difference = target-left_1.get_position();
		derivative = difference-past_difference;

		if(fabs(target-left_1.get_position())<10){
			integral += difference;
		}

		power = difference*kP + integral*kI + derivative*kD;
		Powerdrive(power,0);
	}
	Powerdrive(SpeedCap(power),0);
}

void PDIturn (int degrees, double kP, double kI, double kD){
	double difference = degrees-inertial.get_rotation();
	int power;
	int integral;
	int past_difference;
	int derivative;
	while(fabs(degrees-inertial.get_rotation())>0.2){
		past_difference = difference; 
		difference = degrees-inertial.get_rotation();
		derivative = difference-past_difference;

		if(fabs(degrees-inertial.get_rotation())<2.5){
			integral += difference;
		}

		power = difference*kP + integral*kI + derivative*kD;
		Powerdrive(0,power);
	}
	Powerdrive(0,0);
}


int SpeedCap(int speed){ 
	int limit = 100;
	
	if(abs(speed) <= limit ){
		return(speed);
	}else if(speed < -limit){
	    return -limit;
	}else if (speed > limit){
		return limit;
	}
}

void PIDdrive(int inches, double kP, double kI, double kD){
	resetSens();
	double target = inches;
	double difference = target-left_1.get_position();
	int power;
	int integral;
	int past_difference;
	int derivative;
	
	//turning
	double degrees = 0;
	inertial.reset();
	int r_power;
	int r_integral;
	int r_past_difference;
	int r_derivative;
	int r_difference;
	double r_kP = 0.5;
	double r_kI = 0;
	double r_kD = 0;
	while(fabs(target-left_1.get_position())> 2 || (fabs(degrees-inertial.get_rotation())>0.2)){
		//derivative
		past_difference = difference; 
		difference = target-left_1.get_position();
		derivative = difference-past_difference;

		if(fabs(target-left_1.get_position())<10){
			integral += difference;
		}

		power = difference*kP + integral*kI + derivative*kD;
		//turning
		r_past_difference = r_difference; 
		r_difference = degrees-inertial.get_rotation();
		r_derivative = r_difference-r_past_difference; 

		if(fabs(degrees-inertial.get_rotation())<2.5){
			r_integral += r_difference;
		}

		r_power = r_difference*r_kP + r_integral*r_kI + r_derivative*r_kD;
		Powerdrive(SpeedCap(power),r_power);
	}
	
	
	Powerdrive(0,0);


}

