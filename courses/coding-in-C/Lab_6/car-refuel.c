#include <stdio.h>
#include <string.h>

struct Car {
    float fuel_level;
    float max_fuel_level;
    char name[50];
};

void refuel(struct Car *p, int add_fuel)
{
    if(p->fuel_level + add_fuel > p->max_fuel_level)
    {
        printf("Can't add this much fuel!\n");
    }
    else
    {
        p->fuel_level += add_fuel;
    }
}

int main()
{
    struct Car Touran = {0.5, 55, "VW Touran"};
    return 0;
}