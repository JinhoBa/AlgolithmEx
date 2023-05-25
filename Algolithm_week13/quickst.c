#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void quick_sort(int a[], int left, int right);

void main() {
	int list[] = { 12,17,25, 33,48,52,86,37,100,70 };
	int i, n;
	n = sizeof(list) / sizeof(int);
	quick_sort(list, 0 ,n-1);
	printf("list\n");
	for (i = 0; i < n; i++) {
		printf("%d ", list[i]);
	}
}

void quick_sort(int a[], int left, int right) {
	int pivot, i, j, tmp;
	if (left<right) {
		i = left;
		j = right + 1;
		pivot = a[left];
		while (i < j) {
			do
				i++;
			while ((a[i] < pivot) && (i < right));
			do
				j--;
			while ((a[j] > pivot) && (i > left));
			if (i < j) {
				tmp = a[i];
				a[i] = a[j];
				a[j] = tmp;
			}
		}
		if (j != left) {
			tmp = a[j];
			a[j] = a[left];
			a[left] = tmp;
		}
		quick_sort(a, left, j - 1);
		quick_sort(a, j + 1, right);
	}
}
