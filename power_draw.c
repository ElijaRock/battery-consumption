#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BATTERY_DIR "/sys/class/power_supply/BAT0"
#define WATTAGE "power_now"
#define STATUS "status"

int getPowerStatus();

double getPowerDraw()
{
    FILE *power = fopen(BATTERY_DIR "/" WATTAGE, "r");

    if (power == NULL)
    {
        perror("File does not exist");
        exit(EXIT_FAILURE);
    }

    char uDraw[100];
    fgets(uDraw, 100, power);
    fclose(power);

    int uValue = atoi(uDraw);
    double wValue = uValue * 1.0E-6;
    return wValue * getPowerStatus();
}

int getPowerStatus()
{
    FILE *pState = fopen(BATTERY_DIR "/" STATUS, "r");

    if (pState == NULL)
    {
        perror("File does not exist");
        exit(EXIT_FAILURE);
    }

    int status = 0; // bad case

    char state[2];
    fgets(state, 2, pState);
    fclose(pState);

    if (state[0] == 'C') // Charging
    {
        status = 1;
    }
    if (state[0] == 'D') // Discharging
    {
        status = -1;
    }

    return status;
}