#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

const int N = 1e5 + 2;

int key[100002];

int main(int argc, char *argv[])
{
    srand(time(NULL));
    FILE *fp1;
    fp1 = fopen(argv[2], "w");
    for (int i = 0; i < 127; i++) //key generated randomly by this program, this file should contain exactly 127 characters, each of them being either 0 or 1.
    {
        int random = rand() % 2;
        fprintf(fp1, "%d", random);
        key[i] = random;
    }
    fclose(fp1);

    for (int i = 127; i < N; i++)
    {
        key[i] = (key[i - 1] ^ key[i - 127]);
    }

    FILE *fp2, *fp3;
    fp2 = fopen(argv[1], "r"); //file which will contain the string to be encrypted
    fp3 = fopen(argv[3], "w"); //file where the “encrypted string” needs to be stored

    char c;
    int k, i = 0;
    while (fscanf(fp2, "%c", &c) != EOF)
    {
        k = c;
        int j = 7;
        while (j >= 0)
        {
            int encstr = ((k & (1 << j)) > 0);
            encstr = encstr ^ key[i * 8 + 7 - j + 127];
            fprintf(fp3, "%d", encstr);
            j--;
        }
        i++;
    }

    fclose(fp2);
    fclose(fp3);

    return 0;
}