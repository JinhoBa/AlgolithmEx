#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int binary_search(int a[], int n, int key);
void selection_sort(int a[], int n);
void main() {
	int list[] = { 82, 120, 30, 40, 5, 90, 77, 25, 45, 100, 10, 79, 31, 55, 87 };
	int n = sizeof(list) / sizeof(int);
	int key, i;
	char sorted;
	
	printf("Is your data sorted (y / n)?");
	scanf("%c", &sorted);
	if(sorted == 'n')
		selection_sort(list, n);
	printf("list = ");
	for (int j = 0; j < n; j++){
		printf("%d ", list[j]);
	}

	printf("\n Enter key : ");
	scanf("%d", &key);

	if (i = binary_search(list, n, key) != -1)
		printf("%d exist at [%d]\n", key, i + 1);
	else
		printf("%d does noet exist\n", key);
}
int binary_search(int a[], int n, int key) {
	int mid;
	int left = 0, right = n - 1;
	while (left <= right) {
		mid = (left + right) / 2;
		if (key > a[mid])
			left = mid + 1;
		else if (key < a[mid])
			right = mid - 1;
		else
			return mid;
	}
	return -1;
	/* 재귀
	int mid;
	if(left <= right){
		mid = (left +right) /2;
		if(key >a[mid]) return binsearch (a, mid+1, right, key);
		else if( key< a[mid]) return bins(a, left, mid-1, key);
		else return mid;
	}
	return -1;
	*/
}
void selection_sort(int a[], int n) {
	int i, index, j, temp;
	for ( i = 0; i < n-1; i++){
		index = i;
		for ( j = i+1; j < n; j++) {
			if (a[j] < a[index])
				index = j;
		}
		temp = a[i];
		a[i] = a[index];
		a[index] = temp;
	}
}
//시간 복잡도
//O(1) < O(log n) < O(n) < O(n* log n) < O(n²) < O(n³)  < O(2n) < O(n!)