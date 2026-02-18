#include <stdio.h>
#include <string.h>

#define VALUE_COUNT 3000

typedef struct 
{
    float time;
    double probability;
} SensorData;

typedef struct 
{
    int id;
    double threshold;
    SensorData data[VALUE_COUNT];
    int object_detection[VALUE_COUNT];
} Sensor;

int main()
{
    FILE* f_s1 = fopen("sensor1.txt", "r");
    FILE* f_s2 = fopen("sensor2.txt", "r");
    Sensor sensor1 = {1, 0.8};
    Sensor sensor2 = {2, 0.7};
    return 0;
}