#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int sum[13], randnum1, randnum2;

int main()
{
    srand(time(NULL));
    int i = 0;
    while (i <= 1000000)
    {
        randnum1 = (rand() % 6) + 1;
        randnum2 = (rand() % 6) + 1;
        sum[randnum1 + randnum2]++;
        i++;
    }
    for (int i = 2; i <= 12; i++)
    {
        printf("%d\n", sum[i]);
    }
    return 0;
}