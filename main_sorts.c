#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sorts.h"

const int maxlen = 1000;

int main(int argc, char **argv)
{
    if (argc != 3)
    {
        printf("Incorrect number of arguments\n");
        return 0;
    }
    else
    {
        int i;
        int numofstr = 0;
        int buff = 0;
        int method = 0;
        char *inputname = malloc(maxlen);
        FILE *filein;

        numofstr = atoi(argv[1]);
        printf("Amount of lines: %d\n", numofstr);

        inputname = argv[2];
        printf("Name of file: %s\n\n", inputname);

        filein = fopen(inputname, "r");

        char **strarr = malloc(numofstr * sizeof(char*));

        for (i = 0; i < numofstr; i++)
        {
            strarr[i] = malloc((maxlen) * sizeof(char));
        }

        for (i = 0; i < numofstr; i++)
        {
            if (feof(filein))
            {
                break;
            }
            fgets(strarr[i], maxlen, filein);
            char *pos;
            if ((pos = strchr(strarr[i], '\n')) != NULL)
            {
                *pos = '\0';
            }
            buff++;
        }

        if (numofstr > buff)
        {
            numofstr = buff;
        }

        fclose(filein);

        printf("Choose the method of sorting:\n1 for Bubble Sort\n2 for Merge Sort\n3 for Insertion Sort\n4 for Quick Sort\n");
        scanf("%d", &method);

        switch(method)
        {
        case 1:
            {
                printf("You've chosen Bubble Sort\n\n");
                sort_bubble(strarr, numofstr);
                break;
            }
        case 2:
            {
                printf("You've chosen Merge Sort\n\n");
                sort_merge(strarr, 0, numofstr - 1);
                break;
            }
        case 3:
            {
                printf("You've chosen Insertion Sort\n\n");
                sort_insertion(strarr, numofstr);
                break;
            }
        case 4:
            {
                printf("You've chosen Quick Sort\n\n");
                sort_quick(strarr, 0, numofstr - 1);
                break;
            }
        default:
            {
                printf("Incorrect input of method\n");
                break;
            }
            break;
        }

        if ((method >= 1) && (method <= 4))
        {
            for (i = 0; i < numofstr; i++)
            {
                printf("%d. ", i + 1);
                fputs(strarr[i], stdout);
                fputs("\n", stdout);
            }
        }

        free(strarr);
        return 0;
    }
}