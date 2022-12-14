#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    FILE *fp1;
    char str[1000];
    int freq[1000] = {0};
    for (int i = 2; i < argc; i++)
    {
        fp1 = fopen(argv[i], "r");
        while (fscanf(fp1, "%s", str) != EOF)
        {
            for (int i = 0; str[i] != '\0'; i++)
            {
                freq[str[i]]++;
            }
        }
        fclose(fp1);
    }

    FILE *fp2;
    fp2 = fopen(argv[1], "w");
    for (int i = 0; i < 1000; i++)
    {
        if ((i >= 48 && i <= 57) || (i >= 65 && i <= 90) || (i >= 97 && i <= 122))
        {
            fprintf(fp2, "%c:%d\n", i, freq[i]);
        }
    }
    fclose(fp2);
    return 0;
}