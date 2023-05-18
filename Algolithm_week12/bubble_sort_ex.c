#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void bubble(int a[], int n);
void main() {
    int list[] = { 12,17,25, 33,48,52,86,37,100,70 };
    int i, n;
    n = sizeof(list) / sizeof(int);
    bubble(list, n);
    printf("list");
    for ( i = 0; i < n; i++){
        printf("%d ", list[i]);
    }
}

void bubble(int a[], int n)  //개선된 버블정렬
{
    int i = n - 1, j, tmp, flag = 1;

    while (flag && i != 0) {
        flag = 0;
        for (j = 0; j <= i - 1; j++) {
            if (a[j] > a[j + 1]) {      
                flag = 1;
                tmp = a[j]; a[j] = a[j + 1]; a[j + 1] = tmp;
            } //if
        } //for
        i--;
    }
    printf("i = %d :: flag = %d\n", i, flag);   
}