#include "intake.h"
#include "robot-config.h"

#include "cata.h"

extern Cata cata;

const double INTAKE_SPEED = 200;

void Intake::DriverControl() {
  if (Controller.ButtonL1.pressing()) {
    m_Motor.spin(forward, INTAKE_SPEED, rpm);
  } else if (Controller.ButtonL2.pressing()) {
    m_Motor.spin(reverse, INTAKE_SPEED, rpm);
  } else {
    m_Motor.stop();
  }
}

void Intake::Roll(double deg, directionType direction) {
  m_Motor.spinFor(direction, deg, degrees);
}