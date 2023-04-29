#include "cata.h"
#include "robot-config.h"

#include "util.h"

extern Cata cata;

void Cata::Launch() {
  m_CataRunning = true;

  bool cataHitTop = false;

  while (true) {
    m_Motor.spin(forward, 80, rpm);

    double pos = ConvertAngleRange(m_Rotation.angle());

    if (pos <= 10) {
      cataHitTop = true;
    }

    if ((cataHitTop && pos >= 67) || Controller.ButtonR2.pressing()) {
      m_CataRunning = false;
      m_Motor.stop();
      return;
    }
    
    wait(20, msec);
  }
}

void Cata::DriverControl() {
  if (Controller.ButtonR1.pressing() && !m_CataRunning) {
    task launch([]() -> int {
      cata.Launch();
      return 0;
    });
  }
}