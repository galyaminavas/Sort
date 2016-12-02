#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sorts.h"

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
    int left_amount = middle - left + 1;
    int right_amount = right - middle;

    char **left_buff = (char **)malloc(left_amount * sizeof(char*));
    char **right_buff = (char **)malloc(right_amount * sizeof(char*));

    for (i = 0; i < left_amount; i++)
    {
        left_buff[i] = arr[left + i];
    }

    for (j = 0; j < right_amount; j++)
    {
        right_buff[j] = arr[middle + 1 + j];
    }

    i = 0;
    j = 0;
    k = left;

    while (i < left_amount && j < right_amount)
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
    while (i < left_amount)
    {
        arr[k] = left_buff[i];
        i++;
        k++;
    }
    while (j < right_amount)
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

int count_strings (FILE *f)
{
    int current_string = 0;
    int current_symbol = fgetc(f);
    while (current_symbol != EOF)
    {
        if (current_symbol == '\n')
         {
            current_string++;
         }
         current_symbol = fgetc (f);
    }
    return current_string;
}

void count_strings_length(FILE *f, int *strings_len)
{
    int current_symbol = fgetc(f);
    int current_string = 0;
    int current_string_len = 0;
    while (current_symbol != EOF)
    {
        if (current_symbol == '\n')
         {
            strings_len[current_string] = current_string_len;
            current_string++;
            current_string_len = 0;
         }
         else
         {
             current_string_len++;
         }
         current_symbol = fgetc (f);
    }
}

void read_strings(FILE *f, char **strings, int number_of_lines, int *strings_len)
{
    int i;
    for (i = 0; i < number_of_lines; i++)
    {
        strings[i] = (char *)malloc(sizeof(char) * (strings_len[i] + 1)); // +1 to store '\0' symbol
        for (int j = 0; j < strings_len[i]; j++)
        {
            strings[i][j] = fgetc(f);
        }
        fgetc(f); // \n
        strings[i][strings_len[i]] = '\0';
    }
}
