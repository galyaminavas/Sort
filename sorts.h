#pragma once

void swap(char **str1, char **str2);
int partition(char **arr, int left, int right);
void sort_quick(char **arr, int left, int right);
void merge(char **arr, int left, int middle, int right);
void sort_merge(char **arr, int left, int right);
void sort_bubble(char **arr, int num);
void sort_insertion(char **arr, int num);
int count_strings (FILE *f);
void count_strings_length(FILE *f, int *strings_len);
void read_strings(FILE *f, char **strings, int number_of_lines, int *strings_len);
