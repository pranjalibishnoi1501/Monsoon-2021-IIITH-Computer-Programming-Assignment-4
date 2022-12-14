#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    long double sumsq = 0, mean = 0, tmp = 0, variance = 0;
    int i = 0;

    FILE *fp1;
    if ((fp1 = fopen(argv[1], "r")) == NULL)
    {
        printf("Error opening file\n");
        exit(0);
    }
    while (fscanf(fp1, "%Lf", &tmp) != EOF)
    {
        sumsq += (tmp * tmp);
        ++i;
    }
    fclose(fp1);
    FILE *fp2;
    fp2 = fopen(argv[2], "r");
    fscanf(fp2, "%Lf", &mean);
    fclose(fp2);
    variance = ((double)(sumsq / i) - (mean * mean));
    FILE *fp3;
    fp3 = fopen(argv[3], "w");
    fprintf(fp3, "%Lf", variance);
    fclose(fp3);
    return 0;
}