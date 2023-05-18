#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void insertion(int a[], int n);
void main() {
    int list[] = { 12,17,25, 33,48,52,86,37,100,70 };
    int i, n;
    n = sizeof(list) / sizeof(int);
    insertion(list, n);
    printf("list");
    for (i = 0; i < n; i++) {
        printf("%d ", list[i]);
    }
}
void insertion(int a[], int n) {
    int i, j, key;
    for ( i = 0; i < n-1; i++){
        key = a[i];
        j = i - 1;
        while (a[j] > key && j >= 0) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}
