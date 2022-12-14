#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char *argv[])
{
    double mean = 0, tmp = 0, count = 0, percentage = 0;
    long long int i = 0;
    FILE *fp2;
    fp2 = fopen(argv[2], "r");
    fscanf(fp2, "%lf", &mean);
    fclose(fp2);
    double llimit = (0.8 * mean), ulimit = (1.2 * mean);
    FILE *fp1;
    if ((fp1 = fopen(argv[1], "r")) == NULL)
    {
        printf("Error opening file\n");
        exit(0);
    }
    while (fscanf(fp1, "%lf", &tmp) != EOF)
    {
        if (((tmp > llimit) && (tmp < ulimit)) || tmp == llimit || tmp == ulimit)
        {
            count++;
        }
        i++;
    }
    percentage = (double)((count)*100) / i;
    fclose(fp1);
    FILE *fp3;
    fp3 = fopen(argv[3], "w");
    fprintf(fp3, "%lf", percentage);
    fclose(fp3);
    return 0;
}