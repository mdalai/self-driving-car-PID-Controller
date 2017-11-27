#include "PID.h"

using namespace std;

/*
* TODO: Complete the PID class.
*/
// Constructor 
PID::PID() {}

// Destructor
PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {
    PID::Kp = Kp;
    PID::Ki = Ki;
    PID::Kd = Kd;
    p_error = d_error = i_error = 0.0;

}

void PID::UpdateError(double cte) {

    d_error = cte - p_error;  // differential cte
    p_error = cte;            // proportional cte
    i_error += cte;           // integral cte
   
}

// Calc steering value formula: steer = -Kp * cte - Kd * diff_cte - Ki * int_cte
double PID::TotalError() {
    //return - Kp*p_error; // only P control
    //return - Kp*p_error - Kd*d_error; // P + D control
    return - Kp*p_error - Kd*d_error - Ki*i_error;
}




