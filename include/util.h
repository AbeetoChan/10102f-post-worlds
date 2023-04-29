#ifndef UTIL_H
#define UTIL_H

inline double ConvertAngleRange(double angle) {
	return (angle > 180) ? angle - 360 : angle;
}

#endif