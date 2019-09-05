#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>

double fy(double x) //Функция из lab2
{
    double y;
    if (x == 5)
    {
        return ('e');
    }
    else if (-5 < x && x <= 3)
    {
        y = (sqrt(x + 5) - 7);
        return y;
    }
    else
    {
        y = (cos(x - 5) / sin(x - 5)) - 5;
        return y;
    }
}

void array(void)
{
    int a[30]; //Задаю массивы
    int b[30];

    srand(time(0)); //(псевдо)Случайные числа с использоанием времени
    printf("\na = { ");
    for (int cnt = 0; cnt < 30; cnt++)
    {
        a[cnt] = rand() % 20 - 10;
        printf(" %i,", a[cnt]);
    }
    printf(" }\n\n");
    printf("b = {");
    for (int cnt = 0; cnt < 30; cnt++)
    {
        if (cnt == 29)
        {
            b[cnt] = a[29] - a[0];
            printf(" %i,", b[cnt]);
            break;
        }
        b[cnt] = a[cnt + 1] - a[cnt];
        printf(" %i,", b[cnt]);
    }
    printf(" }\n\n");
    printf("\n[1.Repeat]\n[2.Main menu]\n\n");
    int temp = 0;
    while (temp != 1 && temp != 2)
    {
        scanf("%i", &temp);
        if (temp != 1 && temp != 2)
            printf("\n[Wrong num!]\n\n");
    }
    if (temp == 2)
        main();
    else if (temp == 1)
        array();
}

void float_matrix(void)
{
    double x_min, x_max;

    printf("\n[x_min] = ") && scanf("%lf", &x_min);
    printf("[x_max] = ") && scanf("%lf", &x_max);

    while (x_max <= x_min)
    {
        puts("[Min>=Max]\n");
        printf("/n[x_min] = ") && scanf("%lf", &x_min);
        printf("[x_max] = ") && scanf("%lf", &x_max);
    }
    printf("/n");
    double M[2][20];
    double s = (x_max - x_min) / 20;
    int i = 0;
    for (double c = x_min; i < 20; i++)
    {
        M[0][i] = c;
        c += s;
    }
    for (i = 0; i < 20; i++)
    {
        if (M[0][i] == 5)
            M[1][i] = 0;
        else
            M[1][i] = fy(M[0][i]);
    }
    for (i = 0; i < 20; i++)
    {
        if (M[0][i] == 5)
            printf("M[0][%.3f], M[1][ODZ]\n", M[0][i]);
        else
            printf("M[0][%.3f], M[1][%.3f]\n", M[0][i], M[1][i]);
    }
    printf("\n[1.Repeat]\n[2.Main menu]\n\n");
    int temp = 0;
    while (temp != 1 && temp != 2)
    {
        scanf("%i", &temp);
        if (temp != 1 && temp != 2)
            printf("\n[Wrong num!]\n\n");
    }
    if (temp == 2)
        main();
    else if (temp == 1)
        float_matrix();
}

void main(void)
{
    int num;
    printf("\n[1.Int array]\n[2.Float matrix]\n[3.Exit]\n\n");
    scanf("%i", &num);
    switch (num)
    {
    case 1:
        array();
        break;
    case 2:
        float_matrix();
        break;
    case 3:
        break;
    default:
        printf("[Wrong num]\n");
        main();
        break;
    }
}