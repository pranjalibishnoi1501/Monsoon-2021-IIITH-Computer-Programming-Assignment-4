#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    double sum = 0, sumsq = 0, mean = 0, tmp = 0, diff = 0, squareddifference = 0, variance = 0;
    int i = 0;

    FILE *fp1;
    if ((fp1 = fopen(argv[1], "r")) == NULL)
    {
        printf("Error opening file\n");
        exit(0);
    }
    while (fscanf(fp1, "%lf", &tmp) != EOF)
    {
        sum += tmp;
        ++i;
        sumsq += (tmp * tmp);
        variance = sumsq / i;
        variance -= (sum / i) * (sum / i);
        printf("%lf\n", variance);
    }
    fclose(fp1);
    return 0;
}
