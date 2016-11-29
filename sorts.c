#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sorts.h"

const int maxl = 1000;

void swap(char **str1, char **str2)
{
    char *str;
    str = *str1;
    *str1 = *str2;
    *str2 = str;
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

void sort_quick(char **arr, int left, int right)
{
    if (left < right)
    {
        int m = partition(arr, left, right);
        sort_quick(arr, left, m - 1);
        sort_quick(arr, m + 1, right);
    }
}

void merge(char **arr, int left, int middle, int right)
{
    int i;
    int j;
    int k;
    int leftamount = middle - left + 1;
    int rightamount = right - middle;

    char **left_buff = malloc(leftamount * sizeof(char*));
    char **right_buff = malloc(rightamount * sizeof(char*));

    for (i = 0; i < leftamount; i++)
    {
        left_buff[i] = malloc((maxl) * sizeof(char));
        left_buff[i] = arr[left + i];
    }

    for (j = 0; j < rightamount; j++)
    {
        right_buff[j] = malloc((maxl) * sizeof(char));
        right_buff[j] = arr[middle + 1 + j];
    }

    i = 0;
    j = 0;
    k = left;

    while (i < leftamount && j < rightamount)
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
    while (i < leftamount)
    {
        arr[k] = left_buff[i];
        i++;
        k++;
    }
    while (j < rightamount)
    {
        arr[k] = right_buff[j];
        j++;
        k++;
    }
    free(left_buff);
    free(right_buff);
}

void sort_merge(char **arr, int left, int right)
{
    if (left < right)
    {
        int middle = left + (right - left) / 2;
        sort_merge(arr, left, middle);
        sort_merge(arr, middle + 1, right);
        merge(arr, left, middle, right);
    }
}

void sort_bubble(char **arr, int num)
{
    int i;
    int j;
    for (i = 0; i < num - 1; i++)
    {
        for (j = num - 1; j > i; j--)
        {
            if (strcmp(arr[j], arr[j - 1]) < 0)
            {
                swap(&arr[j], &arr[j - 1]);
            }
        }
    }
}

void sort_insertion(char **arr, int num)
{
    int i;
    int j;
    for (i = 1; i < num; i++)
    {
        for (j = i; (j > 0) && (strcmp(arr[j], arr[j - 1]) < 0); j--)
        {
            swap(&arr[j - 1], &arr[j]);
        }
    }
}