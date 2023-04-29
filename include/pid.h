#ifndef PID_H
#define PID_H 

#include "vex.h"

#include <cmath>

class PID {
public:
  PID(const double kp, const double ki, const double kd, const double stopping)
    : c_KP(kp), c_KI(ki), c_KD(kd), c_Stopping(stopping) {
    Reset();
  }

  inline void SetTarget(double target) {
    m_Target = target;
  }

  inline bool ErrorNotAtStopping() const {
    return std::abs(m_Error) > c_Stopping;
  }
  
  void Reset();
  double Step(double actual);
private:
  const double c_KP;
  const double c_KI;
  const double c_KD;
  const double c_Stopping;

  double m_Target;
  double m_Error;

  double m_LastError;
  double m_RunningSum;
};

#endif