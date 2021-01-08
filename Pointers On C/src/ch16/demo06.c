#include <math.h>
#define A 10.45
#define B 10.00
#define C -1.0
#define X 1.78816 
double wind_chill(double temp, double velocity) {
    temp = 33 - temp;
    return 33 - ((A + B * sqrt(velocity) + C * velocity) * temp) /
           (A + B * sqrt(X) + C * X);
}