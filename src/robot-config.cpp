#include "vex.h"

#include "cata.h"
#include "intake.h"
#include "drive.h"
#include "extension.h"

competition Competition;
brain Brain;
controller Controller(primary);

Cata cata(motor(PORT8, ratio18_1), rotation(PORT3, true));
Intake intake(motor(PORT5, ratio18_1));

motor a = motor(PORT17, ratio6_1, true);
motor b = motor(PORT9, ratio6_1, false);
motor c = motor(PORT20, ratio6_1, true);

motor d = motor(PORT1, ratio6_1, false);
motor e = motor(PORT11, ratio6_1, true);
motor f = motor(PORT12, ratio6_1, false);

Drive drive(
  motor_group(a, b, c),
  motor_group(d, e, f),
  inertial(PORT16),
  PID(0.8, 0, 0, 1),
  PID(0.5, 0, 0, 10),
  5
);

Extension extension(Brain.ThreeWirePort.B);