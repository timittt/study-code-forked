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

typedef struct
{
    float start;
    float end;
} Interval;

void get_values(FILE *p_file, Sensor *p_Sensor)
{
    int i = 0;
    while (i < VALUE_COUNT && fscanf(p_file, "%f %lf", &p_Sensor->data[i].time, &p_Sensor->data[i].probability) == 2)
    {
        i++;
    }
}

void detect_objects(Sensor *p_Sensor)
{
    for (int i = 0; i < VALUE_COUNT; i++)
    {
        if (p_Sensor->threshold < p_Sensor->data[i].probability)
        {
            p_Sensor->object_detection[i] = 1;
        }
        else
        {
            p_Sensor->object_detection[i] = 0;
        }
    }
}

int find_intervals(int *detections, SensorData *time_data, Interval *found_intervals)
{
    int count = 0;
    int in_detection = 0;

    for (int i = 0; i < VALUE_COUNT; i++)
    {
        if (*(detections + i) == 1 && !in_detection)
        {
            (found_intervals + count)->start = (time_data + i)->time;
            in_detection = 1;
        }
        else if (*(detections + i) == 0 && in_detection)
        {
            (found_intervals + count)->end = (time_data + i - 1)->time;
            in_detection = 0;
            count++;
        }
    }
    // Falls am Ende der Datei noch ein Objekt offen ist
    if (in_detection)
    {
        (found_intervals + count)->end = (time_data + VALUE_COUNT - 1)->time;
        count++;
    }
    return count;
}

void write_overlap_array(Sensor *s1, Sensor *s2, int *arr)
{
    for (int i = 0; i < VALUE_COUNT; i++)
    {
        if (s1->object_detection[i] == 1 && s2->object_detection[i] == 1)
        {
            *(arr + i) = 1;
        }
        else 
        {
            *(arr + i) = 0;
        }
    }
}

void print_intervals(const char *name, Interval *intervals, int count)
{
    printf("--- %s Detections: ---\n", name);
    for (int i = 0; i < count; i++)
    {
        printf("Interval %d: %.2f s - %.2f s\n", i + 1, intervals[i].start, intervals[i].end);
    }
    if (count == 0)
        printf("No objects detected.\n");
    printf("\n");
}

int main()
{
    FILE *f_s1 = fopen("sensor1.txt", "r");
    FILE *f_s2 = fopen("sensor2.txt", "r");
    if (f_s1 == NULL || f_s2 == NULL)
    {
        printf("Dateien nicht gefundne!\n");
        return 1;
    }
    Sensor sensor1 = {1, 0.8};
    Sensor sensor2 = {2, 0.7};

    get_values(f_s1, &sensor1);
    get_values(f_s2, &sensor2);

    detect_objects(&sensor1);
    detect_objects(&sensor2);

    int overlap_array[VALUE_COUNT] = {0};
    write_overlap_array(&sensor1, &sensor2, overlap_array);

    Interval s1_intervals[100];
    Interval s2_intervals[100];
    Interval overlap_intervals[100];

    int count1 = find_intervals(sensor1.object_detection, sensor1.data, s1_intervals);
    int count2 = find_intervals(sensor2.object_detection, sensor2.data, s2_intervals);
    int count_fused = find_intervals(overlap_array, sensor1.data, overlap_intervals);

    print_intervals("Sensor 1", s1_intervals, count1);
    print_intervals("Sensor 2", s2_intervals, count2);
    print_intervals("Both sensors", overlap_intervals, count_fused);

    fclose(f_s1);
    fclose(f_s2);
    printf("Interval-Detection erfolgreich abgeschlossen\n");
    return 0;
}