#include <stdio.h>
#include <math.h>
#include <unistd.h>
#include <stdbool.h>

#define CLEAR_LINE "\33[2K\r"

double getPowerDraw();
double timeRemaining(void);
int dEqual(double a, double b, double epsilon);
bool isLinux();

int main(void)
{
    // First check if is linux
    if (!isLinux())
    {
        printf("This project relies on the linux kernel to function properly."
               "\n Your laptop is not using the linux kernel.\n");
    }

    double draw = getPowerDraw();
    double hours = timeRemaining();
    double prevDraw = draw;
    printf("%.1f W%5.1f hr", draw, hours);
    fflush(stdout); // actual printing occurs here

    for (;;)
    {
        sleep(1);

        prevDraw = draw;
        draw = getPowerDraw();

        if (!dEqual(prevDraw, draw, 1.0E-4))
        {
            printf(CLEAR_LINE);

            hours = timeRemaining();

            printf("%.1f W%5.1f hr", draw, hours);
            fflush(stdout);
        }
    }

    return 0;
}

int dEqual(double a, double b, double epsilon)
{
    return fabs(a - b) < epsilon;
}
