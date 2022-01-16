#include <math.h>
#include <stdio.h>

double vectorlength(double x, double y, double z)
{
    double length = sqrt(x * x + y * y + z * z);
    return length;
}


