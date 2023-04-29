#ifndef INTAKE_H
#define INTAKE_H

#include "vex.h"

class Intake {
public:
  Intake(motor runningMotor)
    : m_Motor(runningMotor) {
    
  }

  void DriverControl();

  // -- autonomous --
  void Roll(double deg, directionType direction);
private:
  motor m_Motor;
};

#endif