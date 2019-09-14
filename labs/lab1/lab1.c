#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int main()
{
    //float x = 0.2, y = -12.5 , z = 1.000;
    float x, y, z;
    printf("Input(x):");
    scanf("%f", &x);
    printf("Input(y):");
    scanf("%f", &y);
    printf("Input(z):");
    scanf("%f", &z);
    float a0 = pow(x, y+1) / pow(x-y, 1/z);
    float a1 = y / ( 10 * fabs ( x + y ) );
    float a2 = pow(x+1, (1/(fabs(sin(y)))));
    float a = a0 + a1 + a2;
    printf ( "x: %.1f\n", x );
    printf ( "y: %.1f\n", y );
    printf ( "z: %.1f\n", z );
    printf ( "a0: %.3f\n", a0 );
    printf ( "a1: %.3f\n", a1 );
    printf ( "a2: %.3f\n", a2 );
    printf ( "a: %.3f\n ", a );
}