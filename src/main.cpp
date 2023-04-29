#include "vex.h"
#include "robot-config.h"

#include "cata.h"
#include "intake.h"
#include "drive.h"
#include "extension.h"

extern Cata cata;
extern Intake intake;
extern Drive drive;
extern Extension extension;

void PreRun() {

}

void Auton() {

}

void DriverControl() {
  while (true) {
    cata.DriverControl();
    intake.DriverControl();
    drive.DriverControl();
    extension.DriverControl();
    wait(20, msec);
  }
}

int main() {
  PreRun();

  Competition.autonomous(Auton);
  Competition.drivercontrol(DriverControl);
}