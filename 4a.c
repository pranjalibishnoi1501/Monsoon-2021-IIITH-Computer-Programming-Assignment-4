#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    FILE *fp1;
    if ((fp1 = fopen(argv[1], "r")) == NULL)
    {
        printf("Error opening file\n");
        exit(0);
    }
    double sum = 0, mean = 0, tmp = 0;
    long long int i = 0;
    while (fscanf(fp1, "%lf", &tmp) != EOF)
    {
        sum += tmp;
        ++i;
    }
    mean = (double)sum / i;
    fclose(fp1);
    FILE *fp2;
    fp2 = fopen(argv[2], "w");
    fprintf(fp2, "%lf", mean);
    fclose(fp2);
    return 0;
}