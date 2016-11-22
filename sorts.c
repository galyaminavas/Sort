#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sorts.h"

const int maxl = 1000;

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
            if (strcmp(arr[j], arr[j - 1]) < 0)
            {
                swap(&arr[j], &arr[j - 1]);
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
        left_buff[i] = malloc((maxl) * sizeof(char));
        left_buff[i] = arr[left + i];
    }

    for (j = 0; j < n2; j++)
    {
        right_buff[j] = malloc((maxl) * sizeof(char));
        right_buff[j] = arr[middle + 1 + j];
    }

    i = 0;
    j = 0;
    k = left;

    while (i < n1 && j < n2)
    {
        if (strcmp(left_buff[i], right_buff[j]) < 0)
        {
            arr[k] = left_buff[i];
            i++;
        }
        else
        {
            arr[k] = right_buff[j];
            j++;
        }
        k++;
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
    free(left_buff);
    free(right_buff);
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

int partition(char **arr, int left, int right)
{
    int j = left;
    int i;
    for (i = left + 1; i <= right; i++)
    {
        if (strcmp(arr[i], arr[left]) < 0)
        {
            swap(&arr[i], &arr[j + 1]);
            j++;
        }
    }
    swap(&arr[j], &arr[left]);
    return j;
}

void quicksort(char **arr, int left, int right)
{
    if (left < right)
    {
        int m = partition(arr, left, right);
        quicksort(arr, left, m - 1);
        quicksort(arr, m + 1, right);
    }
}
