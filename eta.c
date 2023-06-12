#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define BATTERY_DIR "/sys/class/power_supply/BAT0"
#define CAPACITY "energy_now"

double getPowerDraw();

double timeRemaining(void)
{
    FILE *capacity = fopen(BATTERY_DIR "/" CAPACITY, "r");

    if (capacity == NULL)
    {
        perror("File does not exist");
        exit(EXIT_FAILURE);
    }

    char cap[100];
    fgets(cap, 100, capacity);
    fclose(capacity);

    int uCap = atoi(cap);
    double wCap = uCap * 1.0E-6;

    double hours = wCap / abs(getPowerDraw());

    return hours;
}