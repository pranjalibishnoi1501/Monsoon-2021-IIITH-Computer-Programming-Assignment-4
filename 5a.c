#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int count0 = 0, count1 = 0, rand0 = 0, rand1 = 0, array[1000000];
    srand(time(NULL));

    for (int x = 1; x <= 127; x++)
    {
        array[x] = (rand() % 2);
    }
    for (int x = 128; x <= 1000000; x++)
    {
        array[x] = array[x - 1] ^ array[x - 127];

        if (array[x] == 0)
        {
            count0++;
        }
        if (array[x] == 1)
        {
            count1++;
        }

        int random = rand() % 2;

        if (random == 0)
        {
            rand0++;
        }
        if (random == 1)
        {
            rand1++;
        }
    }
    printf("USING XOR APPROACH: %d\n", count0);
    printf("USING XOR APPROACH: %d\n", count1);
    printf("USING RANDOM FUNCTION APPROACH: %d\n", rand0);
    printf("USING RANDOM FUNCTION APPROACH: %d\n", rand1);
    return 0;
}