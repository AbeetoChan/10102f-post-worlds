#ifndef CATA_H 
#define CATA_H

#include "vex.h"
#include "util.h"

class Cata {
public:
  Cata(motor runningMotor, rotation rotationSensor)
    : m_Motor(runningMotor), m_Rotation(rotationSensor), m_CataRunning(false) {
    m_Motor.setReversed(true);
  }
  
  void DriverControl();

  // -- autonomous functions --
  void Launch();  
private:
  inline double Position() {
    return ConvertAngleRange(m_Rotation.position(degrees));
  }

  motor m_Motor;
  rotation m_Rotation;
  bool m_CataRunning;
};

#endif