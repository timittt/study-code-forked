#include <stdio.h>

struct Car 
{
    float fuel_level;
    float max_fuel_level;
    char name[50];
};

void refuel(struct Car *p, int add_fuel)
{
    if((p->fuel_level + add_fuel) > p->max_fuel_level)
    {
        printf("Can't add this much fuel!\n");
    }
    else
    {
        p->fuel_level += add_fuel;
        printf("Refueled %d l. Your %s is now %.1f%% filled (%.1f l).\n",
        add_fuel, p->name, 100*(p->fuel_level/p->max_fuel_level), p->fuel_level);
    }
}

int main()
{
    struct Car myCar = {0.5, 55, "VW Touran"};
    printf("Enter amount to refuel: ");
    int add = 0;
    if (scanf("%d", &add) != 1) {
        printf("Ungueltige Eingabe!\n");
        return 1;
    }
    refuel(&myCar, add);
    return 0;
}