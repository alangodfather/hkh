#include "main.h"
#include "function.hpp"
	Motor left_front(8, 1);
	Motor right_front(3);
	Motor left_top(5);
	Motor right_top(1,1);
	Motor left_bottom(9,1);
	Motor right_bottom(2);
	Motor catapult(6);
	Motor intake(12);
	ADIDigitalOut wings(1);
	ADIDigitalOut hangpiston(2);
	Rotation rotation_sensor(4);

	Imu inertial(21);

/**
 * A callback function for LLEMU's center button.
 *
 * When this callback is fired, it will toggle line 2 of the LCD text between
 * "I was pressed!" and nothing.
 */


/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {
	 inertial.reset();
	 delay(200);
	 pros::lcd::initialize();
	 wings.set_value(false);
	// delay(250);
	// inertial.reset();
	// delay(250);
}

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {}

/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
void competition_initialize() {}
	

/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */
void autonomous() {
	intake = -127;
	PIDdrive(47,0.22,0.01,8,1350);
	PIDdrive(-46,0.20,0.01,8,1350);
	delay(200);
	PIDturn(90,1.9,0.00025,6,1000);
	intake = 0;
	PIDdriverightArc(-40,0.4,0.01,0.2,2200);
	PIDdrive(14,0.22,0.01,5,1000);
	PIDturn(-42,1.99,0.00035,7,1000);
	delay(350);
	PIDdrive(12,0.5,0.01,5,1000);//Drive forward to descore triball in corner
	delay(150);
	wings.set_value(true);
	delay(150);
	PIDturn(-45,1.98,0.003,5,1000);
	PIDturn(25,1.98,0.0035,5,1000);
	delay(200);
	wings.set_value(false);
	delay(200);
	PIDdrive(5,0.5,0.01,5,1000);
	intake = 127;
	delay(200);
	PIDturn(-32,1.98,0.003,5,1000);
	delay(200);
	PIDdrive(35, 0.5, 0.01, 5, 1000);


	
	
	
	
	
	

	
	//new close side legal elim auto
	/*
	intake = -127;
	PIDdrive(47,0.22,0.01,5,1350);
	PIDdrive(-47,0.25,0.01,5,1350);
	PIDturn(75,1.9,0.00025,5);
	PIDdriverightArc(-40,0.4,0.01,0.2,2200);
	intake = 0;
	PIDdrive(5,0.35,0.01,5,2000);
	PIDturn(-180,2.2,0.000275,7.5);
	PIDdriveleftArc(-67,0.30,0.0025,1,900);
	delay(250);
	PIDturn(-180,1.8,0.000275,7.5);
	PIDdrive(24,0.22,0.01,5,800);
	intake = 127;
	delay(300);
	PIDdrive(-38,0.22,0.01,5,800);
	PIDturn(-180,1.82,0.000275,7.5);
	intake = 0;
	
	*/
	
	// far side auto elim and normal
	/*
	intake = -127;   // first triball push
	PIDdrive(68,0.25,0.01,5,1350);
	PIDturn(-52,1.9,0.00025,5);
	PIDdrive(-50,0.25,0.01,2.5,800);
	PIDdrive(8,0.25,0.01,2.5,800);
	intake = 0; 
	PIDturn(-179,2.2,0.000275,7.5);
	intake = 100;
	delay(200);
	PIDdrive(11,0.25,0.01,2.5,800);
	intake = 0;
	PIDdrive(-20,0.20,0.01,2.5,800);
	PIDturn(129,2.2,0.000275,7.5);
	intake = -127;
	delay(250);
	PIDdrive(33,0.10,0.01,2.5,900);
	PIDdrive(-13,0.25,0.01,2.5,800);
	PIDturn(-125,1.9,0.0003,5);
	intake = 70;
	PIDdrive(25,0.25,0.01,2.5,800);
	PIDdrive(-10,0.20,0.01,2.5,800);
	intake = 0;
	PIDturn(-90,1.9,0.00025,5);
	PIDdrive(-37,0.25,0.01,2.5,800);
	PIDturn(-90,1.9,0.00025,5);
	PIDdriveleftArc(-77,0.33,0.0025,1,1100);// last triball push
	PIDdrive(5,0.25,0.01,2.5,800);
	*/

	//elim close side auto
	/*
	PIDdrive(-39,0.25,0.01,2.5,1100);
	PIDturn(90,2.9,0.0025,1);
	wings.set_value(true);
	PIDdrive(-30,0.25,0.01,5,1100);
	wings.set_value(false);
	delay(500);
	PIDdrive(25,0.15,0.01,5,1100);
	intake = 127;
	PIDdrive(11,0.35,0.01,5,1050);
	intake = 0;
	delay(500);
	PIDdrive(-10,0.15,0.01,5,1100);
	PIDturn(-90,3.8,0.0025,1);
	PIDdrive(25,0.15,0.01,5,1100);
	PIDturn(65,3.8,0.0025,1);
	PIDdrive(25,0.15,0.01,5,1100);
	*/

	//New AWP auto 
	/*
	PIDdrive(4,0.35,0.01,5,500);
	wings.set_value(true);
	PIDdrive(-4,0.35,0.01,5,500);
	PIDdrive(10,0.35,0.01,5,500);
	delay(400);
	wings.set_value(false);
	delay(500);
	PIDdrive(7,0.35,0.01,5,500);
	PIDturn(36,3.8,0.0025,1);
	PIDdrive(4,0.35,0.01,5,500);
	intake = 127;
	delay(500);
	PIDdrive(12,0.30,0.01,5,750);
	intake = 0;
	PIDdriveleftArc(-73,0.33,0.0025,1,1100);
	delay(300);
	PIDturn(180,3.1,0.0025,3);
	PIDdrive(16,0.20,0.01,5,500);
	delay(300);
	*/
	
	// elim auto
	/*
	intake = -127;
	PIDdrive(48,0.25,0.01,5,3000);
	PIDdrive(-47,0.25,0.01,5,3000);
	intake = 0;
	PIDturn(75,3.1,0.0025,1);
	delay(500);
	PIDdriverightArc(-40,0.5,0.01,0.2,2200);
	delay(500);
	PIDdrive(5,0.35,0.01,5,2000);
	delay(500);
	PIDturn(-180,3.1,0.0025,1);
	delay(500);
	PIDdriveleftArc(-67,0.33,0.0025,1,900);
	*/


	// wp auto
	/*
	wings.set_value(true);
	delay(500);
	PIDturn(-52,3.1,0.0025,1);
	delay(500);
	wings.set_value(false);
	PIDturn(15,3.0,0.0025,2);
	delay(200);
	PIDdrive(19,0.35,0.0025,1,2000);
	PIDturn(35,3.5,0.0025,1);
	delay(250);
	PIDdrive(2,2.5,0.0025,1,500);
	delay(250);
	timedintake(700,90);
	delay(500);
	PIDdrive(7,2.5,0.0025,1,500);
	delay(500);
	PIDdriveleftArc(-67,0.33,0.0025,1,900);
	delay(500);
	PIDturn(180,3.5,0.0025,1);
	delay(500);
	PIDdrive(27,0.25,0.01,5,4000);
	delay(250);
	*/

	// Working Skills auto code (Slot 3)
	/*
	timedcata(30000,-127);
	PIDturn(-27,2,0.0025,2);
	resetcata();
	PIDdrive(-79,0.25,0.01,0.2,5000);
	PIDdriverightArc(-40,0.5,0.01,0.2,2200);
	PIDdrive(9,0.5,0.01,0.2,900);
	PIDdrive(-11,0.5,0.01,0.2,1000);
	PIDdrive(9,0.5,0.01,0.2,900);
	PIDdrive(-11,0.5,0.01,0.2,1000);
	PIDdrive(5,0.28,0.01,0.2,1000);
	PIDturn(-90,2.2,0.0025,2);
	PIDdrive(-8,0.28,0.01,0.2,1000);
	intake = 127;
	PIDdrive(43,0.28,0.01,0.2,2000);
	PIDturn(90,2.2,0.0025,2);
	intake = 0;
	wings.set_value(true);
	PIDdrive(-6,0.28,0.01,0.2,500);
	delay(250);
	PIDdriveleftArc(-55,0.35,0.01,0.2,1500);
	PIDdrive(250,1,0.01,0.2,800);
	delay(250);
	PIDturn(90,2.2,0.0025,2);
	PIDdrive(-5,1,0.01,0.2,800);
	PIDdriveleftArc(-55,0.35,0.01,0.2,1500);
	PIDdrive(250,1,0.01,0.2,800);
	wings.set_value(false);
	*/
	
	

	







	/*
	delay(200);
	PIDdrive(-9,0.26,0.01,0.2);
	delay(200);
	PIDturn(-89,2,0.0025,0.15);
	delay(500);
	millisdrive(500,-60);
	delay(500);
	PIDdrive(5,0.26,0.01,0.2);
	delay(500);
	PIDturn(90,2,0.0025,0.15);
	delay(500);
	millisdrive(970,-1);
	delay(150);
	PIDdrive(6,0.26,0.01,0.2);
	delay(150);
	PIDturn(90,2,0.0025,0.15);
	delay(150);
	millisdrive(330,-1);
	delay(200);
	PIDdrive(38,0.31,0.003,0);
	delay(150);
	PIDturn(38,2.1,0.003,0.1);
	delay(150);
	intake = 85;
	PIDdrive(11,0.19,0.003,1.3);
	delay(200);
	intake = 0;
	PIDturn(110,2.1,0.003,0.2);
	delay(150);
	PIDdrive(18,0.45,0.008,1);
	intake = -115;
	delay(1250);
	intake = 0;
	delay(150);
	millisdrive(450,1);
	delay(350);
	millisdrive(225,-1);
	delay(350);
	millisdrive(300,1);
	*/
	
	
	// defensive side auto
	/*
	PIDdrive(-35,0.25,0.003,0.2);
	delay(1000);
	PIDdrive(37,0.25,0.0025,0.15);
	delay(250);
	PIDturn(60,2.1,0.003,0.1);
	delay(250);
	piston.set_value(true);
	delay(250);
	PIDdrive(17,0.31,0.003,0);
	delay(250);
	PIDturn(15,1.9,0.003,0.1);
	delay(250);
	intake = -85;
	delay(1000);
	intake = 0;
	delay(250);
	piston.set_value(false);
	delay(250);
	millisdrive(400,1);
	delay(500);
	millisdrive(200,-1);
	delay(500);
	millisdrive(500,1);
	*/
	

	// offensive side auto
	
	/*
	millisdrive(970,-1);
	delay(150);
	PIDdrive(6,0.26,0.01,0.2,2000);
	delay(150);
	PIDturn(90,2,0.0025,0.15);
	delay(150);
	millisdrive(330,-1);
	delay(150);
	piston.set_value(true);
	delay(200);
	PIDdrive(38,0.31,0.003,0, 2000);
	delay(150);
	PIDturn(38,2.1,0.003,0.1);
	delay(150);
	intake = 85;
	PIDdrive(11,0.19,0.003,1.3, 2000);
	delay(200);
	intake = 0;
	PIDturn(110,2.1,0.003,0.2);
	delay(150);
	PIDdrive(18,0.45,0.008,1, 2000);
	intake = -115;
	delay(1250);
	intake = 0;
	piston.set_value(false);
	delay(150);
	millisdrive(450,1);
	delay(350);
	millisdrive(225,-1);
	delay(350);
	millisdrive(300,1);
	*/

}

/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */
void opcontrol() {
	rotation_sensor.reset();
	bool toggle = false;
	bool tog = false;
	bool hang = false;
	bool shoot = false;
	while (true) {
		Controller master(pros::E_CONTROLLER_MASTER);
		pros::screen::print(TEXT_MEDIUM, 1, "Angle: %ld \n", rotation_sensor.get_angle());
		pros::screen::print(TEXT_MEDIUM, 2, "Temperature left 2: %f", left_top.get_temperature());
		pros::screen::print(TEXT_MEDIUM, 3, "Temperature left 3: %f", left_bottom.get_temperature());
		pros::screen::print(TEXT_MEDIUM, 5, "Temperature right 1 : %f", right_front.get_temperature());
		pros::screen::print(TEXT_MEDIUM, 6, "Temperature right 2: %f", right_top.get_temperature());
		pros::screen::print(TEXT_MEDIUM, 7, "Temperature right 3: %f", right_bottom.get_temperature());
		pros::screen::print(TEXT_MEDIUM, 8, "Rotation Sensor angle %f", rotation_sensor.get_angle());
    
		
		int yaxis = master.get_analog(ANALOG_LEFT_Y);
		int xaxis = master.get_analog(ANALOG_RIGHT_X);

		Powerdrive(yaxis,xaxis);
		
		if(master.get_digital(DIGITAL_X)== true){
			autonomous();
		}
	
		

		if(master.get_digital(DIGITAL_R2)){
			catapult = -127;
		}
		else{
			if((rotation_sensor.get_angle() < 12150)){
			catapult = -100;
			}
			else{
				catapult = 0;
			}

		}
		if(master.get_digital_new_press(DIGITAL_A)){
			hang = !hang;
			hangpiston.set_value(hang);
		}
		

		if(master.get_digital(DIGITAL_L1) == true){
			intake = 105;
		}
		else if(master.get_digital(DIGITAL_R1) == true){
			intake = -127;
		}
		else{
			intake = 0;
		}
		if (master.get_digital_new_press(DIGITAL_L2) == true){
			tog = !tog;
			wings.set_value(tog);

		}
		
		
		
		delay(20);
		
	}
	
}