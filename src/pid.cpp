#include "pid.h"

// Reset the PID controller by setting all the
// constants to zero.
void PID::Reset() {
  m_Target = 0;
  m_Error = 0;
  m_RunningSum = 0;
  m_LastError = 0;
}

double PID::Step(double actual) {
  m_Error = m_Target - actual;

  double proportional = m_Error * c_KP;

  m_RunningSum += m_Error;
  double integral = m_RunningSum * c_KI;
  
  double derivative = (m_Error - m_LastError) * c_KD;
  m_LastError = m_Error;

  return proportional + integral + derivative;
}