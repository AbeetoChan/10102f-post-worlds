#include "drive.h"
#include "robot-config.h"
#include "util.h"

#include <cmath>

void Drive::DriverControl() {
  double left = Controller.Axis3.position(percent);
  double right = Controller.Axis2.position(percent);

  m_LeftMotors.spin(forward, left, percent);
  m_RightMotors.spin(forward, right, percent);
}

static inline double GetDistanceTravelled(motor_group& motorGroup) {
  const double WHEEL_C = 3.25 * M_PI;
  const double GEAR_RATIO = 0.6;
  
  return motorGroup.position(turns) * WHEEL_C * GEAR_RATIO;
}

bool Drive::VelCheck() {
  return std::abs(m_LeftMotors.velocity(rpm)) < c_NotMoving || std::abs(m_RightMotors.velocity(rpm)) < c_NotMoving;
}

void Drive::Forward(double inches) {
  m_Drive.SetTarget(inches);

  m_LeftMotors.resetPosition();
  m_RightMotors.resetPosition();

  do {
    double left = GetDistanceTravelled(m_LeftMotors);
    double right = GetDistanceTravelled(m_RightMotors);
    double average = (left + right) / 2;

    double calculated = m_Drive.Step(average);

    m_LeftMotors.spin(forward, calculated, volt);
    m_RightMotors.spin(forward, calculated, volt);

    if (VelCheck())
      return;
    
    wait(20, msec);
  } while (m_Drive.ErrorNotAtStopping());

  m_Drive.Reset();

  m_LeftMotors.stop();
  m_RightMotors.stop();
}

void Drive::Turn(double degrees) {
  m_Turn.SetTarget(degrees);

  m_LeftMotors.resetPosition();
  m_RightMotors.resetPosition();

  m_InertialSensor.resetHeading();
  
  do {
    double head = ConvertAngleRange(m_InertialSensor.heading());
    double calculated = m_Turn.Step(head);

    m_LeftMotors.spin(forward, calculated, volt);
    m_RightMotors.spin(reverse, calculated, volt);

    if (VelCheck())
      return;

    wait(20, msec);
  } while (m_Turn.ErrorNotAtStopping());
  
  m_Turn.Reset();

  m_LeftMotors.stop();
  m_RightMotors.stop();
}