#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

#define STEP_COUNT 6
#define SLOT_COUNT 8
#define PART_COUNT 3

void print_field(int *p_part_arr, int current_time_index)
{
    printf("Time %d: ", current_time_index);
    for(int k = 0; k < SLOT_COUNT; k++)
    {
        printf("%d  ", *(p_part_arr + k));
    }
    printf("\n");
}

int main()
{
    srand(time(NULL));
    int part_arr[SLOT_COUNT];
    memset(part_arr, 0, sizeof(part_arr));
    int *p_part_arr = part_arr;

    int part_index[PART_COUNT] = {2, 4, 6};
    int *p_part_index = part_index;

    int collided_parts[PART_COUNT] = {0, 0, 0};
    int *p_collided_parts = collided_parts;

    // setze Slots, die Partikel enthalten, auf 1
    for(int i = 0; i < PART_COUNT; i++)
    {
        *(p_part_arr + *(p_part_index + i)) = 1;
    }
    print_field(part_arr, 0);

    //Simulation
    int direction = 0;
    for(int i = 0; i < STEP_COUNT; i++) // time steps
    {
        //Partikel bewegen
        for(int j = 0; j < PART_COUNT; j++)
        {
            while(1) // so lange bis legaler Move gefunden wurde
            {
                direction = (rand() % 2) * 2 - 1; // -1 oder 1 random
                if((*(p_part_index + j) + direction < SLOT_COUNT) && (*(p_part_index + j) + direction >= 0)) //sichergehen, dass index im definierten Bereich
                {
                    *(p_part_index + j) += direction;
                    break;
                }
            }
        }
        //Felder-Array überschreiben
        memset(part_arr, 0, sizeof(part_arr));
        for(int j = 0; j < PART_COUNT; j++)
        {
            if(!*(p_collided_parts + j))
            {
                *(p_part_arr + *(p_part_index + j)) = *(p_part_arr + *(p_part_index + j)) + 1;
            }
        }
        for(int j = 0; j < SLOT_COUNT; j++)
        {
            if(*(p_part_arr + j) == 2) // Kollision erkannt auf index j
            {
                *(p_part_arr + j) = 0;
                for(int m = 0; m < PART_COUNT - 1; m++)
                {
                    if(*(p_part_index + m) == *(p_part_index + m + 1))
                    {
                        *(p_collided_parts + m) = 1;
                        *(p_collided_parts + m + 1) = 1;
                    }
                }
                printf("Collision on field %d!\n", j+1);
            }
        }
        print_field(part_arr, i+1);
    }

    return 0;
}