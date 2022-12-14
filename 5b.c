#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int count0 = 0, count1 = 0, array[1000000], array0 = 0, array1 = 0;
    srand(time(NULL));

    for (int i = 1; i <= 127; i++)
    {
        array[i] = (rand() % 2);
    }
    for (int i = 128; i <= 1000000; i++)
    {
        array[i] = array[i - 1] ^ array[i - 127];

        if (array[i - 1] == 0)
        {
            count0++;
        }
        if (array[i - 1] == 1)
        {
            count1++;
        }
        if ((array[i] == 0) && (array[i - 1] == 0))
        {
            array0++;
        }
        if ((array[i] == 0) && (array[i - 1] == 1))
        {
            array1++;
        }
    }

    printf("P(xi = 0/xi−1 = 0) = %lf\n", (double)array0 / (double)count0);
    printf("P(xi = 0/xi−1 = 1) = %lf\n", (double)array1 / (double)count1);
    return 0;
}