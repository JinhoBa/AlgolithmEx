#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define NUMSTRING 10

void insertion_string(char a[][10], int n);
void main()
{
    char list[NUMSTRING][10];
    int i, n;

    printf("The number of strings to be sorted : ");
    scanf("%d", &n);
    printf("Input %d strings : \n", n);
    for (i = 0; i < n; i++)
        scanf("%s", list[i]);
    insertion_string(list, n);
    printf("Á¤·ÄµÈ µ¥ÀÌÅÍ ¸®½ºÆ®: \n");
    for (i = 0; i < n; i++)
        printf("%s\n", list[i]);
}
void insertion_string(int a[][10], int n) {
    int i, j;
    char idata[10];
    for (i = 1; i < n; i++) {
        strcpy(idata, a[i]);
        j = i - 1;
        while (j >= 0 && strcmp(a[j], idata) > 0) {
            strcpy(a[j + 1], a[j]);
            j--;
        }
        strcpy(a[j + 1], idata);
    }
}
