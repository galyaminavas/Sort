#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sorts.h"

int main(int argc, char **argv)
{
    if (argc < 3)
    {
        printf("Incorrect number of arguments\n");
        return -1;
    }
    
    int i;
    int input_num_of_lines = atoi(argv[1]);
    char *filename = argv[2];
    FILE *fileinp;
    if (fopen(filename, "r") != NULL)
    {
        fileinp = fopen(filename, "r");
    }
    else
    {
        printf("Incorrect name of file\n");
        return -1;
    }
    
    printf("Number of lines: %d\n", input_num_of_lines);
    
    printf("Name of file: %s\n\n", filename);
    
    int number_of_lines = count_strings(fileinp);
    rewind(fileinp);
    if (number_of_lines < input_num_of_lines)
    {
        input_num_of_lines = number_of_lines;
    }
    
    int *strings_len = (int *)malloc(sizeof(char *) * number_of_lines);
    count_strings_length(fileinp, strings_len);
    rewind(fileinp);
    
    char **strings = (char **)malloc(sizeof(char *) * number_of_lines);
    read_strings(fileinp, strings, number_of_lines, strings_len);
    
    int method = 0;
    printf("Choose the method of sorting:\n1 for Bubble Sort\n2 for Merge Sort\n3 for Insertion Sort\n4 for Quick Sort\n");
    scanf("%d", &method);
    
    switch(method)
    {
    case 1:
        {
            printf("You've chosen Bubble Sort\n\n");
            sort_bubble(strings, input_num_of_lines);
            break;
        }
    case 2:
        {
            printf("You've chosen Merge Sort\n\n");
            sort_merge(strings, 0, input_num_of_lines - 1);
            break;
        }
    case 3:
        {
            printf("You've chosen Insertion Sort\n\n");
            sort_insertion(strings, input_num_of_lines);
            break;
        }
    case 4:
        {
            printf("You've chosen Quick Sort\n\n");
            sort_quick(strings, 0, input_num_of_lines - 1);
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
        for (i = 0; i < input_num_of_lines; i++)
        {
            printf("%d. ", i + 1);
            puts(strings[i]);
        }
    }
    
    for (i = 0; i < number_of_lines; i++)
    {
        free(strings[i]);
    }
    free(strings);
    free(strings_len);
    
    fclose(fileinp);
    
    return 0;
    
}