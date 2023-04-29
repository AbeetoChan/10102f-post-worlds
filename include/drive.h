#ifndef DRIVE_H 
#define DRIVE_H 

#include "pid.h"

class Drive {
public:
  Drive(
    motor_group leftMotors, 
    motor_group rightMotors, 
    inertial inertialSensor,
    PID drivePID, 
    PID turnPID,
    const double notMoving
  )
    : m_LeftMotors(leftMotors), 
    m_RightMotors(rightMotors), 
    m_InertialSensor(inertialSensor),
    m_Drive(drivePID), 
    m_Turn(turnPID),
    c_NotMoving(notMoving)
  {
    m_InertialSensor.calibrate();
  }

  void DriverControl();

  // -- autonomous functions --
  void Forward(double inches);
  void Turn(double degrees);
  bool VelCheck();
private:
  motor_group m_LeftMotors;
  motor_group m_RightMotors;
  inertial m_InertialSensor;

  PID m_Drive;
  PID m_Turn;

  const double c_NotMoving;
};

#endif