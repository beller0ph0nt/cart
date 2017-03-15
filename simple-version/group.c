#include <stdio.h>
#include <stdlib.h>

void group_int_num(int* array, int len)
{
    int* groups = calloc(len, sizeof(int));
    int  i      = 0;
    int  val    = 0;
    int  min    = array[0];

    for (i = 1; i < len; i++)
    {
        val = array[i];
        if (val < min)
        {
            min = val;
        }
    }

    for (i = 0; i < len; i++)
    {
        groups[array[i]- min]++;
    }

    for (i = 0; i < len; i++)
    {
         printf("group %d: %d element(s)\n", i + min, groups[i]);
    }

    free(groups);
}

int main(int argc, char** argv)
{
#define LEN 10
    int a[LEN] = { 1, 2, 7, 9, 3, 1, 0, 2, 6, 3 };

    group_int_num(a, LEN);
    return 0;
}
