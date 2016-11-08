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
            if (strcmp(arr[j - 1], arr[j]) > 0)
            {
                swap(&arr[j - 1], &arr[j]);
            }
        }
    }
}

/*void mergesort(char **arr, char **buff, int left, int right)
{
    if (left == right)
    {
        buff[left] = arr[left];
        return buff;
    }

    int middle = (left + right) / 2;

    char **l_buff = mergesort(arr, buff, left, middle);
    char **r_buff = mergesort(arr, buff, middle + 1, right);

    char **target = *l_buff == *arr ? buff: arr;
    int width = right - left;
    int l_cur = left;
    int r_cur = middle + 1;
    for (int i = left; i <= right; i++)
    {
        if (l_cur <= middle && r_cur <= right)
        {
            if (strcmp(l_buff[l_cur], r_buff[r_cur]) < 0)
            {
                target[i] = l_buff[l_cur];
                l_cur++;
            }
            else
            {
                target[i] = r_buff[r_cur];
                r_cur++;
            }
        }
        else if (l_cur <= middle)
        {
            target[i] = l_buff[l_cur];
            l_cur++;
        }
        else
        {
            target[i] = r_buff[r_cur];
            r_cur++;
        }
    }
    return target;
}*/

void insertsort(char **arr, int n)
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
    char **copy = malloc(n * sizeof(char*));
    for (i = 0; i < n; i++)
    {
        strarr[i] = malloc((maxlen) * sizeof(char));
        copy[i] = malloc((maxlen) * sizeof(char));
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

    //mergesort(strarr, copy, 0, numofstr - 1);
    //bubblesrot(strarr, numofstr);
    insertsort(strarr, numofstr);
    //quicksort(strarr, 0, numofstr - 1);

    for (i = 0; i < numofstr; i++)
    {
        fputs(strarr[i], stdout);
        fputs("\n", stdout);
    }

fclose(stdin);
fclose(stdout);
return 0;
}
