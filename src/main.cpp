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
	PDIturn(90,1,0.0008,0);
	delay(500);
	intake=-127;


	/*millisdrive(1000,-1);
	delay(500);
	PIDdrive(8,0.65,0,0);
	delay(500);
	PDIturn(90,3.5,0,0);
	delay(500);
	millisdrive(400,-1);
	delay(500);
	PIDdrive(35,0.75,0.0,0);
	delay(500);
	PDIturn(35,2.5,0,0);
	*/
	// timedintake(1000,-127);
	// delay(500);
	// PIDdrive(6,2,0,0.2);
	
	
	//left side
	/*
	PIDdrive(19,0.60,0.5,0);
	delay(100);
	PDIturn(40,2.2,0,0);
	delay(500);
	PIDdrive(2,0.60,0.5,0);
	delay(500);
	intaking(-127);
	piston.set_value(true);
	delay(500);
	piston.set_value(false);
	delay(500);
	millisdrive(500,1);
	delay(500);
	millisdrive(200,-1);
	delay(500);
	millisdrive(250,1);
	delay(500);
	millisdrive(250,-1);
	*\

	
	
	
	
	/*delay(500);
	piston.set_value(true);
	delay(500);
	intaking(-127);
	delay(500);
	piston.set_value(false);
	delay(5000);
	millisdrive(1000,1);
	delay(500);
	millisdrive(1250,-1);
    *\
	/*delay(500);
	PDIturn(-30,1.6,0.0,0.3);
	piston.set_value(true);
	intaking(-127);
	delay(1000);
	piston.set_value(false);
	delay(1000);
	millisdrive(1000,1);
	millisdrive(1250,-1);




	
	/* Far side auto
	
	millisdrive(500,1);
	delay(200);
	turning(190,-1);
	piston.set_value(true);
	intaking(-127);
	delay(1000);
	piston.set_value(false);
	delay(1000);
	millisdrive(1000,1);
	millisdrive(1250,-1);
	*\

//Near side auto
	/*
	millisdrive(600,1);
	delay(200);
	turning(250,1);
	piston.set_value(true);
	intaking(-127);
	delay(1000);
	piston.set_value(false);
	delay(1000);
	millisdrive(1000,1);
	millisdrive(1250,-1);
	//PDIturn(1000000,0.1,0,0);
*/
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
	
	/*PIDdrive(1000,1,0.025,0.25);*/
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
			void autonomous();
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