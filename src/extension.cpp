#include "extension.h"
#include "robot-config.h"

void Extension::Launch() {
  m_Extension.set(true);
}

void Extension::DriverControl() {
  if (Controller.ButtonX.pressing()) {
    Launch();
  }
}