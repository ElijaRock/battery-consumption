#include <stdio.h>
#include <math.h>
#include <unistd.h>

#define CLEAR_LINE "\33[2K\r"

double getPowerDraw();
int dEqual(double a, double b, double epsilon);

int main(void)
{
    double draw = getPowerDraw();
    double prevDraw = draw;
    printf("%.1f W", draw);
    fflush(stdout); // actual printing occurs here

    for (;;)
    {
        sleep(1);

        prevDraw = draw;
        draw = getPowerDraw();

        if (!dEqual(prevDraw, draw, 1.0E-4))
        {
            printf(CLEAR_LINE);
            printf("%.1f W", draw);
            fflush(stdout);
        }
    }

    return 0;
}

int dEqual(double a, double b, double epsilon)
{
    return fabs(a - b) < epsilon;
}
