#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    FILE *f1 = fopen(argv[1], "r");
    FILE *f2 = fopen(argv[2], "r");
    FILE *f3 = fopen(argv[3], "w");

    if (!f1 || !f2)
    {
        exit(1);
    }

    char n1[16], n2[16];
    int r1 = fscanf(f1, "%s", n1);
    int r2 = fscanf(f2, "%s", n2);
    while (r1 == 1 || r2 == 1)
    {
        if (r1 == 1 && r2 == 1)
        {
            int v = strcmp(n1, n2);
            if (v == 0)
            {
                fprintf(f3, "%s\n", n1);
                fprintf(f3, "%s\n", n2);
                r1 = fscanf(f1, "%s", n1);
                r2 = fscanf(f2, "%s", n2);
            }
            else if (v > 0)
            {
                fprintf(f3, "%s\n", n2);
                r2 = fscanf(f2, "%s", n2);
            }
            else if (v < 0)
            {
                fprintf(f3, "%s\n", n1);
                r1 = fscanf(f1, "%s", n1);
            }
        }
        else if (r1 == 1)
        {
            fprintf(f3, "%s\n", n1);
            r1 = fscanf(f1, "%s", n1);
        }
        else if (r2 == 1)
        {
            fprintf(f3, "%s\n", n2);
            r2 = fscanf(f2, "%s", n2);
        }
    }
    fclose(f1);
    fclose(f2);
    fclose(f3);
    return 0;
}
