#ifndef _FUNCTIONS_HPP_
#define _FUNCTIONS_HPP_

void Powerdrive(int powerforward, int powerturning);
void timedmove(int time);
void millisdrive(int time, int power);
void turning(int time, int turnp);
void turn(int target);
void drive(int target);
double InchtoTicks(int distance);
void PDIdrive (int inches, double kP, double kI, double kD);
#endif