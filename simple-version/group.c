#include <stdio.h>
#include <stdlib.h>

void group_int_num(int* array, int len)
{
    int  i   = 0;
    int  min = array[0];
    int  max = min;

    for (i = 1; i < len; i++)
    {
        int val = array[i];
        if (val < min)
            min = val;
        else if (val > max)
            max = val;
    }

    int  number_of_groups = max - min + 1;
    int* groups           = calloc(number_of_groups, sizeof(int));

    for (i = 0; i < len; i++)
    {
        int hash = array[i] - min;
        groups[hash]++;
    }

// DEBUG
    for (i = 0; i < number_of_groups; i++)
    {
         printf("group %d: %d element(s)\n", i + min, groups[i]);
    }
// DEBUG

    free(groups);
}

#define BITS_IN_BYTE    8

/*
void group_int_bit_field(int* array, int len)
{
    int  number_of_groups = sizeof(int) * BITS_IN_BYTE;
    int* groups           = calloc(number_of_groups, sizeof(int));

    for (i = 0; i < len; i++)
    {
        int hash = 
    }
}
*/


int main(int argc, char** argv)
{
#define LEN 10
    int a[LEN] = { 1, 2, 7, 6, 3, 1, 0, 2, 6, 3 };

    group_int_num(a, LEN);
    return 0;
}
