#include<stdio.h>
#include <stdlib.h>

void main(int argc, char **argv)
{
    int h, m, a, ha, ma;

    scanf("%d", &h);
    scanf("%d", &m);
    printf("Hour: %d, Mins: %d\n", h,m);

    ha = (60*h+m)*0.5;
    ma = 6*m;
    a = abs(ha-ma);
    a= 360-a > a? a: 360-a;
    printf("Angle: %d\n", a);
}

