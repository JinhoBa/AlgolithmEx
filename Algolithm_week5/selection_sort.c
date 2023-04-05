#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
void selec_sort(int list[], int n);
void selec_sortd(int list[], int n);
int find_kthdata(int list[], int n, int k);
void main() {
	int list[6] = { 35,95,25,70,15,58 };
	int k;
	/*selec_sort(list, 6);
	for (int i = 0; i < 6; i++){
		printf("%d ", list[i]);
	}
	printf("\n");
	selec_sortd(list, 6);
	for (int i = 0; i < 6; i++) {
		printf("%d ", list[i]);
	}*/
	printf("몇 번째 데이터를 선택할까요 ? ");
	scanf("%d", &k);
	printf("k번째 데이터 : %d", find_kthdata(list, 6, k));

}
void selec_sort(int list[], int n) {
	int s, index, j, temp;
	for ( s = 0; s < n-1; s++){
		index = s;
		for ( j = s + 1; j < n; j++){
			if (list[j] < list[index])
				index = j;
		}
		temp = list[s];
		list[s] = list[index];
		list[index] = temp;
	}
}
void selec_sortd(int list[], int n) {
	int s, index, j, temp;
	for (s = 0; s < n - 1; s++) {
		index = s;
		for (j = s + 1; j < n; j++) {
			if (list[j] > list[index])
				index = j;
		}
		temp = list[s];
		list[s] = list[index];
		list[index] = temp;
	}
}
int find_kthdata(int list[], int n,int k) {
	int s, index, j, temp;
	for (s = 0; s < n - 1; s++) {
		index = s;
		for (j = s + 1; j < n; j++) {
			if (list[j] < list[index])
				index = j;
		}
		temp = list[s];
		list[s] = list[index];
		list[index] = temp;
		if(s== k-1)break;
	}
	return list[s]; //list[k-1]

}