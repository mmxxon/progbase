#include <math.h>
#include <stdio.h>
#define M_PI 3.14159265358979323846

double fy(double x) //Функция из lab2
{
    double y;
    if (x == 5)
    {
        return 0;
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

double int_fy(double x_min, double x_max, double x_step) //Функция вычисления интеграла
{
    double n = (x_max - x_min) / x_step, sum;                        //n - кол-во шагов
    for (double counter = x_min; counter < x_max; counter += x_step) //Вычисление функции для каждого значения счетчика (counter)
    {
        if (x_min <= 5 && x_max >= 5) //Если 5 в промежутке - значение функции 0
        {
            return 0;
        }
        sum += fabs(fy(counter)); //сумма значений по модулю
    }
    return sum * x_step; //площадь
}

int check(double x_min, double x_max) //проверка на то, что значение pi+5 не принадлежит {xmin; xmax}
{
    double limin = 5 - 33 * M_PI;
    double limax = 5 + 30 * M_PI;
    int z;
    for (double count2 = limin; count2 < limax; count2 += M_PI) //перебор значений pi+5. если в промежутке - z и, соответственно, значение функции = 0
    {
        if (count2 < x_max && count2 > x_min)
        {
            z = 0;
            break; //при нахождении pi+5 в {xmin; xmax} останавливает цикл
        }
        else
        {
            z = 1;
            continue;
        }
    }
    return z;
}

int main()
{
    double x_min, x_max, x_step;

    printf("x_min = "); //Ввод
    scanf("%lf", &x_min);
    printf("x_max = ");
    scanf("%lf", &x_max);
    if (x_max <= x_min) //min не >= max
    {
        printf("Min>=Max\n");
        return 0;
    }
    else if (x_min < 5 - 33 * M_PI || x_max > 5 + 30 * M_PI) //предупреждение при выходе за границы перебора
    {
        puts("\n!!!ANSWER MAY BE INCORRECT!!!\n");
    }
    if ((x_max < -5 || x_min > 3) && check(x_min, x_max) == 0) //проверка на ОДЗ
    {
        puts("Error: ODZ(1)");
        return 0;
    }
    else
    {
        printf("x_step = "); //ввод xstep
        scanf("%lf", &x_step);
        double S = int_fy(x_min, x_max, x_step); //интегрирование
        if (S == 0)                              //проверка на ОДЗ или S=0
        {
            puts("Error");
            return 0;
        }
        else //вывод S
        {
            printf("%.6lf\n", S);
        }
    }
}