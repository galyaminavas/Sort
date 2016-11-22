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
        int numofstr;
        char *inputname = malloc(maxlen);

        numofstr = atoi(argv[1]);
        printf("The number of lines: %d\n", numofstr);

        inputname = argv[2];
        printf("The name of file: %s\n", inputname);

        freopen(inputname, "r", stdin);

        char **strarr = malloc(numofstr * sizeof(char*));

        for (i = 0; i < numofstr; i++)
        {
            strarr[i] = malloc((maxlen) * sizeof(char));
        }
        for (i = 0; i < numofstr; i++)
        {
            fgets(strarr[i], maxlen, stdin);
            char *pos;
            if ((pos = strchr(strarr[i], '\n')) != NULL)
            {
                *pos = '\0';
            }
        }
        fclose(stdin);
        freopen("CON", "r", stdin);

        int method;
        printf("Choose the method of sorting:\n1 for BubbleSort\n2 for MergeSort\n3 for InsertionSort\n4 for QuickSort\n");
        scanf("%d", &method);

        switch(method)
        {
        case 1:
            {
                bubblesort(strarr, numofstr);
                break;
            }
        case 2:
            {
                mergesort(strarr, 0, numofstr - 1);
                break;
            }
        case 3:
            {
                insertionsort(strarr, numofstr);
                break;
            }
        case 4:
            {
                quicksort(strarr, 0, numofstr - 1);
                break;
            }
        default:
            {
                break;
            }
            break;
        }

        for (i = 0; i < numofstr; i++)
        {
            fputs(strarr[i], stdout);
            fputs("\n", stdout);
        }

        free(strarr);
        return 0;
    }
}
