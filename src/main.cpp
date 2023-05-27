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
	delay(500);
	inertial.reset();
	delay(1000);
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
	PDIturn(-90,1.5,0.05,2);
	inertial.reset();

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
	Controller master(pros::E_CONTROLLER_MASTER);
	
	
	
	
	
	
	
	
	
	
	
	
	
	/**
	drive(1050);
	turn(80);
	inertial.reset();
	drive(-550);
	delay(1000);
	drive;(550);
	turn(125);
	inertial.reset();
	/*
	delay(500);
	drive(-6000);
	*/








	/*
	millisdrive(2100,1);
	delay(1000);
	turning(240,1);
	delay(1000);
	millisdrive(2700,1);
	delay(1000);
	turning(260,-1);
	delay(1000);
	turning(515,-1);
	delay(1000);
	millisdrive(1400,-1);
	delay(1000);
	millisdrive(100,1);
	delay(1000);
	turning(430,1);
	delay(500);
	millisdrive(600,-1);
	delay(1000);
	turning(240,1);
	delay(1000);
	millisdrive(3500,-1);
	delay(1000);
	turning(150,1);
	delay(500);
	millisdrive(300,-1);
	*/


	while (true) {
		int yaxis = master.get_analog(ANALOG_LEFT_Y);
		int xaxis = master.get_analog(ANALOG_RIGHT_X);

		Powerdrive(yaxis,xaxis);
		
	}
}