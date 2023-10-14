#include "main.h"
	Motor left_1(2, 1);
	Motor right_1(4);
	Motor left_2(3);
	Motor right_2(5,1);
	Motor left_3(21,1);
	Motor right_3(9);
	Motor catapult(1);
	Motor intake(14);
	ADIDigitalOut piston(2);
	ADIDigitalOut wings(1);
	Rotation rotation_sensor(8);
	Imu inertial(6);

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
	
	millisdrive(1250,-1);
	millisdrive(900,1);
	delay(500);
	PIDturn(-26,2,0.0025,0.15);
	timedcata(3000,-127);
	delay(500);
	PIDturn(-20,2,0.0025,0.15);
	delay(500);
	PIDdrive(-15,0.26,0.01,0.2);
	PIDturn(-90,2,0.0025,0.15);
	millisdrive(-450,1);
	PIDdrive(7,0.26,0.01,0.2);
	PIDturn(90,2,0.0025,0.15);
	piston.set_value(true);
	PIDdrive(-30,0.26,0.01,0.2);
	delay(500);







	/*
	millisdrive(970,-1);
	delay(150);
	PIDdrive(6,0.26,0.01,0.2);
	delay(150);
	PIDturn(90,2,0.0025,0.15);
	delay(150);
	millisdrive(330,-1);
	delay(150);
	piston.set_value(true);
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
	piston.set_value(false);
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
	
	// millisdrive(970,-1);
	// delay(150);
	// PIDdrive(6,0.26,0.01,0.2);
	// delay(150);
	// PIDturn(90,2,0.0025,0.15);
	// delay(150);
	// millisdrive(330,-1);
	// delay(150);
	// piston.set_value(true);
	// delay(200);
	// PIDdrive(38,0.31,0.003,0);
	// delay(150);
	// PIDturn(38,2.1,0.003,0.1);
	// delay(150);
	// intake = 85;
	// PIDdrive(11,0.19,0.003,1.3);
	// delay(200);
	// intake = 0;
	// PIDturn(110,2.1,0.003,0.2);
	// delay(150);
	// PIDdrive(18,0.45,0.008,1);
	// intake = -115;
	// delay(1250);
	// intake = 0;
	// piston.set_value(false);
	// delay(150);
	// millisdrive(450,1);
	// delay(350);
	// millisdrive(225,-1);
	// delay(350);
	// millisdrive(300,1);
	

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
	bool shoot = false;
	while (true) {
		Controller master(pros::E_CONTROLLER_MASTER);
		pros::screen::print(TEXT_MEDIUM, 1, "Angle: %ld \n", rotation_sensor.get_angle());
		// pros::screen::print(TEXT_MEDIUM, 2, "Temperature left 2: %f", left_2.get_temperature());
		// pros::screen::print(TEXT_MEDIUM, 3, "Temperature left 3: %f", left_3.get_temperature());
		// pros::screen::print(TEXT_MEDIUM, 5, "Temperature right 1 : %f", right_1.get_temperature());
		// pros::screen::print(TEXT_MEDIUM, 6, "Temperature right 2: %f", right_2.get_temperature());
		// pros::screen::print(TEXT_MEDIUM, 7, "Temperature right 3: %f", right_3.get_temperature());
		// pros::screen::print(TEXT_MEDIUM, 8, "Rotation Sensor angle %f", rotation_sensor.get_angle());
    
		
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
			if(rotation_sensor.get_angle() < 4650){
			catapult = -127;
			}
			else{
				catapult = 0;
			}

		}
		
		

		if(master.get_digital(DIGITAL_R1) == true){
			intake = 105;
		}else if(master.get_digital(DIGITAL_L1) == true){
			intake = -127;
		}
		else{
			intake = 0;
		}
		if (master.get_digital_new_press(DIGITAL_L2) == true){
			toggle = !toggle;
			piston.set_value(toggle);

		}
		if (master.get_digital_new_press(DIGITAL_UP) == true){
			tog = !tog;
			wings.set_value(tog);

		}
		
		
		
		delay(20);
		
	}
	
}