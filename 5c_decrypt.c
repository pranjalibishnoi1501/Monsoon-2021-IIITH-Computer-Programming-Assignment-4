#include <stdio.h>
#include <string.h>

const int N = 1e6;

int key[1000000];

int main(int argc, char *argv[])
{
    FILE *fp1;
    fp1 = fopen(argv[1], "r"); // reading the key generated in key.txt file using the encryption program
    for (int i = 0; i < 127; i++)
    {
        fscanf(fp1, "%1d", &key[i]);
    }
    fclose(fp1);

    for (int i = 127; i < N; i++)
    {
        key[i] = key[i - 1] ^ key[i - 127];
    }

    FILE *fp2;
    fp2 = fopen(argv[2], "r"); // reading the file which contains the encrypted string generated using encryption program

    int bit[N], n = 0;
    while ((fscanf(fp2, "%1d", &bit[n])) != EOF)
    {
        bit[n] = bit[n] ^ key[n + 127];
        n++;
    }
    fclose(fp2);

    FILE *fp3;
    fp3 = fopen(argv[3], "w"); //file where the “decrypted string” needs to be stored
    int i = 0;
    while (i < n)
    {
        int k = 0;
        for (int j = 0; j < 8; j++)
        {
            k = k + ((1 << (7 - j)) * bit[i + j]);
        }
        fprintf(fp3, "%c", (char)k);
        i = i + 8;
    }
    fclose(fp3);
    return 0;
}
