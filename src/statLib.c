#include "stLib.h"

extern float function1(double A, double deltaX){
	return (cos(A + deltaX) - cos(A)) / deltaX;
}

extern float function2(double A, double deltaX){
	return (cos(A + deltaX) - cos(A - deltaX)) / (2 * deltaX);
}