#include <stdlib.h>
#include <math.h>
#include <stdio.h>

int main(){

    const double xmin  = -10.0;
    const double xmax  = 10.0;
    const double xstep = 0.5;

    double x = xmin;
    double y;
    while  (x <= xmax)
    {
        if (x==5)
        {
            printf("x(5.0) = Error\n");
            x += xstep;
        }
        else if (-5<x && x<=3) 
        {
            y=(sqrt(x + 5) - 7);
        }
        else 
        {
            y=(cos(x-5)/sin(x-5))-5;
        }   
        
        printf ("x(%.1f) = %.6f\n", x ,y);
        x += xstep;
    }
}