#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    double x, y, d;
    srand48((int)time(NULL));
    long double pSquare = 10;
    long long int pCircle = 0;

    while (pSquare <= 100000000)
    {
        pCircle = 0;

        for (int i = 0; i < pSquare; i++)
        {
            x = (double)drand48();

            y = (double)drand48();

            d = ((x * x) + (y * y));

            if (d <= 1)
            {

                pCircle++;
            }
        }
        double pi = 4.0 * ((double)pCircle / (double)(pSquare));
        printf("%lf\n", pi);
        pSquare = pSquare * 10;
    }
    return 0;
}