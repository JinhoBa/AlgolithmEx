#define MAX_SIZE 100
#include <stdio.h>
void merge_sort(int list[], int left, int right);
void merge(int list[], int left, int mid, int right);
void print_list(int* list, int n, char* mesg);

main()
{
    int list[] = { 32, 15, 20, 55, 40, 10, 27, 30, 70, 60, 50, 90, 66, 33 };
    int n;
    n = sizeof(list) / sizeof(int);

    print_list(list, n, "데이터 리스트  : \n");
    merge_sort(list, 0, n - 1);
    print_list(list, n, "합병된 데이터 리스트 : \n");
}

void print_list(int* list, int n, char* mesg)
{
    int i;
    printf(mesg);
    for (i = 0; i < n; i++) {
        printf("%d   ", list[i]);
        if ((i % 7) == 6) printf("\n");
    }
    printf("\n\n");
}
void merge_sort(int list[], int left, int right) {
    int mid;
    if (left < right) {
        mid = (left + right) / 2;
        merge_sort(list, left, mid);
        merge_sort(list, mid+1, right);
        merge(list, left, mid,right);
    }
}
void merge(int a[], int left, int mid, int right) {
    int i = left, j = mid + 1, k = left, h;
    int tlist[MAX_SIZE];
    while (i<= mid && j<=right) {
        if (a[i] < a[j])
            tlist[k++] = a[i++];
        else
            tlist[k++] = a[j++];

    }
    if (i >mid)
        while (j <= right) tlist[k++] = a[j++];
    else
        while(i<=mid) tlist[k++] = a[i++];
        for (h = left; h <= right; h++)
            a[h] = tlist[h];
}
