#ifndef PID_H
#define PID_H

class PID {
public:
  /*
  * Errors
  */
  double p_error;
  double i_error;
  double d_error;
  double total_error;
  double bestErr = 1e9;

  /*
  * Coefficients
  */ 
  double Kp;
  double Ki;
  double Kd;

  /*
  * Custom
  */
  double sum_cte;
  double prev_cte;
  int step;

  double dpp = 0.05;
  double dpi = 0;
  double dpd = 0.05;

  int coeff_indicator = 0;
  int plus_indicator = 0;

  /*
  * Constructor
  */
  PID();

  /*
  * Destructor.
  */
  virtual ~PID();

  /*
  * Initialize PID.
  */
  void Init(double Kp, double Ki, double Kd);

  double getValue();
  /*
  * Update the PID error variables given cross track error.
  */
  void UpdateError(double cte);

  /*
  * Calculate the total PID error.
  */
  double TotalError();


};

#endif /* PID_H */
