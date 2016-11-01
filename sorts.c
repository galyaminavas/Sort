#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(char **s1, char **s2)
{
char *s;
s = *s1;
*s1 = *s2;
*s2 = s;
}

void bubblesrot(char **arr, int n)
{
    int i;
    int j;
    for (i = 0; i < n - 1; i++)
    {
        for (j = n - 1; j > i; j--)
        {
            if (0 < strcmp(arr[j - 1], arr[j]))
            {
                swap(&arr[j - 1], &arr[j]);
            }
        }
    }
}

void insertsort(char **arr, int n)
{
    int i;
    int j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < i; j++)
        {
            if (0 > strcmp(arr[i], arr[j]))
            {
                swap(&arr[i], &arr[j]);
            }
        }
    }
}

void quicksort (char **arr, int first, int last)
{
    int i = first;
    int j = last;
    char *p = arr[(first+last) / 2];
    if (i <= j)
    {
        while (strcmp(arr[i], p) < 0)
        {
            i++;
        }
        while (strcmp(arr[j], p) > 0)
        {
            j--;
        }
        if (i <= j)
        {
            if (strcmp(arr[i], arr[j]) > 0)
            {
                 swap(&arr[i], &arr[j]);
            }
            i++;
            j--;
        }
    }
    if (i < last)
    {
        quicksort(arr, i, last);
    }
    if (first < j)
    {
        quicksort(arr, first, j);
    }

}
const int maxlen = 1000;

/*int main()
{

char *s1 = malloc(n * sizeof(char));
char *s2 = malloc(n * sizeof(char));

fgets(s1, n, stdin);
fgets(s2, n, stdin);

swap(&s1, &s2);

fputs(s1, stdout);
fputs(s2, stdout);


return 0;
}*/

int main()
{
    int n;
    int i;
    int numofstr = 0;

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    fscanf(stdin, "%d\n", &n);
    char **strarr = malloc(n * sizeof(char*));
    for (i = 0; i < n; i++)
    {
        strarr[i] = malloc((maxlen) * sizeof(char));
    }

    for (i = 0; i < n; i++)
    {
        if (feof(stdin))
        {
            break;
        }
        fgets(strarr[i], maxlen, stdin);
        char *pos;
        if ((pos = strchr(strarr[i], '\n')) != NULL)
        {
            *pos = '\0';
        }
        numofstr++;

    }
    //bubblesrot(strarr, numofstr);
    //insertsort(strarr, numofstr);
    quicksort(strarr, 0, numofstr - 1);

    for (i = 0; i < numofstr; i++)
    {
        fputs(strarr[i], stdout);
        fputs("\n", stdout);
    }

fclose(stdin);
fclose(stdout);
return 0;
}
