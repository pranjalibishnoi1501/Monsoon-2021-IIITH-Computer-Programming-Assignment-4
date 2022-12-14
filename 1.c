#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int count[7];

int main()
{
    srand(time(NULL));
    int i = 0;
    while (i <= 1000000)
    {
        int randnum;
        randnum = (rand() % 6) + 1;
        count[randnum]++;
        i++;
    }

    for (int i = 1; i <= 6; i++)
    {
        printf("%d\n", count[i]);
    }

    return 0;
}