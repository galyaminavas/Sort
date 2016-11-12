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

void bubblesort(char **arr, int n)
{
    int i;
    int j;
    for (i = 0; i < n - 1; i++)
    {
        for (j = n - 1; j > i; j--)
        {
            if (strcmp(arr[j - 1], arr[j]) > 0)
            {
                swap(&arr[j - 1], &arr[j]);
            }
        }
    }
}
void merge(char **arr, int left, int middle, int right)
{
    int i;
    int j;
    int k;
    int n1 = middle - left + 1;
    int n2 = right - middle;

    char **left_buff = malloc(n1 * sizeof(char*));
    char **right_buff = malloc(n2 * sizeof(char*));

    for (i = 0; i < n1; i++)
    {
        left_buff[i] = malloc((1000) * sizeof(char));
        left_buff[i] = arr[left + i];
    }

    for (j = 0; j < n2; j++)
    {
        right_buff[j] = malloc((1000) * sizeof(char));
        right_buff[j] = arr[middle + 1 + j];
    }

    i = 0;
    j = 0;
    k = left;
    while (i < n1 && j < n2)
    {
        if (strcmp(right_buff[j], left_buff[i]) > 0)
        {
            arr[k] = left_buff[i];
            i++;
            k++;
        }
        else
        {
            arr[k] = right_buff[j];
            j++;
            k++;
        }
    }
    while (i < n1)
    {
        arr[k] = left_buff[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = right_buff[j];
        j++;
        k++;
    }
}

void mergesort(char **arr, int left, int right)
{
    if (left < right)
    {
        int middle = left + (right - left) / 2;
        mergesort(arr, left, middle);
        mergesort(arr, middle + 1, right);

        merge(arr, left, middle, right);
    }
}

void insertionsort(char **arr, int n)
{
    int i;
    int j;
    for (i = 1; i < n; i++)
    {
        for (j = i; (j > 0) && (strcmp(arr[j], arr[j - 1]) < 0); j--)
        {
                swap(&arr[j - 1], &arr[j]);
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

    mergesort(strarr, 0, numofstr - 1);

    for (i = 0; i < numofstr; i++)
    {
        fputs(strarr[i], stdout);
        fputs("\n", stdout);
    }

fclose(stdin);
fclose(stdout);
return 0;
}
