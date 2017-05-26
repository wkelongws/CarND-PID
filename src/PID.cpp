#include "PID.h"
#include <math.h>
#include <iostream>

#define MIN_NUMBER_STEPS 300


using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {
	// P: steer in proportion to the crosstrack error
  
  	// I: steer more when there is sustained error to counter the systematic bias we have from e.g. misaligned wheels.
  
  	// D: When the car has turned enough to reduce CTE, it counter-steers
  	// to avoid overshooting
  
  	// Twiddle: choose optimal parameters
	this->Kp = Kp;
  	this->Ki = Ki;
  	this->Kd = Kd;

  	//dpp = 1;
	//dpi = 1;
	//dpd = 1;

  	sum_cte = 0;
  	prev_cte = 0;
  	step = 0;
  	total_error = 0;
  	//bestErr = 1e9;

}

void PID::UpdateError(double cte) {
	sum_cte += cte;
  	p_error = - Kp * cte;
  	i_error = - Ki * sum_cte;
  	d_error = - Kd * (cte - prev_cte);
  	prev_cte = cte;
  	step++;
  	if(step>MIN_NUMBER_STEPS){
  		total_error += pow(cte,2);
  	}
  	
  	//std::cout << "updated error" << std::endl;
}

double PID::getValue() {
	double steeringAngle = p_error + i_error + d_error;
	steeringAngle = steeringAngle<-1?-1:steeringAngle;
	steeringAngle = steeringAngle>1?1:steeringAngle;
	return steeringAngle;
}

double PID::TotalError() {
	return total_error/(step-MIN_NUMBER_STEPS);
}



