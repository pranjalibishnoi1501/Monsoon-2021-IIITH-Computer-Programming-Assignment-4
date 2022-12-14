#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    char arr[20000][50];
    int a = 0;

    FILE *fp1;
    for (int i = 2; i < argc; i++)
    {
        fp1 = fopen(argv[i], "r");
        while (fscanf(fp1, "%s", arr[a]) != EOF)
        {
            a++;
        }
    }
    fclose(fp1);

    // Bubble Sort arr
    char temp[50];
    for (int i = 0; i < a - 1; i++)
    {
        for (int j = 0; j < a - i - 1; j++)
        {
            if (strcmp(arr[j], arr[j + 1]) > 0)
            {
                strcpy(temp, arr[j]);
                strcpy(arr[j], arr[j + 1]);
                strcpy(arr[j + 1], temp);
            }
        }
    }

    FILE *fp = fopen(argv[1], "w");
    for (int i = 0; i < a;)
    {
        int cur = i;
        while (strcmp(arr[i], arr[cur]) == 0)
        {
            cur++;
            if (cur == a)
                break;
        }
        fprintf(fp, "%s:%d\n", arr[i], cur - i);
        i = cur;
    }
    fclose(fp);
    return 0;
}