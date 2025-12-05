#include "circleShift.h"

int testCircle()
{
    int num[] = { 1, 0, 1, 1 };
    int num2[] = { 1, 0, 0, 1 };
    return ((maxCircleShift(num, 4) == 14) && (maxCircleShift(num2, 4) == 12));
}
