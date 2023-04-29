#ifndef EXTENSION_H 
#define EXTENSION_H 

#include "vex.h"

class Extension {
public:
  Extension(triport::port extension)
    : m_Extension(extension) {
    m_Extension.set(false);
  }

  void DriverControl();

  // -- autonomous functions --
  void Launch();
private:
  digital_out m_Extension;
};

#endif