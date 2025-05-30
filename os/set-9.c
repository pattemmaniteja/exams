#include <stdio.h>
#define MAX 25

void main()
{
    int frag[MAX], b[MAX], f[MAX], i, j, nb, nf, temp, lowest;
    static int bf[MAX], ff[MAX];

    printf("\nEnter the number of blocks: ");
    scanf("%d", &nb);
    printf("\nEnter the number of files: ");
    scanf("%d", &nf);

    printf("\nEnter the size of the blocks:\n");
    for (i = 1; i <= nb; i++)
    {
        printf("Block %d: ", i);
        scanf("%d", &b[i]);
    }

    printf("\nEnter the size of the files:\n");
    for (i = 1; i <= nf; i++)
    {
        printf("File %d: ", i);
        scanf("%d", &f[i]);
    }

    for (i = 1; i <= nf; i++)
    {
        lowest = 10000; // reset for each file
        for (j = 1; j <= nb; j++)
        {
            if (bf[j] != 1)
            { // if block is free
                temp = b[j] - f[i];
                if (temp >= 0 && temp < lowest)
                { // best fit condition
                    ff[i] = j;
                    lowest = temp;
                }
            }
        }

        frag[i] = lowest;

        if (lowest != 10000) // if block found
            bf[ff[i]] = 1;
        else
            ff[i] = -1; // no block found
    }

    printf("\nFile No\tFile Size\tBlock No\tBlock Size\tFragment\n");
    for (i = 1; i <= nf; i++)
    {
        if (ff[i] != -1)
            printf("%d\t%d\t\t%d\t\t%d\t\t%d\n", i, f[i], ff[i], b[ff[i]], frag[i]);
        else
            printf("%d\t%d\t\tNot Allocated\n", i, f[i]);
    }
}